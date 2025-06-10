/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpipi <tpipi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/16 00:19:40 by tpipi             #+#    #+#             */
/*   Updated: 2025/01/27 17:23:54 by tpipi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANA_HPP
# define HUMANA_HPP

#include "Weapon.hpp"
#include <string>

class HumanA
{
	public:
		HumanA(std::string name, Weapon &weapon);

		void		attack(void);

		~HumanA(void);
	private :
		Weapon		&_weapon;
		std::string	_name;
};

#endif