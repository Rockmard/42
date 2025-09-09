/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpipi <tpipi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/21 16:46:13 by tpipi             #+#    #+#             */
/*   Updated: 2025/02/21 17:44:03 by tpipi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"

AForm::AForm(void) : _name("Form"), _isSigned(false), _gradeToBeSigned(150), _gradeToBeExec(150), _target("home") {}

AForm::AForm(std::string name, bool isSigned, int gradeSign, int gradeExec, std::string target) : 
	_name(name), 
	_isSigned(isSigned), 
	_gradeToBeSigned(gradeSign), 
	_gradeToBeExec(gradeExec),
	_target(target)
{
	if (gradeSign > 150 || gradeExec > 150)
		throw AForm::GradeTooLowException();
	else if (gradeSign < 1 || gradeExec < 1)
		throw AForm::GradeTooHighException();
}

AForm::AForm(const AForm &copy) :
	_name(copy._name),
	_gradeToBeSigned(copy._gradeToBeSigned), 
	_gradeToBeExec(copy._gradeToBeExec),
	_target(copy._target)
{
	*this = copy;
}

AForm	&AForm::operator =(const AForm &copy)
{
	if (this != &copy)
		this->_isSigned = copy.getIsSigned();
	return *this;
}

void	AForm::beSigned(Bureaucrat &bur)
{
	if (_gradeToBeSigned < bur.getGrade())
		throw AForm::GradeTooLowException();
	_isSigned = true;
}

void	AForm::execute(Bureaucrat const &executor) const
{
	if (_isSigned == false)
		throw AForm::FormNotSigned();
	if (_gradeToBeExec < executor.getGrade())
		throw AForm::GradeTooLowException();
	executeForm();
}

std::string	AForm::getName(void) const
{
	return _name;
}

bool		AForm::getIsSigned(void) const
{
	return _isSigned;
}

int			AForm::getGradeExec(void) const
{
	return _gradeToBeExec;
}

int			AForm::getGradeSign(void) const
{
	return _gradeToBeSigned;
}

std::string	AForm::getTarget(void) const
{
	return _target;
}

AForm::~AForm(void) {}

std::ostream &operator << (std::ostream &stream, const AForm &form)
{
	stream << "Form " << 
			form.getName() << ", needing a grade " << 
			form.getGradeSign() << " to be signed and a grade " << 
			form.getGradeExec() << " to be executed, and has a target on " <<
			form.getTarget();
	if (form.getIsSigned())
		stream << ", is signed.";
	else
		stream << ", isn't signed.";
	return stream;
}