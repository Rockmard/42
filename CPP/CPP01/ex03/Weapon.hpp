/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpipi <tpipi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/15 23:51:57 by tpipi             #+#    #+#             */
/*   Updated: 2024/11/16 01:06:42 by tpipi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WEAPON_HPP
# define WEAPON_HPP

#include <string>

class Weapon
{
	public :
		Weapon(void);
		Weapon(std::string type);

		std::string	getType(void);
		void		setType(std::string type);

		~Weapon(void);
	private :
		std::string _type;
};

#endif
