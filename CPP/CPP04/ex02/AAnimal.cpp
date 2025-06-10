/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AAnimal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpipi <tpipi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/05 16:26:22 by tpipi             #+#    #+#             */
/*   Updated: 2025/02/05 18:44:22 by tpipi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AAnimal.hpp"

AAnimal::AAnimal()
{
	type = "Beast";
	std::cout << "A beast woke up from a long sleep...be careful!" << std::endl;
}

AAnimal::AAnimal(std::string type)
{
	this->type = type;
	std::cout << "A beast woke up from a long sleep...be careful!" << std::endl;
}

AAnimal::AAnimal(const AAnimal &AAnimal)
{
	*this = AAnimal;
	std::cout << "A beast has been cloned!" << std::endl;
}

AAnimal &AAnimal::operator = (const AAnimal &AAnimal)
{
	if (this != &AAnimal)
		type = AAnimal.type;
	return *this;
}

AAnimal::~AAnimal()
{
	std::cout << "The beast ran away in the forest, you wonder why..." << std::endl;
}

void	AAnimal::makeSound(void)	const
{
	std::cout << "...*the beast doesn't make any sound and just look at you deep in your eyes, you feel uncomfortable and leave*..." << std::endl;
}

std::string	AAnimal::getType(void)	const
{
	return type;
}