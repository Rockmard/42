/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpipi <tpipi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/10 04:58:16 by tpipi             #+#    #+#             */
/*   Updated: 2024/11/08 19:03:12 by tpipi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"
#include <iostream>

Contact::Contact()
{
	//std::cout << "Contact created" << std::endl;
}

Contact::~Contact()
{
	//std::cout << "Contact destroyed" << std::endl;
}

void	Contact::setFirstName(std::string str)
{
	this->_firstName = str;
}

void	Contact::setLastName(std::string str)
{
	this->_lastName = str;
}

void	Contact::setNickname(std::string str)
{
	this->_nickname = str;
}

void	Contact::setPhoneNumber(std::string str)
{
	this->_phoneNumber = str;
}

void	Contact::setDarkestSecret(std::string str)
{
	this->_darkestSecret = str;
}

std::string	Contact::getFirstName(void)
{
	return (this->_firstName);
}

std::string	Contact::getLastName(void)
{
	return (this->_lastName);
}

std::string	Contact::getNickname(void)
{
	return (this->_nickname);
}

std::string	Contact::getPhoneNumber(void)
{
	return (this->_phoneNumber);
}

std::string	Contact::getDarkestSecret(void)
{
	return (this->_darkestSecret);
}
