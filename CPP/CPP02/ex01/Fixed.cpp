/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpipi <tpipi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/04 16:40:20 by tpipi             #+#    #+#             */
/*   Updated: 2025/02/26 19:53:16 by tpipi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"
#include <cmath>
#include <bitset>

Fixed::Fixed(void)
{
	std::cout << "Default constructor called" << std::endl;
	_nbVal = 0;
}

Fixed::Fixed(const Fixed &fixed)
{
	std::cout << "Copy constructor called" << std::endl;
	_nbVal = fixed.getRawBits();
	//*this = fixed;
}

Fixed::Fixed(const int nb)
{
	std::cout << "Int constructor called" << std::endl;
	_nbVal = nb << _nbBits;
}

Fixed::Fixed(const float nb)
{
	std::cout << "Float constructor called" << std::endl;
	_nbVal = roundf(nb * (1 << _nbBits));
}

Fixed &Fixed::operator = (const Fixed &fixed)
{
	std::cout << "Copy assignment operator called" << std::endl;
	if (this != &fixed)
		_nbVal = fixed.getRawBits();
	return *this; 
}

Fixed::~Fixed(void)
{
	std::cout << "Destructor called" << std::endl;
}

int Fixed::getRawBits(void) const
{
	std::cout << "getRawBits member function called" << std::endl;
	return _nbVal;
}

void Fixed::setRawBits(int const raw)
{
	std::cout << "setRawBits member function called" << std::endl;
	_nbVal = raw;
}

float Fixed::toFloat(void) const
{
	return static_cast<float>(_nbVal) / (1 << _nbBits);
}

int Fixed::toInt(void) const
{
	return roundf(toFloat());
}

std::ostream &operator << (std::ostream &stream, const Fixed &fixed)
{
	stream << fixed.toFloat();
	return stream;
}
