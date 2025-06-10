/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpipi <tpipi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/05 16:25:47 by tpipi             #+#    #+#             */
/*   Updated: 2025/03/05 16:38:13 by tpipi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

Cat::Cat():Animal("Cat")
{
	std::cout << "A cat has been found in a dumpster, who does that ?" << std::endl;
	this->brain = new Brain();
}

Cat::Cat(Brain &brain):Animal("Cat")
{
	std::cout << "A cat has been found in a dumpster, who does that ?" << std::endl;
	this->brain = new Brain(brain);
}

Cat::Cat(const Cat &cat)
{
	std::cout << "A cat has met its worst enemy...another cat, prepare not to sleep..." << std::endl;
	this->brain = new Brain();
	*this = cat;
}

Cat &Cat::operator = (const Cat &animal)
{
	if (this != &animal)
	{
		delete this->brain;
		this->brain = new Brain(*animal.brain);
		type = animal.type;
	}
	return *this;
}

void	Cat::getBrain(void)	const
{
	// affiche les 5 premieres idees
	for (size_t i = 0; i < 5; i++)
		std::cout << this->brain->getIdeas()[i] << std::endl;
}

void	Cat::makeSound(void)	const
{
	std::cout << "Meow meow! - says the cat" << std::endl;
}

Cat::~Cat()
{
	delete this->brain;
	std::cout << "A cat was just run over...how cruel" << std::endl;
}