/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpipi <tpipi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/19 16:31:22 by tpipi             #+#    #+#             */
/*   Updated: 2025/05/21 15:42:48 by tpipi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include <iostream>

int	tryIncrement(Bureaucrat &bureaucrat)
{
	std::cout << bureaucrat << std::endl;
	try
	{
		std::cout << "Tentative d'incrementation : " << std::endl;
		bureaucrat.incrementGrade();
		std::cout << bureaucrat << std::endl;
	}
	catch (std::exception &e) 
	{
        std::cout << "Caught Exception : " << e.what() << std::endl;
	}
	return 0;
}

int	tryDecrement(Bureaucrat &bureaucrat)
{
	std::cout << bureaucrat << std::endl;
	try
	{
		std::cout << "Tentative de décrementation : " << std::endl;
		bureaucrat.decrementGrade();
		std::cout << bureaucrat << std::endl;
	}
	catch (std::exception &e) 
	{
        std::cout << "Caught Exception : " << e.what() << std::endl;
	}
	return 0;
}

int	main(void)
{
	std::cout << "Bureaucrat constructor void\n" << std::endl;
	{ // bureaucrat constructor void
		Bureaucrat	alex;

		tryIncrement(alex);
		tryDecrement(alex);
	}
	std::cout << "\nBureaucrat with grade 1\n" << std::endl;
	{ // bureaucrat with grade 1
		Bureaucrat	steve("Steve", 1);

		tryIncrement(steve);
	}
	std::cout << "\nBureaucrat with grade 150\n" << std::endl;
	{ // bureaucrat with grade 150
		Bureaucrat	paul("Paul", 150);

		tryDecrement(paul);
	} 
	std::cout << "\nBureaucrat with grade 75\n" << std::endl;
	{ // bureaucrat with grade 75
		Bureaucrat	kevin("Kevin", 75);

		tryIncrement(kevin);
		tryDecrement(kevin);
	}
	std::cout << "\nBureaucrat with grade wrong grade (0)\n" << std::endl;
	{ // bureaucrat with wrong grade
		try
		{
			Bureaucrat	bureaucrat("Bureaucrat", 0);
			std::cout << bureaucrat << std::endl;
		}
		catch (std::exception &e) 
		{
			std::cout << "Caught Exception : " << e.what() << std::endl;
		}
	        
	}
	std::cout << "\nBureaucrat with grade wrong grade (151)\n" << std::endl;
	{
		try
		{
			Bureaucrat	bureaucrat("Bureaucrat", 151);
			std::cout << bureaucrat << std::endl;
		}
		catch (std::exception &e) 
		{
			std::cout << "Caught Exception : " << e.what() << std::endl;
		}
	        
	}
	Bureaucrat	bureaucrat1("Georges", 150);
	Bureaucrat	bureaucrat2(bureaucrat1);
	std::cout << bureaucrat2 << std::endl;
	return (0);
}