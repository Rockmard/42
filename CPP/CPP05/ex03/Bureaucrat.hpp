/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpipi <tpipi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/19 16:31:35 by tpipi             #+#    #+#             */
/*   Updated: 2025/05/13 13:39:31 by tpipi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

# include <string>
# include <iomanip>
# include <iostream>
# include "AForm.hpp"

class AForm;

class Bureaucrat
{
	public :
		Bureaucrat(void);
		Bureaucrat(std::string name, int grade);
		Bureaucrat(const Bureaucrat &copy);
		Bureaucrat &operator= (const Bureaucrat &copy);

		void	signForm(AForm &form);
		void	executeForm(AForm const &form) const;

		std::string	getName(void) const;
		int			getGrade(void) const;
		void		incrementGrade(void);
		void		decrementGrade(void);
		
		class GradeTooHighException : public std::exception
		{
			public:
				const char* what() const throw() {
					return "Grade Too High Exception";
				}
		};

		class GradeTooLowException : public std::exception
		{
			public:
				const char* what() const throw() {
					return "Grade Too Low Exception";
				}
		};

		~Bureaucrat(void);
	private :
		std::string const	_name;
		int					_grade;
};

std::ostream	&operator<< (std::ostream &stream, const Bureaucrat &bur);

#endif