/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpipi <tpipi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/05 20:33:20 by tpipi             #+#    #+#             */
/*   Updated: 2025/03/05 16:22:51 by tpipi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Brain.hpp"
#include <iostream>

Brain::Brain()
{
	for (size_t i = 0; i < sizeof(this->ideas) / sizeof(std::string); i++)
		this->ideas[i] = "...";
	std::cout << "Brain default constructor called" << std::endl;
}

Brain::Brain(std::string ideas[100])
{
	for (size_t i = 0; i < sizeof(this->ideas) / sizeof(std::string); i++)
		this->ideas[i] = ideas[i];
	std::cout << "Brain default constructor called" << std::endl;
}

Brain::Brain(const Brain &brain)
{
	std::cout << "Brain copy constructor called" << std::endl;
	*this = brain;
}

Brain &Brain::operator = (const Brain &brain)
{
	if (this != &brain)
	{
		for (size_t i = 0; i < sizeof(brain.ideas) / sizeof(std::string); i++)
			this->ideas[i] = brain.ideas[i];
	}
	return *this;
}

Brain::~Brain()
{
	std::cout << "Brain destructor called" << std::endl;
}

std::string	*Brain::getIdeas(void)
{
	return this->ideas;
}