/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpipi <tpipi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/05 15:53:18 by tpipi             #+#    #+#             */
/*   Updated: 2025/02/06 00:40:26 by tpipi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

FragTrap::FragTrap(void):ClapTrap("FragTrapper")
{
	std::cout << "Calling default constructor of an unknown FragTrap" << std::endl;
	_hitPoint = 100;
	_energyPoint = 100;
	_attackDamage = 30;
}

FragTrap::FragTrap(std::string name):ClapTrap(name)
{
	std::cout << "Calling default constructor of FragTrap " << name << std::endl;
	_hitPoint = 100;
	_energyPoint = 100;
	_attackDamage = 30;
}

FragTrap::FragTrap(const FragTrap &fragtrap):ClapTrap(fragtrap)
{
	std::cout << "Calling copy constructor of FragTrap " << _name << std::endl;
}

FragTrap	&FragTrap::operator = (const FragTrap &fragtrap)
{
	if (this != &fragtrap)
	{
		_name = fragtrap._name;
		_hitPoint = fragtrap._hitPoint;
		_energyPoint = fragtrap._energyPoint;
		_attackDamage = fragtrap._attackDamage;
	}
	return (*this);
}

FragTrap::~FragTrap(void)
{
	std::cout << "Calling destructor of FragTrap " << _name << std::endl;
}

void	FragTrap::highFivesGuys(void)
{
	std::cout << "FragTrap " << _name << " wants to high fives with you!";
	if (_hitPoint == 0)
		std::cout << " Even though he's dead...";
	else if (_energyPoint == 0)
		std::cout << " But can't even stand up on his feet...";
	std::cout << std::endl;
}