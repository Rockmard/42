/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpipi <tpipi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/15 23:58:47 by tpipi             #+#    #+#             */
/*   Updated: 2025/02/19 14:56:52 by tpipi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"
#include <iostream>

Weapon::Weapon(void)
{
	this->_type = "hands";
	std::cout << "Weapon has been created" << std::endl;
}

Weapon::Weapon(std::string type)
{
	this->_type = type;
	std::cout << "Weapon has been created" << std::endl;
}

std::string	Weapon::getType(void)
{
	return (_type);
}

void	Weapon::setType(std::string type)
{
	this->_type = type;
}

Weapon::~Weapon(void)
{
	std::cout << "Weapon has been destroyed" << std::endl;
}
