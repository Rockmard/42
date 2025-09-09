/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Data.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpipi <tpipi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/15 20:36:02 by tpipi             #+#    #+#             */
/*   Updated: 2025/06/10 16:51:39 by tpipi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Data.hpp"

Data::Data(int val, std::string str) : _val(val), _str(str)
{
	std::cout << "Creating the data..." << std::endl;
}

Data::Data(const Data &copy)
{
	*this = copy;
}

Data &Data::operator=(const Data &copy)
{
	std::cout << "Copying the data from another one..." << std::endl;
	if (this != &copy)
	{
		this->_val = copy._val;
		this->_str = copy._str;
	}
	return *this;
}

std::string	Data::getStr(void)
{
	return (_str);
}

int	Data::getVal(void)
{
	return (_val);
}

Data::~Data(void)
{
	std::cout << "Deleting the data..." << std::endl;
}