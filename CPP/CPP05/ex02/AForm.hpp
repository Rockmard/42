/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AAForm.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpipi <tpipi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/21 16:45:09 by tpipi             #+#    #+#             */
/*   Updated: 2025/05/13 11:24:13 by tpipi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AFORM_HPP
# define AFORM_HPP

# include "Bureaucrat.hpp"

class Bureaucrat;

class AForm
{
	public:
		AForm(void);
		AForm(std::string name, bool isSigned, int gradeSign, int gradeExec, std::string target);
		AForm(const AForm &copy);
		AForm &operator= (const AForm &copy);
		
		void		beSigned(Bureaucrat &bur);
		void		execute(Bureaucrat const &executor) const;

		std::string	getName(void) const;
		bool		getIsSigned(void) const;
		int			getGradeExec(void) const;
		int			getGradeSign(void) const;
		std::string	getTarget(void) const;

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

		class FormNotSigned : public std::exception
		{
			public:
				const char* what() const throw() {
					return "Form Not Signed Exception";
				}
		};

		virtual	~AForm(void);
	private:
		std::string const	_name;
		bool				_isSigned;
		int	const			_gradeToBeSigned;
		int	const			_gradeToBeExec;
		std::string	const	_target;
	protected:
		virtual void	executeForm(void) const = 0;
};

std::ostream	&operator<< (std::ostream &stream, const AForm &form);

#endif