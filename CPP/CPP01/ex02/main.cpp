/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpipi <tpipi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/08 20:44:58 by tpipi             #+#    #+#             */
/*   Updated: 2024/11/15 23:43:17 by tpipi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string>
#include <iostream>

int	main(void)
{
	std::string	str = "HI THIS IS BRAIN";
	std::string	*stringPTR = &str;
	std::string	&stringREF = str;

	std::cout << "Memory addresses" << std::endl;
	std::cout << " > The string : " << &str << std::endl;
	std::cout << " > The pointer : " << stringPTR << std::endl;
	std::cout << " > The reference : " << &stringREF << std::endl << std::endl;

	std::cout << "Value" << std::endl;
	std::cout << " > The string : " << str << std::endl;
	std::cout << " > The pointer : " << *stringPTR << std::endl;
	std::cout << " > The reference : " << stringREF << std::endl;
}
