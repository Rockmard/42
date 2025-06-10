/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpipi <tpipi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/08 20:10:19 by tpipi             #+#    #+#             */
/*   Updated: 2025/02/19 15:14:52 by tpipi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"
#include <iostream>

int	main(void)
{
	Zombie	*horde;
	int		N;

	N = 5;
	horde = zombieHorde(N, "Alan");
	if (horde == NULL)
	{
		std::cout << "It seems a memory issue occured while creating the horde.\nThe program has been discontinued." << std::endl;
		return (1);
	}

	std::cout << "A la main un par un" << std::endl;
	horde[0].announce();
	horde[1].announce();
	horde[2].announce();
	horde[3].announce();
	horde[4].announce();

	std::cout << "Boucle" << std::endl;
	for (int i = 0; i < N; i++) {
		horde[i].announce();
	}

	std::cout << "Test renvoi du premier" << std::endl;
	horde[0].setName("Martin");
	horde->announce();
	
	delete [] horde;
	return (0);
}
