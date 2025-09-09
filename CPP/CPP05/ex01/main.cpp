/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpipi <tpipi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/19 16:31:22 by tpipi             #+#    #+#             */
/*   Updated: 2025/05/13 15:34:46 by tpipi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Form.hpp"

int	main(void)
{
	{
		std::cout << "TEST CONSTRUCTOR EXCEPTIONS\n" << std::endl;
		try
		{
			std::cout << ">> Sign grade 0" << std::endl;
			Form("Form", false, 0, 75);
		}
		catch(const std::exception& e)
		{
			std::cerr << e.what() << '\n';
		}
		try
		{
			std::cout << ">> Sign grade 151" << std::endl;
			Form("Form", false, 151, 75);
		}
		catch(const std::exception& e)
		{
			std::cerr << e.what() << '\n';
		}
		try
		{
			std::cout << ">> Exec grade 0" << std::endl;
			Form("Form", false, 75, 0);
		}
		catch(const std::exception& e)
		{
			std::cerr << e.what() << '\n';
		}
		try
		{
			std::cout << ">> Exec grade 151" << std::endl;
			Form("Form", false, 75, 151);
		}
		catch(const std::exception& e)
		{
			std::cerr << e.what() << '\n';
		}
	}
	{
		std::cout << "\nTEST BUREAUCRAT signForm() FUNCTION, THUS TESTING EXCEPTIONS\n" << std::endl;
		try
		{
			std::cout << ">> Creating John, a 150 grade bureaucrat" << std::endl;
			Bureaucrat	john("John", 150);
			Form form("Form", false, 75, 75);
			std::cout << form << std::endl;
			john.signForm(form);
			std::cout << form << std::endl;
		}
		catch(const std::exception& e) //won't catch anything in THIS scenario because it's already caught in the signForm func
		{
			std::cerr << e.what() << '\n';
		}
		std::cout << std::endl;
		try
		{
			std::cout << ">> Creating Marc, a 1 grade bureaucrat" << std::endl;
			Bureaucrat	john("John", 1);
			Form form("Form", false, 75, 75);
			std::cout << form << std::endl;
			john.signForm(form);
			std::cout << form << std::endl;
		}
		catch(const std::exception& e) //same
		{
			std::cerr << e.what() << '\n';
		}
	}
	return 0;
}