/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpipi <tpipi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/13 14:56:00 by tpipi             #+#    #+#             */
/*   Updated: 2025/05/20 20:20:23 by tpipi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"

Intern::Intern(void) {}

Intern::Intern(const Intern &copy)
{
	(void)copy;
}

Intern	&Intern::operator=(const Intern &copy)
{
	(void)copy;
	return *this;
}

AForm	*Intern::createShrubberyForm(std::string target)
{
	AForm *form = new ShrubberyCreationForm(target);
	return form;
}

AForm	*Intern::createRobotomyForm(std::string target)
{
	AForm *form = new RobotomyRequestForm(target);
	return form;
}

AForm	*Intern::createPresidentialForm(std::string target)
{
	AForm *form = new PresidentialPardonForm(target);
	return form;
}

AForm	*Intern::makeForm(std::string formName, std::string formTarget)
{
	std::string	choices[3] = {
		"shrubbery creation",
		"robotomy request",
		"presidential pardon"
	};
	AForm* (Intern::*functab[])(std::string) = {
        &Intern::createShrubberyForm,
        &Intern::createRobotomyForm,
        &Intern::createPresidentialForm
    };
	
	for (int i = 0; i < 3; i++)
	{
		if (choices[i] == formName)
		{
			std::cout << "Intern creates " << formName << std::endl;
			AForm *form = (this->*functab[i])(formTarget);
			return form;
		}
	}
	std::cout << "Intern couldn't create the form." << std::endl;
	throw Intern::FormNameInvalidException();
}

Intern::~Intern() {}