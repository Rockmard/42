/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpipi <tpipi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/04 16:40:34 by tpipi             #+#    #+#             */
/*   Updated: 2025/02/26 19:53:20 by tpipi            ###   ########.fr       */
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

		int getRawBits(void) const;
		void setRawBits(int const raw);
		float toFloat(void) const;
		int toInt(void) const;
		
		~Fixed(void);
	private:
		int	_nbVal;
		static const int _nbBits = 8;
};

std::ostream	&operator << (std::ostream &stream, const Fixed &fixed);

#endif