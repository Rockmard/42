/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpipi <tpipi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/05 00:54:41 by tpipi             #+#    #+#             */
/*   Updated: 2025/02/05 16:11:19 by tpipi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

int	main(void)
{
	ScavTrap andre("andre");
	ScavTrap andre2(andre);

	// HP TESTS
	std::cout << "\nHP (HIT POINTS) TESTS\n" << std::endl;
	andre.guardGate();
	andre.attack("Pedro");
	andre.takeDamage(2);
	std::cout << "andre has " << andre.getHitPoint() << " HP left." << std::endl;
	andre.takeDamage(2);
	std::cout << "andre has " << andre.getHitPoint() << " HP left." << std::endl;
	andre.beRepaired(5);
	std::cout << "andre has " << andre.getEnergyPoint() << " EP left." << std::endl;
	andre.takeDamage(999); // is dead since then
	std::cout << "andre has " << andre.getHitPoint() << " HP left." << std::endl;  // normally can't go below 0 or boom
	andre.attack("Pedro");
	andre.beRepaired(5);
	andre.guardGate();
	std::cout << "andre has " << andre.getEnergyPoint() << " EP left." << std::endl;

	// EP tests
	std::cout << "\nEP (ENERGY POINTS) TESTS\n" << std::endl;
	for (int i = 0; i < 50; i++)
		andre2.attack("Pedro");
	std::cout << std::endl;
	andre2.attack("Pedro"); // can't attack
	andre2.beRepaired(5); // can't repair
	std::cout << "andre has " << andre2.getEnergyPoint() << " EP left." << std::endl; // normally can't go below 0 or boom

	// = TESTS
	std::cout << "\n'=' TESTS\n" << std::endl;
	ScavTrap andre3 = andre2;
	std::cout << "andre3 stats : \n>>HP - " << andre3.getHitPoint() << "\n>>EP - " << andre3.getEnergyPoint() << "\n" << std::endl;
	return 0;
}