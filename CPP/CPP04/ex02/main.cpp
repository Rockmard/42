/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpipi <tpipi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/05 16:24:28 by tpipi             #+#    #+#             */
/*   Updated: 2025/03/05 16:45:52 by tpipi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"
#include "Dog.hpp"

int	main(void)
{
	// decomment and compile to see that it doesn't work
	//AAnimal	animal;
	AAnimal* zoo[50];

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
}