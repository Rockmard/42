/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpipi <tpipi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/20 15:28:44 by tpipi             #+#    #+#             */
/*   Updated: 2025/06/10 16:37:45 by tpipi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "classes.hpp"
#include <cstdlib>
#include <ctime>
#include <iostream>

Base	*createA(void)
{
	Base	*a = new A;
	return a;
}

Base	*createB(void)
{
	Base	*b = new B;
	return b;
}

Base	*createC(void)
{
	Base	*c = new C;
	return c;
}

Base	*generate(void)
{
	static bool seeded = false;
	Base* (*functab[])() = {
        &createA,
        &createB,
        &createC
    };

    if (!seeded) {
        srand(time(NULL));
        seeded = true;
    }
	int randomNum = rand() % 3; // de 0 a 2

	std::cout << "The random number is : " << randomNum << "\n0 = A, 1 = B, 2 = C\n" << std::endl;
	Base *randomBase = functab[randomNum]();
	return randomBase;
}

void identify(Base *p)
{
	if (p == NULL)
		std::cerr << "Error ptr point towards nothing" << std::endl;
	else
	{
		if (dynamic_cast<A*>(p))
			std::cout << "The base is an A" << std::endl;
		if (dynamic_cast<B*>(p))
			std::cout << "The base is a B" << std::endl;
		if (dynamic_cast<C*>(p))
			std::cout << "The base is a C" << std::endl;
	}
}

void identify(Base &p)
{
	try
	{
		A a = dynamic_cast<A&>(p);
		std::cout << "The base is an A" << std::endl;
	}
	catch(...) {}
	
	try
	{
		B b = dynamic_cast<B&>(p);
		std::cout << "The base is a B" << std::endl;
	}
	catch(...) {}

	try
	{
		C c = dynamic_cast<C&>(p);
		std::cout << "The base is a C" << std::endl;
	}
	catch(...) {}
}

int	main(void)
{
	Base *b1 = generate();

	identify(b1);
	identify(*b1);
	delete b1;
	return 0;
}