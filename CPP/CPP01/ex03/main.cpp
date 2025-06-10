/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpipi <tpipi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/16 00:51:13 by tpipi             #+#    #+#             */
/*   Updated: 2025/02/19 15:00:55 by tpipi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"
#include "HumanA.hpp"
#include "HumanB.hpp"

int main()
{
	{
		Weapon club = Weapon("crude spiked club");
		HumanA bob("Bob", club);

		bob.attack();
		
		club.setType("some other type of club");
		bob.attack();
	}
	{
		Weapon club = Weapon("crude spiked club");
		Weapon weirdWeapon = Weapon();
		HumanB jim("Jim");

		jim.attack();

		jim.setWeapon(club);
		jim.attack();

		club.setType("some other type of club");
		jim.attack();

		jim.setWeapon(weirdWeapon);
		jim.attack();
	}
	return 0;
}
