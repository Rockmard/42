/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpipi <tpipi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/05 16:26:22 by tpipi             #+#    #+#             */
/*   Updated: 2025/02/05 19:07:13 by tpipi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal()
{
	type = "Fake";
	std::cout << "A fake is lurking in the nature!" << std::endl;
}

WrongAnimal::WrongAnimal(std::string type)
{
	this->type = type;
	std::cout << "A fake is lurking in the nature!" << std::endl;
}

WrongAnimal::WrongAnimal(const WrongAnimal &animal)
{
	*this = animal;
	std::cout << "A fake has multiplied!" << std::endl;
}

WrongAnimal &WrongAnimal::operator = (const WrongAnimal &animal)
{
	if (this != &animal)
		type = animal.type;
	return *this;
}

WrongAnimal::~WrongAnimal()
{
	std::cout << "The fake disappeared, you wonder how..." << std::endl;
}

void	WrongAnimal::makeSound(void)	const
{
	std::cout << "...*help*..." << std::endl;
}

std::string	WrongAnimal::getType(void)	const
{
	return type;
}