/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongDog.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpipi <tpipi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/05 16:25:50 by tpipi             #+#    #+#             */
/*   Updated: 2025/02/05 19:22:41 by tpipi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongDog.hpp"

WrongDog::WrongDog():WrongAnimal("WrongDog")
{
	std::cout << "WrongDog default constructor has been called" << std::endl;
}

WrongDog::WrongDog(const WrongDog &dog)
{
	*this = dog;
	std::cout << "WrongDog copy constructor has been called" << std::endl;
}

WrongDog &WrongDog::operator = (const WrongDog &animal)
{
	if (this != &animal)
		type = animal.type;
	return *this;
}

void	WrongDog::makeSound(void)	const
{
	std::cout << "Ba- *cough* bar- *cough* bark bark" << std::endl;
}

WrongDog::~WrongDog()
{
	std::cout << "WrongDog destructor has been called" << std::endl;
}