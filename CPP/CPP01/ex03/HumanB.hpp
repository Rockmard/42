/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpipi <tpipi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/16 00:19:40 by tpipi             #+#    #+#             */
/*   Updated: 2025/01/27 17:23:52 by tpipi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HumanB_HPP
# define HumanB_HPP

#include "Weapon.hpp"
#include <string>

class HumanB
{
	public:
		HumanB(std::string name);

		void		attack(void);
		void		setWeapon(Weapon &weapon);

		~HumanB(void);
	private :
		Weapon		*_weapon;
		std::string	_name;
};

#endif