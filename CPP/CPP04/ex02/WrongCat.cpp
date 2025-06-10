/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpipi <tpipi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/05 16:25:47 by tpipi             #+#    #+#             */
/*   Updated: 2025/02/05 18:42:40 by tpipi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongCat.hpp"

WrongCat::WrongCat():WrongAnimal("WrongCat")
{
	std::cout << "WrongCat default constructor has been called" << std::endl;
}

WrongCat::WrongCat(const WrongCat &cat)
{
	*this = cat;
	std::cout << "WrongCat copy constructor has been called" << std::endl;
}

WrongCat &WrongCat::operator = (const WrongCat &animal)
{
	if (this != &animal)
		type = animal.type;
	return *this;
}

void	WrongCat::makeSound(void)	const
{
	std::cout << "Me- *cough* meo- *cough* moew moew..." << std::endl;
}

WrongCat::~WrongCat()
{
	std::cout << "WrongCat destructor has been called" << std::endl;
}