/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpipi <tpipi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/05 01:29:22 by tpipi             #+#    #+#             */
/*   Updated: 2025/02/06 00:39:37 by tpipi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

ScavTrap::ScavTrap(void):ClapTrap("ScavTrapper")
{
	std::cout << "Calling default constructor of an unknown ScavTrap" << std::endl;
	_hitPoint = 100;
	_energyPoint = 50;
	_attackDamage = 20;
}

ScavTrap::ScavTrap(std::string name):ClapTrap(name)
{
	std::cout << "Calling default constructor of ScavTrap " << name << std::endl;
	_hitPoint = 100;
	_energyPoint = 50;
	_attackDamage = 20;
}

ScavTrap::ScavTrap(const ScavTrap &scavtrap):ClapTrap(scavtrap)
{
	std::cout << "Calling copy constructor of ScavTrap " << _name << std::endl;
}

ScavTrap	&ScavTrap::operator = (const ScavTrap &scavtrap)
{
	if (this != &scavtrap)
	{
		_name = scavtrap._name;
		_hitPoint = scavtrap._hitPoint;
		_energyPoint = scavtrap._energyPoint;
		_attackDamage = scavtrap._attackDamage;
	}
	return (*this);
}

ScavTrap::~ScavTrap(void)
{
	std::cout << "Calling destructor of ScavTrap " << _name << std::endl;
}

void	ScavTrap::attack(const std::string &target)
{
	if (_energyPoint == 0)
		std::cout << "ScavTrap " << _name << " is tired and won't attack right now! " << target << ", it's your lucky day!" << std::endl;
	else if (_hitPoint == 0)
		std::cout << "ScavTrap "  << _name << " is dead unfortunately (for him)... " << target << ", it's your lucky day!" << std::endl;
	else
	{
		std::cout << "ScavTrap " << _name << " attacks " << target << ", dealing " << _attackDamage << " damage points!" << std::endl;
		_energyPoint--;
	}
}

void ScavTrap::guardGate(void)
{
	if (_hitPoint == 0)
		std::cout << "ScavTrap " << _name << " is dead and can't gatekeep anymore (society says thanks to whoever killed this guy)!" << std::endl;
	else if (_energyPoint == 0)
		std::cout << "ScavTrap " << _name << " is way too tired for gatekeeper mode right now, call him later!" << std::endl;
	else
		std::cout << "ScavTrap " << _name << " is now in Gate Keeper Mode (it means he's gatekeeping his favorite underground artist because he's kinda edgy)..." << std::endl;
}