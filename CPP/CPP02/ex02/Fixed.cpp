/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpipi <tpipi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/04 16:40:20 by tpipi             #+#    #+#             */
/*   Updated: 2025/02/26 19:53:34 by tpipi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"
#include <cmath>
#include <bitset>

Fixed::Fixed(void)
{
	_nbVal = 0;
}

Fixed::Fixed(const Fixed &fixed)
{
	_nbVal = fixed.getRawBits();
	//*this = fixed;
}

Fixed::Fixed(const int nb)
{
	_nbVal = nb << _nbBits;
}

Fixed::Fixed(const float nb)
{
	_nbVal = roundf(nb * (1 << _nbBits));
}

Fixed &Fixed::operator = (const Fixed &fixed)
{
	if (this != &fixed)
		_nbVal = fixed.getRawBits();
	return *this; 
}

int Fixed::operator > (const Fixed &fixed) {
	if (_nbVal > fixed.getRawBits())
		return 1;
	return 0;
}

int Fixed::operator < (const Fixed &fixed) {
	if (_nbVal < fixed.getRawBits())
		return 1;
	return 0;
}

int Fixed::operator >= (const Fixed &fixed) {
	if (_nbVal >= fixed.getRawBits())
		return 1;
	return 0;
}

int Fixed::operator <= (const Fixed &fixed) {
	if (_nbVal <= fixed.getRawBits())
		return 1;
	return 0;
}

int Fixed::operator == (const Fixed &fixed) {
	if (_nbVal == fixed.getRawBits())
		return 1;
	return 0;
}

int Fixed::operator != (const Fixed &fixed) {
	if (_nbVal != fixed.getRawBits())
		return 1;
	return 0;
}

Fixed Fixed::operator + (const Fixed &fixed) {
	return (this->toFloat() + fixed.toFloat());
}

Fixed Fixed::operator - (const Fixed &fixed) {
	return (this->toFloat() - fixed.toFloat());
}

Fixed Fixed::operator * (const Fixed &fixed) {
	return (this->toFloat() * fixed.toFloat());
}

Fixed Fixed::operator / (const Fixed &fixed) {
	if (fixed.toFloat() != 0)
		return (this->toFloat() / fixed.toFloat());
	return *this;
}

Fixed &Fixed::operator ++ () {
	_nbVal++;
	return *this;
}

Fixed &Fixed::operator -- () {
	_nbVal--;
	return *this;
}

Fixed Fixed::operator ++ (int n) {
	Fixed	tmp(*this);
	this->_nbVal++;
	return tmp;
}

Fixed Fixed::operator -- (int n) {
	Fixed	tmp(*this);
	this->_nbVal--;
	return tmp;
}

Fixed::~Fixed(void) {}

int Fixed::getRawBits(void) const
{
	return _nbVal;
}

void Fixed::setRawBits(int const raw)
{
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

Fixed Fixed::min(Fixed &f1, Fixed &f2) {
	if (f1.getRawBits() > f2.getRawBits())
		return (f2);
	return (f1);
}

Fixed Fixed::min(const Fixed &f1, const Fixed &f2) {
	if (f1.getRawBits() > f2.getRawBits())
		return (f2);
	return (f1);
}

Fixed Fixed::max(Fixed &f1, Fixed &f2) {
	if (f1.getRawBits() < f2.getRawBits())
		return (f2);
	return (f1);
}

Fixed Fixed::max(const Fixed &f1, const Fixed &f2) {
	if (f1.getRawBits() < f2.getRawBits())
		return (f2);
	return (f1);
}

std::ostream &operator << (std::ostream &stream, const Fixed &fixed)
{
	stream << fixed.toFloat();
	return stream;
}