/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpipi <tpipi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/21 16:46:13 by tpipi             #+#    #+#             */
/*   Updated: 2025/05/13 13:33:13 by tpipi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"

Form::Form(void) : _name("Form"), _isSigned(false), _gradeToBeSigned(150), _gradeToBeExec(150) {}

Form::Form(std::string name, bool isSigned, int gradeSign, int gradeExec) : 
	_name(name), 
	_isSigned(isSigned), 
	_gradeToBeSigned(gradeSign), 
	_gradeToBeExec(gradeExec)
{
	if (gradeSign > 150 || gradeExec > 150)
		throw Form::GradeTooLowException();
	else if (gradeSign < 1 || gradeExec < 1)
		throw Form::GradeTooHighException();
}

Form::Form(const Form &copy) :
	_name(copy._name),
	_gradeToBeSigned(copy._gradeToBeSigned), 
	_gradeToBeExec(copy._gradeToBeExec)
{
	*this = copy;
}

Form	&Form::operator =(const Form &copy)
{
	if (this != &copy)
		this->_isSigned = copy.getIsSigned();
	return *this;
}

void	Form::beSigned(Bureaucrat &bur)
{
	if (_gradeToBeSigned < bur.getGrade())
		throw Form::GradeTooLowException();
	_isSigned = true;
}

std::string	Form::getName(void) const
{
	return _name;
}

bool		Form::getIsSigned(void) const
{
	return _isSigned;
}

int			Form::getGradeExec(void) const
{
	return _gradeToBeExec;
}

int			Form::getGradeSign(void) const
{
	return _gradeToBeSigned;
}

Form::~Form(void) {}

std::ostream &operator << (std::ostream &stream, const Form &form)
{
	stream << "Form " << 
			form.getName() << ", needing a grade " << 
			form.getGradeSign() << " to be signed and a grade " << 
			form.getGradeExec() << " to be executed, ";
	if (form.getIsSigned())
		stream << "is signed.";
	else
		stream << "isn't signed.";
	return stream;
}