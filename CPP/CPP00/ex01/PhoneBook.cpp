/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpipi <tpipi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/10 05:06:31 by tpipi             #+#    #+#             */
/*   Updated: 2024/12/20 01:08:48 by tpipi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"
#include <iostream>

PhoneBook::PhoneBook()
{
	this->_indexList = 0;
	this->_nbContacts = 0;
	//std::cout << "PhoneBook created" << std::endl;
}

PhoneBook::~PhoneBook()
{
	//std::cout << "PhoneBook destroyed" << std::endl;
}

int	PhoneBook::addContact()
{
	std::string	tmp;
	Contact		contact;

	std::cout << "(ADD) >> What's the first name ? : ";
	if (!std::getline(std::cin, tmp) || tmp.length() == 0)
		return (1);
	contact.setFirstName(tmp);
	std::cout << "(ADD) >> What's the last name ? : ";
	if (!std::getline(std::cin, tmp) || tmp.length() == 0)
		return (1);
	contact.setLastName(tmp);
	std::cout << "(ADD) >> What's the nickname ? : ";
	if (!std::getline(std::cin, tmp) || tmp.length() == 0)
		return (1);
	contact.setNickname(tmp);
	std::cout << "(ADD) >> What's the phone number ? : ";
	if (!std::getline(std::cin, tmp) || tmp.length() == 0)
		return (1);
	contact.setPhoneNumber(tmp);
	std::cout << "(ADD) >> What's the darkest secret ? : ";
	if (!std::getline(std::cin, tmp) || tmp.length() == 0)
		return (1);
	contact.setDarkestSecret(tmp);
	this->_contactList[this->_indexList] = contact;
	this->_indexList++;
	if (this->_indexList == 8)
		this->_indexList = 0;
	if (this->_nbContacts < 8)
		this->_nbContacts++;
	std::cout << "(ADD) >> Contact added to the list." << std::endl;
	return (2);
}

static void	align_print(std::string str)
{
	int	space_nb;

	space_nb = 10 - str.length();
	std::cout << "|";
	for (int i = 0; i < space_nb; i++)
		std::cout << " ";
	if (str.length() > 10)
	{
		for (int i = 0; i < 9; i++)
			std::cout << str[i];
		std::cout << ".";
	}
	else
		std::cout << str;
}

void	PhoneBook::searchContact()
{
	int			index;
	int			index_chosen;
	std::string	answer;

	index = 0;
	std::cout << "|----------|----------|----------|----------|" << std::endl;
	std::cout << "|     Index|First Name| Last Name|  Nickname|" << std::endl;
	std::cout << "|----------|----------|----------|----------|" << std::endl;
	if (this->_nbContacts == 0)
	{
		std::cout << "(SEARCH) >> No contact to get the info from :'(" << std::endl;
		return ;
	}
	while (index < this->_nbContacts)
	{
		std::cout << "|         " << index;
		align_print(this->_contactList[index].getFirstName());
		align_print(this->_contactList[index].getLastName());
		align_print(this->_contactList[index].getNickname());
		std::cout << "|" << std::endl;
		index++;
	}
	std::cout << "|----------|----------|----------|----------|" << std::endl;
	std::cout << "(SEARCH) >> Enter the index of the contact you wanna get the info of : ";
	if (!std::getline(std::cin, answer))
		return ;
	index_chosen = answer[0] - '0';
	if (answer.length() != 1 || !(index_chosen >= 0 && index_chosen < this->_nbContacts))
		std::cout << "(SEARCH) >> Not a valid index / index format :'(" << std::endl;
	else
	{
		std::cout << "(SEARCH) >> First Name : " << this->_contactList[index_chosen].getFirstName() << std::endl;
		std::cout << "(SEARCH) >> Last Name : " << this->_contactList[index_chosen].getLastName() << std::endl;
		std::cout << "(SEARCH) >> Nickname : " << this->_contactList[index_chosen].getNickname() << std::endl;
		std::cout << "(SEARCH) >> Phone Number : " << this->_contactList[index_chosen].getPhoneNumber() << std::endl;
		std::cout << "(SEARCH) >> Darkest Secret : " << this->_contactList[index_chosen].getDarkestSecret() << std::endl;
	}
}
