/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpipi <tpipi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/04 16:40:34 by tpipi             #+#    #+#             */
/*   Updated: 2025/02/26 19:53:04 by tpipi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
# define FIXED_HPP

class	Fixed
{
	public:
		Fixed(void);
		Fixed(const Fixed &fixed);
		Fixed &operator = (const Fixed &fixed);

		int getRawBits(void) const;
		void setRawBits(int const raw);
		
		~Fixed(void);
	private:
		int	_nbVal;
		static const int _nbBits = 8;
};

#endif