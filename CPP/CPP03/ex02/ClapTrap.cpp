/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :<<:      :<<:    :<<:   */
/*                                                    <<:<< <<:<<         <<:<<     */
/*   By: tpipi <tpipi@student.42.fr>                <<#<<  <<:<<       <<#<<        */
/*                                                <<#<<#<<#<<#<<#<<   <<#<<           */
/*   Created: 2025/02/05 00:17:36 by tpipi             #<<#    #<<#             */
/*   Updated: 2025/02/05 00:39:55 by tpipi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

ClapTrap::ClapTrap(void)
{
	std::cout << "Calling default constructor of an unknown ClapTrap" << std::endl;
	_name = "ClapTrapper";
	_hitPoint = 10;
	_energyPoint = 10;
	_attackDamage = 0;
}

ClapTrap::ClapTrap(std::string name)
{
	std::cout << "Calling default constructor of ClapTrap " << name << std::endl;
	_name = name;
	_hitPoint = 10;
	_energyPoint = 10;
	_attackDamage = 0;
}

ClapTrap::ClapTrap(const ClapTrap &claptrap)
{
	std::cout << "Calling copy constructor of ClapTrap " << claptrap._name << std::endl;
	*this = claptrap;
}

ClapTrap	&ClapTrap::operator = (const ClapTrap &claptrap)
{
	if (this != &claptrap)
	{
		_name = claptrap._name;
		_hitPoint = claptrap._hitPoint;
		_energyPoint = claptrap._energyPoint;
		_attackDamage = claptrap._attackDamage;
	}
	return (*this);
}

ClapTrap::~ClapTrap(void)
{
	std::cout << "Calling destructor of ClapTrap " << _name << std::endl;
}

void	ClapTrap::attack(const std::string &target)
{
	if (_energyPoint == 0)
		std::cout << "ClapTrap " << _name << " is too exhausted to attack right now! " << target << " will live another day!" << std::endl;
	else if (_hitPoint == 0)
		std::cout << "ClapTrap "  << _name << " has no HP left! " << target << " will live another day!" << std::endl;
	else
	{
		std::cout << "ClapTrap " << _name << " attacks " << target << ", causing " << _attackDamage << " points of damage!" << std::endl;
		_energyPoint--;
	}
}

void	ClapTrap::takeDamage(unsigned int amount)
{
	std::cout << "Oof... ClapTrap " << _name << " took " << amount << " points of damage!" << std::endl;
	if (_hitPoint - amount > _hitPoint)
		_hitPoint = 0;
	else
		_hitPoint -= amount;
}

void	ClapTrap::beRepaired(unsigned int amount)
{
	if (_energyPoint == 0)
		std::cout << "ClapTrap " << _name << " is too exhausted to repair himself right now!" << std::endl;
	else if (_hitPoint == 0)
		std::cout << "ClapTrap "  << _name << " is already dead and can't repair himself!" << std::endl;
	else
	{
		_hitPoint += amount;
		_energyPoint--;
		std::cout << "ClapTrap " << _name << " repaired himself and has now " << _hitPoint << " HP!" << std::endl; 
	}
}

std::string	ClapTrap::getName(void)
{
	return _name;
}

unsigned int			ClapTrap::getHitPoint(void)
{
	return _hitPoint;
}

unsigned int			ClapTrap::getEnergyPoint(void)
{
	return _energyPoint;
}

unsigned int			ClapTrap::getAttackDamage(void)
{
	return _attackDamage;
}