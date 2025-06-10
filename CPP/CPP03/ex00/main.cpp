/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpipi <tpipi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/05 00:54:41 by tpipi             #+#    #+#             */
/*   Updated: 2025/02/05 16:11:24 by tpipi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

int	main(void)
{
	ClapTrap bob("Bob");
	ClapTrap bob2(bob);

	// HP TESTS
	std::cout << "\nHP (HIT POINTS) TESTS\n" << std::endl;
	bob.attack("Pedro");
	bob.takeDamage(2);
	std::cout << "Bob has " << bob.getHitPoint() << " HP left." << std::endl;
	bob.takeDamage(2);
	std::cout << "Bob has " << bob.getHitPoint() << " HP left." << std::endl;
	bob.beRepaired(5);
	std::cout << "Bob has " << bob.getEnergyPoint() << " EP left." << std::endl;
	bob.takeDamage(4294967295); // is dead since then
	bob.takeDamage(1);
	std::cout << "Bob has " << bob.getHitPoint() << " HP left." << std::endl;  // normally can't go below 0 or boom
	bob.attack("Pedro");
	bob.beRepaired(5);
	std::cout << "Bob has " << bob.getEnergyPoint() << " EP left." << std::endl;

	// EP tests
	std::cout << "\nEP (ENERGY POINTS) TESTS\n" << std::endl;
	for (int i = 0; i < 10; i++)
		bob2.attack("Pedro");
	std::cout << std::endl;
	bob2.attack("Pedro"); // can't attack
	bob2.beRepaired(5); // can't repair
	std::cout << "Bob has " << bob2.getEnergyPoint() << " EP left." << std::endl; // normally can't go below 0 or boom

	// = TESTS
	std::cout << "\n'=' TESTS\n" << std::endl;
	ClapTrap bob3 = bob2;
	std::cout << "Bob3 stats : \n>>HP - " << bob3.getHitPoint() << "\n>>EP - " << bob3.getEnergyPoint() << "\n" << std::endl;
	return 0;
}
