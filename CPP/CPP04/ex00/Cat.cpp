/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpipi <tpipi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/05 16:25:47 by tpipi             #+#    #+#             */
/*   Updated: 2025/02/05 18:42:40 by tpipi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

Cat::Cat():Animal("Cat")
{
	std::cout << "A cat has been found in a dumpster, who does that ?" << std::endl;
}

Cat::Cat(const Cat &cat)
{
	*this = cat;
	std::cout << "A cat has met its worst enemy...another cat, prepare not to sleep..." << std::endl;
}

Cat &Cat::operator = (const Cat &animal)
{
	if (this != &animal)
		type = animal.type;
	return *this;
}

void	Cat::makeSound(void)	const
{
	std::cout << "Meow meow! - says the cat" << std::endl;
}

Cat::~Cat()
{
	std::cout << "A cat was just run over...how cruel" << std::endl;
}