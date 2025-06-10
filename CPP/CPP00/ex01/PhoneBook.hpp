/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpipi <tpipi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/10 04:22:34 by tpipi             #+#    #+#             */
/*   Updated: 2024/12/20 00:46:32 by tpipi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

# include "Contact.hpp"

class PhoneBook
{
	private :
		Contact	_contactList[8];
		int		_nbContacts;
		int		_indexList;
	public :
		PhoneBook(void);
		~PhoneBook(void);
		
		int addContact(void);
		void searchContact(void);
};

#endif