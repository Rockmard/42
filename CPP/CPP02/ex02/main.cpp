/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpipi <tpipi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/04 16:40:14 by tpipi             #+#    #+#             */
/*   Updated: 2025/02/26 19:19:45 by tpipi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

int main( void )
{
	Fixed a;
	Fixed const b(Fixed(5.05f) * Fixed(2));

	std::cout << a << std::endl;
	std::cout << ++a << std::endl;
	std::cout << a << std::endl;
	std::cout << a++ << std::endl;
	std::cout << a << std::endl;
	std::cout << b << std::endl;
	std::cout << Fixed::max( a, b ) << std::endl;

	// additional tests
	std::cout << "\nnon subject tests\n" << std::endl;
	std::cout << "3.5 + 3.5 : " << Fixed(3.5f) + Fixed(3.5f) << std::endl;
	std::cout << "3.5 - 2.5 : " << Fixed(3.5f) - Fixed(2.5f) << std::endl;
	std::cout << "2 * 18.2 : " << Fixed(2) * Fixed(18.2f) << std::endl;
	std::cout << "35 / 0 : " << Fixed(35) / Fixed(0) << std::endl;
	std::cout << "74.2 / 12.8 : " << Fixed(74.2f) / Fixed(12.8f) << std::endl;
	std::cout << "74.2 / -12.8 : " << Fixed(74.2f) / Fixed(-12.8f) << std::endl;
	std::cout << std::endl;
	std::cout << "1 > 0.9 : " << (Fixed(1) > Fixed(0.9f)) << std::endl;
	std::cout << "22 >= 34 : " << (Fixed(22) >= Fixed(34)) << std::endl;
	std::cout << "78 < 0.0 : " << (Fixed(78) < Fixed(0.0f)) << std::endl;
	std::cout << "10.2 <= 10.2 : " << (Fixed(10.2f) <= Fixed(10.2f)) << std::endl;
	std::cout << "100 == 300 : " << (Fixed(100) == Fixed(300)) << std::endl;
	std::cout << "100 != 85 : " << (Fixed(100) != Fixed(85)) << std::endl;
	return 0;
}
