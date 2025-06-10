/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpipi <tpipi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/05 16:24:28 by tpipi             #+#    #+#             */
/*   Updated: 2025/02/05 19:27:16 by tpipi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"
#include "Dog.hpp"
#include "WrongCat.hpp"
#include "WrongDog.hpp"

int	main(void)
{
	const Animal *meta = new Animal();
	const Animal *j = new Dog();
	const Animal *i = new Cat();

	const WrongAnimal *wrongMeta = new WrongAnimal();
	const WrongAnimal *wrongJ = new WrongDog();
	const WrongAnimal *wrongI = new WrongCat();

	std::cout << "\nTYPE TESTS\n" << std::endl;

	std::cout << meta->getType() << std::endl;
	std::cout << j->getType() << std::endl;
	std::cout << i->getType() << std::endl;

	std::cout << "\nWRONG TYPE TESTS\n" << std::endl;

	std::cout << wrongMeta->getType() << std::endl;
	std::cout << wrongJ->getType() << std::endl;
	std::cout << wrongI->getType() << std::endl;

	std::cout << "\nSOUND TESTS\n" << std::endl;
	
	i->makeSound();
	j->makeSound();
	meta->makeSound();

	std::cout << "\nWRONG SOUND TESTS\n" << std::endl;

	wrongI->makeSound();
	wrongJ->makeSound();
	wrongMeta->makeSound();

	std::cout << std::endl;

	delete meta;
	delete j;
	delete i;
	delete wrongMeta;
	delete wrongJ;
	delete wrongI;
}