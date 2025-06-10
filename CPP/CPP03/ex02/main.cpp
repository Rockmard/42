/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpipi <tpipi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/05 00:54:41 by tpipi             #+#    #+#             */
/*   Updated: 2025/02/28 10:32:23 by tpipi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

int	main(void)
{
	FragTrap mars("mars");
	FragTrap mars2(mars);

	// HP TESTS
	std::cout << "\nHP (HIT POINTS) TESTS\n" << std::endl;
	mars.highFivesGuys();
	mars.attack("Pedro");
	mars.takeDamage(5);
	std::cout << "mars has " << mars.getHitPoint() << " HP left." << std::endl;
	mars.takeDamage(7);
	std::cout << "mars has " << mars.getHitPoint() << " HP left." << std::endl;
	mars.beRepaired(15);
	std::cout << "mars has " << mars.getEnergyPoint() << " EP left." << std::endl;
	mars.takeDamage(999); // is dead since then
	std::cout << "mars has " << mars.getHitPoint() << " HP left." << std::endl;  // normally can't go below 0 or boom
	mars.attack("Pedro");
	mars.beRepaired(5);
	mars.highFivesGuys();
	std::cout << "mars has " << mars.getEnergyPoint() << " EP left." << std::endl;

	// EP tests
	std::cout << "\nEP (ENERGY POINTS) TESTS\n" << std::endl;
	for (int i = 0; i < 100; i++)
		mars2.attack("Pedro");
	std::cout << std::endl;
	mars2.attack("Pedro"); // can't attack
	mars2.beRepaired(5); // can't repair
	std::cout << "mars has " << mars2.getEnergyPoint() << " EP left." << std::endl; // normally can't go below 0 or boom

	// = TESTS
	std::cout << "\n'=' TESTS\n" << std::endl;
	FragTrap mars3 = mars2;
	std::cout << "mars3 stats : \n>>HP - " << mars3.getHitPoint() << "\n>>EP - " << mars3.getEnergyPoint() << "\n" << std::endl;
	return 0;
}