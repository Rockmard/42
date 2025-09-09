/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpipi <tpipi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/13 14:55:45 by tpipi             #+#    #+#             */
/*   Updated: 2025/05/13 15:33:19 by tpipi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INTERN_HPP
# define INTERN_HPP

# include "AForm.hpp"
# include "ShrubberyCreationForm.hpp"
# include "RobotomyRequestForm.hpp"
# include "PresidentialPardonForm.hpp"

class Intern
{
	public:
		Intern(void);
		Intern(const Intern &copy);
		Intern &operator=(const Intern &copy);

		AForm	*makeForm(std::string formName, std::string formTarget);

		class FormNameInvalidException : public std::exception
		{
			public:
				const char* what() const throw() {
					return "Form Name Invalid Exception";
				}
		};

		~Intern();
	private:
		AForm	*createShrubberyForm(std::string target);
		AForm	*createRobotomyForm(std::string target);
		AForm	*createPresidentialForm(std::string target);
};

#endif