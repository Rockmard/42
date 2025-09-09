/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpipi <tpipi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/13 16:04:58 by tpipi             #+#    #+#             */
/*   Updated: 2025/06/10 16:36:13 by tpipi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

ScalarConverter::ScalarConverter(void) {}

ScalarConverter::ScalarConverter(const ScalarConverter &copy)
{
	(void)copy;
}

ScalarConverter &ScalarConverter::operator=(const ScalarConverter &copy)
{
	(void)copy;
	return *this;
}

ScalarConverter::~ScalarConverter(void) {}

static void	printConvertString(std::string c, std::string i, std::string f, std::string d)
{
	std::cout << "char: " << c << std::endl;
	std::cout << "int: " << i << std::endl;
	std::cout << "float: " << f << std::endl;
	std::cout << "double: " << d << std::endl;
}

static void	printConvert(int i, float f, double d, int precision)
{
	if (i >= 32 && i <= 126)
		std::cout << "char: '" << static_cast<char>(i) << "'" << std::endl;
	else
		std::cout << "char: " << ND << std::endl;
	std::cout << "int: " << i << std::endl;
	if (d - i == 0)
	{
		std::cout << std::fixed << std::setprecision(0) << "float: " << f << ".0f" << std::endl;
		std::cout << std::fixed << std::setprecision(0) << "double: " << d << ".0" << std::endl;
	}
	else
	{
		std::cout << std::fixed << std::setprecision(precision) << "float: " << f << "f" << std::endl;
		std::cout << std::fixed << std::setprecision(precision) << "double: " << d << std::endl;
	}
}

static void	printWhenExceptionCaught(const char *what, float f, double d)
{
	std::string stof = "stof";
	std::string stod = "stod";

	std::cout << "char: " << ND << std::endl;
	std::cout << "int: " << IMP << std::endl;
	if (what == stof || what == stod)
		std::cout << "float: " << IMP << std::endl;
	else
		std::cout << std::scientific << std::setprecision(5) << "float: " << f << "f" << std::endl;
	if (what == stod)
		std::cout << "double: " << IMP << std::endl;
	else
		std::cout << std::scientific << std::setprecision(5) << "double: " << d << std::endl;
}

static bool	isSpecial(std::string literal)
{
	std::string specialChar[3] = {
		"-inf",
		"+inf",
		"nan"
	};

	for (int i = 0; i < 3; i++)
	{
		if (specialChar[i] == literal || (specialChar[i] + "f").c_str() == literal)
		{
			printConvertString(IMP, IMP, specialChar[i] + "f", specialChar[i]);
			return true;
		}
	}
	return false;
}

static bool	isSurroundedWithNumbers(std::string str, int index)
{
	if (str[index + 1] && (str[index - 1] >= '0' && str[index - 1] <= '9') && (str[index + 1] >= '0' && str[index + 1] <= '9'))
		return true;
	return false;
}

static int	detectType(std::string literal, int *precision)
{
	/*
	-1 : not a literal
	0 : a character
	1 : an int
	2 : a float
	3 : a double
	*/
	int		i = 0;
	bool	dot = false;
	
	if (literal.length() == 1 && !(literal[i] >= '0' && literal[i] <= '9'))
		return 0;
	if (literal[0] == '-')
		i++;
	while (literal[i])
	{
		if (dot)
			(*precision)++;
		if (literal[i] == '.')
		{
			if (!isSurroundedWithNumbers(literal, i) || dot)
				return -1;
			else if (!dot)
				dot = true;
		}
		else if (literal[i] == 'f')
		{
			(*precision)--;
			if (!literal[i + 1] && dot)
				return 2;
			else
				return -1;
		}
		else if (!(literal[i] >= '0' && literal[i] <= '9'))
			return -1;
		i++;
	}
	if (dot)
		return 3;
	else
		return 1;
}

static int ft_stoi(std::string literal)
{
    long int l = strtol(literal.c_str(), NULL, 10);
    if (errno || l > INT_MAX || l < INT_MIN)
        throw std::overflow_error("stoi");
    return (static_cast<int>(l));
}

static float ft_stof(std::string literal)
{
	double d = strtod(literal.c_str(), NULL);
	if (errno || d > FLT_MAX || d < -FLT_MAX)
		throw std::overflow_error("stof");
	return (static_cast<float>(d));
}

static double ft_stod(std::string literal)
{
    double d = strtod(literal.c_str(), NULL);
    if (errno)
       throw std::overflow_error("stod");
    return (d);
}

void	ScalarConverter::convert(std::string literal)
{
	int type;
	int	i = 0;
	int	precision = 0;
	float f = 0.0f;
	double d = 0.0;

	if (!isSpecial(literal))
	{
		type = detectType(literal, &precision);
		if (type == -1)
			printConvertString(IMP, IMP, IMP, IMP);
		else if (type == 0)
			printConvert(static_cast<int>(literal[0]), static_cast<float>(literal[0]), static_cast<double>(literal[0]), precision);
		else
		{
			try
			{
				d = ft_stod(literal);
				f = ft_stof(literal);
				i = ft_stoi(literal);
				if (type == 1)
					printConvert(i, static_cast<float>(i), static_cast<double>(i), precision);
				else if (type == 2 || type == 3)
					printConvert(i, f, d, precision);
			}
			catch(std::exception &e)
			{
				printWhenExceptionCaught(e.what(), f, d);
			}
		}
	}
}
