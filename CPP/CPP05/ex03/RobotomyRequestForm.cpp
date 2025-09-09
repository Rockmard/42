/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpipi <tpipi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/13 12:29:45 by tpipi             #+#    #+#             */
/*   Updated: 2025/05/13 14:05:43 by tpipi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm(std::string target):AForm("RobotomyForm", false, 72, 45, target) {}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &form)
{
	*this = form;
}

RobotomyRequestForm	&RobotomyRequestForm::operator=(const RobotomyRequestForm &copy)
{
	AForm::operator=(copy);
	return *this;
}

RobotomyRequestForm::~RobotomyRequestForm(void) {}

void	RobotomyRequestForm::executeForm(void) const
{
	static bool seeded = false;
    if (!seeded) {
        srand(time(NULL));
        seeded = true;
    }
	int randomNum = rand() % 10; // de 0 a 9

	if (randomNum % 2 == 0)
	{
		std::cout << "*drrrr ptrtrtrtrtrtrt trtrtrtrtrtrtr*" << std::endl;
		std::cout << getTarget() << " has been robotomized." << std::endl;
	}
	else
		std::cout << "The robotomy failed." << std::endl;
}