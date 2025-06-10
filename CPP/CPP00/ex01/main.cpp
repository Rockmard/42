/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpipi <tpipi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/10 05:37:01 by tpipi             #+#    #+#             */
/*   Updated: 2024/12/20 01:17:40 by tpipi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"
#include <iostream>

int	main(void)
{
	PhoneBook	phoneBook;
	std::string	tmp;

	while (1)
	{
		std::cout << ">> What do you want to do ? :\n>> ";
		if (!std::getline(std::cin, tmp))
			break ;
		if (tmp == "ADD") {
			if (phoneBook.addContact() == 1)
				std::cout << "(ADD) >> Contact couldn't be added." << std::endl;
		}
		else if (tmp == "SEARCH")
			phoneBook.searchContact();
		else if (tmp == "EXIT")
			break ;
	}
	return (0);
}
