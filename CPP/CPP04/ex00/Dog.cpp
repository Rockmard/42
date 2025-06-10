/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpipi <tpipi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/05 16:25:50 by tpipi             #+#    #+#             */
/*   Updated: 2025/02/05 18:42:42 by tpipi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

Dog::Dog():Animal("Dog")
{
	std::cout << "A dog has been summoned" << std::endl;
}

Dog::Dog(const Dog &dog)
{
	*this = dog;
	std::cout << "A dog has found his brother! They look so happy!" << std::endl;
}

Dog &Dog::operator = (const Dog &animal)
{
	if (this != &animal)
		type = animal.type;
	return *this;
}

void	Dog::makeSound(void)	const
{
	std::cout << "Bark bark! - says the dog" << std::endl;
}

Dog::~Dog()
{
	std::cout << "A dog went to paradise..." << std::endl;
}