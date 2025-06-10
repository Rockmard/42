/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpipi <tpipi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/27 17:24:04 by tpipi             #+#    #+#             */
/*   Updated: 2025/01/27 18:42:12 by tpipi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"
#include <iostream>

Harl::Harl()
{
	std::cout << "Harl has been summoned." << std::endl;
}

Harl::~Harl()
{
	std::cout << "Harl says goodbye." << std::endl;
}

void	Harl::debug()
{
	std::cout << "DEBUG : I love having extra bacon for my 7XL-double-cheese-triple-pickle-specialketchup burger. I really do!" << std::endl;
}

void	Harl::info(void)
{
	std::cout << "INFO : I cannot believe adding extra bacon costs more money. You didn't put enough bacon in my burger! If you did, I wouldn't be asking for more!" << std::endl;
}
void	Harl::warning(void)
{
	std::cout << "WARNING : I think I deserve to have some extra bacon for free. I've been coming for years whereas you started working here since last month." << std::endl;
}
void	Harl::error(void)
{
	std::cout << "ERROR : This is unacceptable! I want to speak to the manager now." << std::endl;
}

void	Harl::complain(std::string level)
{
	int	nbfunc = 4;
	int	i = 0;
	void (Harl::*functptr[])(void) = { &Harl::debug, &Harl::info, &Harl::warning, &Harl::error };
	std::string	leveltab[nbfunc] = { "DEBUG", "INFO", "WARNING", "ERROR"};

	for (i = 0; i < nbfunc; i++) {
		if (level.compare(leveltab[i]) == 0) {
			(this->*functptr[i])();
			break ;
		}
	}
	if (i > nbfunc - 1)
		std::cout << "Harl has nothing to say..." << std::endl;
}