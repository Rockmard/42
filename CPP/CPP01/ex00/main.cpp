/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpipi <tpipi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/08 19:37:10 by tpipi             #+#    #+#             */
/*   Updated: 2025/02/19 15:13:23 by tpipi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int	main(void)
{
	Zombie	zombieAlan;
	Zombie	zombieGandalf("Gandalf");
	Zombie	*zombieKevin;

	zombieKevin = newZombie("Kevin");
	zombieAlan.setName("Alan");

	randomChump("Ivy");
	zombieAlan.announce();
	zombieGandalf.announce();
	if (zombieKevin != NULL)
	{
		zombieKevin->announce();
		delete zombieKevin;
	}
	return (0);
}