/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpipi <tpipi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/05 16:24:28 by tpipi             #+#    #+#             */
/*   Updated: 2025/03/05 16:29:03 by tpipi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"
#include "Dog.hpp"

int	main(void)
{
	Animal* zoo[50];
	std::string	strtab[100];

	// init zoo
	for (int i = 0; i < 25; i++)
		zoo[i] = new Dog();
	for (int i = 25; i < 50; i++)
		zoo[i] = new Cat();
	
	std::cout << "\n" << std::endl;
	// test zoo on 10 animals
	for (int i = 0; i < 10; i++)
		zoo[i]->makeSound();
	std::cout << "\n" << std::endl;
	
	// delete zoo
	for (int i = 0; i < 50; i++)
		delete zoo[i];

	// brain copy
	std::cout << "\n\nTEST DE DEEP COPY\n" << std::endl;
	for (int i = 0; i < 100; i++)
		strtab[i] = "idee";
	Brain brain(strtab);

	std::cout << "\nChat sans cerveau.\n" << std::endl;
	Cat braindead;
	braindead.getBrain();

	std::cout << "\nChat avec cerveau mis manuellement.\n" << std::endl;
	Cat cat(brain);
	cat.getBrain();
	
	std::cout << "\nChat avec cerveau mis par copy.\n" << std::endl;
	Cat cat2(cat);
	cat2.getBrain();
}