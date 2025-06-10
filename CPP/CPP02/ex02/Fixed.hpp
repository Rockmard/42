/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpipi <tpipi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/04 16:40:34 by tpipi             #+#    #+#             */
/*   Updated: 2025/02/26 19:53:24 by tpipi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
# define FIXED_HPP

#include <iostream>

class	Fixed
{
	public:
		Fixed(void);
		Fixed(const Fixed &fixed);
		Fixed(const int nb);
		Fixed(const float nb);
		Fixed &operator = (const Fixed &fixed);
		int operator > (const Fixed &fixed);
		int operator < (const Fixed &fixed);
		int operator >= (const Fixed &fixed);
		int operator <= (const Fixed &fixed);
		int operator == (const Fixed &fixed);
		int operator != (const Fixed &fixed);
		Fixed operator + (const Fixed &fixed);
		Fixed operator - (const Fixed &fixed);
		Fixed operator * (const Fixed &fixed);
		Fixed operator / (const Fixed &fixed);
		Fixed &operator ++ ();
		Fixed &operator -- ();
		Fixed operator ++ (int n);
		Fixed operator -- (int n);

		int getRawBits(void) const;
		void setRawBits(int const raw);
		float toFloat(void) const;
		int toInt(void) const;
		static Fixed min(Fixed &f1, Fixed &f2);
		static Fixed min(const Fixed &f1, const Fixed &f2);
		static Fixed max(Fixed &f1, Fixed &f2);
		static Fixed max(const Fixed &f1, const Fixed &f2);
		
		~Fixed(void);
	private:
		int	_nbVal;
		static const int _nbBits = 8;
};

std::ostream	&operator << (std::ostream &stream, const Fixed &fixed);

#endif