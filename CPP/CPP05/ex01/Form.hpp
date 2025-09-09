/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpipi <tpipi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/21 16:45:09 by tpipi             #+#    #+#             */
/*   Updated: 2025/05/13 11:56:56 by tpipi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_HPP
# define FORM_HPP

# include "Bureaucrat.hpp"

class Bureaucrat;

class Form
{
	public:
		Form(void);
		Form(std::string name, bool isSigned, int gradeSign, int gradeExec);
		Form(const Form &copy);
		Form &operator= (const Form &copy);
		
		void		beSigned(Bureaucrat &bur);

		std::string	getName(void) const;
		bool		getIsSigned(void) const;
		int			getGradeExec(void) const;
		int			getGradeSign(void) const;

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

		~Form(void);
	private:
		std::string const	_name;
		bool				_isSigned;
		int const			_gradeToBeSigned;
		int const			_gradeToBeExec;
};

std::ostream	&operator<< (std::ostream &stream, const Form &form);

#endif