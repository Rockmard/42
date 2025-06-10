/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpipi <tpipi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/05 16:25:50 by tpipi             #+#    #+#             */
/*   Updated: 2025/03/05 16:43:05 by tpipi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

Dog::Dog():AAnimal("Dog")
{
	std::cout << "A dog has been summoned" << std::endl;
	this->brain = new Brain();
}

Dog::Dog(const Dog &dog)
{
	std::cout << "A dog has found his brother! They look so happy!" << std::endl;
	this->brain = new Brain();
	*this = dog;
}

Dog &Dog::operator = (const Dog &animal)
{
	if (this != &animal)
	{
		delete this->brain;
		this->brain = new Brain(*animal.brain);
		type = animal.type;
	}
	return *this;
}

void	Dog::makeSound(void)	const
{
	std::cout << "Bark bark! - says the dog" << std::endl;
}

Dog::~Dog()
{
	delete this->brain;
	std::cout << "A dog went to paradise..." << std::endl;
}