/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpipi <tpipi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/05 16:26:22 by tpipi             #+#    #+#             */
/*   Updated: 2025/02/05 18:44:22 by tpipi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"

Animal::Animal()
{
	type = "Beast";
	std::cout << "A beast woke up from a long sleep...be careful!" << std::endl;
}

Animal::Animal(std::string type)
{
	this->type = type;
	std::cout << "A beast woke up from a long sleep...be careful!" << std::endl;
}

Animal::Animal(const Animal &animal)
{
	*this = animal;
	std::cout << "A beast has been cloned!" << std::endl;
}

Animal &Animal::operator = (const Animal &animal)
{
	if (this != &animal)
		type = animal.type;
	return *this;
}

Animal::~Animal()
{
	std::cout << "The beast ran away in the forest, you wonder why..." << std::endl;
}

void	Animal::makeSound(void)	const
{
	std::cout << "...*the beast doesn't make any sound and just look at you deep in your eyes, you feel uncomfortable and leave*..." << std::endl;
}

std::string	Animal::getType(void)	const
{
	return type;
}