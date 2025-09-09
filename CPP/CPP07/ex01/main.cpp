/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpipi <tpipi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/20 17:04:08 by tpipi             #+#    #+#             */
/*   Updated: 2025/05/20 17:36:16 by tpipi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "iter.hpp"

void	addInt(int &i)
{
	i++;
}

void	subInt(int &i)
{
	i--;
}

int	printChar(const char &c)
{
	std::cout << c << std::endl;
	return 0;
}

int	main(void)
{
	int			arrayInt[5];
	const char	arrayChar[3] = {'a', 'b', 'c'};

	for (int i = 0; i < 5; i++)
		arrayInt[i] = i;

	::iter(arrayInt, 5, addInt);
	for (int i = 0; i < 5; i++)
		std::cout << arrayInt[i] << " ";
	std::cout << std::endl;
	
	::iter(arrayInt, 5, subInt);
	for (int i = 0; i < 5; i++)
		std::cout << arrayInt[i] << " ";
	std::cout << std::endl;

	::iter(arrayChar, 3, printChar);
}
