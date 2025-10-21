/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpipi <tpipi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/10 21:16:30 by tpipi             #+#    #+#             */
/*   Updated: 2025/10/21 12:28:54 by tpipi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

static bool isDateValide(std::string date)
{
	if ((date.find_first_not_of("0123456789") != std::string::npos && (date[4] != '-' || date[7] != '-')) || date.length() > 10)
		return false;

	std::string year = date.substr(0, 4);
	long int	yearInt = strtol(year.c_str(), NULL, 10);
	if (year < "2009")
		return false;

	std::string month = date.substr(date.find_first_of('-') + 1, 2);
	if (month > "12" || month < "01")
		return false;

	std::string day = date.substr(date.find_last_of('-') + 1, 2);
	if (day < "01")
		return false;
	if ((month == "01" || month == "03" || month == "05" || month == "07" || month == "08" || month == "10" || month == "12") && day > "31")
		return false;
	if ((month == "04" || month == "06" || month == "09" || month == "11") && day > "30")
		return false;
	if (month == "02") {
		if (yearInt % 4 == 0 || (yearInt % 100 == 0 && yearInt % 400 == 0)) {
			if (day > "29")
				return false;
		}
		else {
			if (day > "28")
				return false;
		}
	}
	return true;
}

static bool isValueValide(std::string value)
{
	if (value.find_first_not_of("0123456789.") != std::string::npos || value[0] == '.' || value.find_first_of('.') != value.find_last_of('.'))
		return false;
	return true;
}

static bool	isDatabaseLineErroneous(std::string line, std::string *date, std::string *exchangeRate, int nbLine)
{
	if (nbLine == 1) {
		if (line == "date,exchange_rate")
			return false;
		else
			return true;
	}
	if (line.find(',') == std::string::npos)
		return true;
	if (line.find_first_of(',') != line.find_last_of(','))
		return true;
	if (line.find(" ,") != std::string::npos || line.find(", ") != std::string::npos)
		return true;

	*date = line.substr(0, line.find(','));
	if (!isDateValide(*date))
		return true;

	*exchangeRate = line.substr(line.find(',') + 1);
	if (!isValueValide(*exchangeRate))
		return true;
		
	return false;
}

static float	getExchangeRateByDate(std::string date, std::map<std::string, std::string> exchangeRateForDate)
{
	int			i;
	int			closestCount = 0;
	std::string	closestDate = "";

	for (std::map<std::string, std::string>::iterator it = exchangeRateForDate.begin(); it != exchangeRateForDate.end(); it++) {
		if (date == it->first) {
			closestDate = it->first;
			break ;
		}
		
		i = 0;
		while (date[i]) {
			if (date[i] == it->first[i])
				i++;
			else
				break ;
		}
		if (i >= closestCount && (date[i] > it->first[i] || closestDate == "")) {
			closestCount = i;
			closestDate = it->first;
		}
	}
	std::string exchangeRate = exchangeRateForDate.at(closestDate);
    float f = strtof(exchangeRate.c_str(), NULL);
	return f;
}

int ft_bitcoin_exchange(char *input)
{
	std::string                 		line;
	std::string							date;
	std::string							exchangeRate;
	std::fstream                		fin;
	std::fstream                		fcsv;
	std::map<std::string, std::string>	exchangeRateForDate;
	float	 							value;
	float								valueByRate;
	int									nbLine = 1;
		
	fin.open(input, std::ios::in);
	fcsv.open("data.csv", std::ios::in);

	if (!fin.is_open())
		std::cerr << "Error: could not open file." << std::endl;
	else if (!fcsv.is_open())
		std::cerr << "Error: could not open database." << std::endl;
	else {
		while (std::getline(fcsv, line)) {
			
			if (isDatabaseLineErroneous(line, &date, &exchangeRate, nbLine)) {
				std::cerr << "Error: database is erroneous. => " << line << std::endl;
				fin.close();
				fcsv.close();
				return 1;
			}
			
			if (exchangeRateForDate.find(date) != exchangeRateForDate.end()) {
				std::cerr << "Error: database has a duplicate. => " << date << std::endl;
				fin.close();
				fcsv.close();
				return 1;
			}
			
			exchangeRateForDate.insert(std::pair<std::string, std::string>(date, exchangeRate));
			nbLine++;
		}

		nbLine = 0;
		while (std::getline(fin, line)) {
			if (line.find(" | ") == std::string::npos || line.find_first_of('|') != line.find_last_of('|'))
				std::cerr << "Error: bad input => " << line << std::endl;
			else {
			
				nbLine++;
				date = line.substr(0, line.find(" | "));
				exchangeRate = line.substr(line.find(" | ") + 3);
				value = strtof(exchangeRate.c_str(), NULL);

				if (line == "date | value" && nbLine == 1)
					continue ;
				else if (errno || value < 0 || value > 1000 || !isDateValide(date) || !isValueValide(exchangeRate)) {
					if (value < 0)
						std::cerr << "Error: not a positive number." << std::endl;
					else if (value > 1000)
						std::cerr << "Error: too large a number." << std::endl;
					else
						std::cerr << "Error: bad input => " << line << std::endl;
				}
				else {
					valueByRate = getExchangeRateByDate(date, exchangeRateForDate) * value;
					std::cout << date << " => " << value << " = " << valueByRate << std::endl;
				}
			}
		}
	}

	fin.close();
	fcsv.close();
	
	return 0;
}