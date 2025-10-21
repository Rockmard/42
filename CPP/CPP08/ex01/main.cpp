/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpipi <tpipi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/04 14:56:49 by tpipi             #+#    #+#             */
/*   Updated: 2025/06/04 18:10:02 by tpipi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"
#include <ctime>

int main(void)
{
	{
		Span sp = Span(5);
		sp.addNumber(6);
		sp.addNumber(3);
		sp.addNumber(17);
		sp.addNumber(9);
		sp.addNumber(11);

		std::cout << sp.shortestSpan() << std::endl;
		std::cout << sp.longestSpan() << std::endl;
	}
	{
		Span sp = Span(10);

		try
		{
			std::cout << "\n>> Essaie de shortestSpan() sans valeur." << std::endl;
			sp.shortestSpan();
		}
		catch(const std::exception& e)
		{
			std::cerr << e.what() << '\n';
		}
		sp.addNumber(6);
		try
		{
			std::cout << "\n>> Essaie de longestSpan() avec une valeur." << std::endl;
			sp.longestSpan();
		}
		catch(const std::exception& e)
		{
			std::cerr << e.what() << '\n';
		}
		sp.addNumber(3);
		sp.addNumber(17);
		sp.addNumber(9);
		sp.addNumber(11);
		try
		{
			std::cout << "\n>> Ajout liste beaucoup trop grande de 1" << std::endl;
			std::vector<int> vector(6, 5);
			std::vector<int>::iterator first = vector.begin();
			std::vector<int>::iterator last = vector.end();
			sp.addNumber(first, last);
		}
		catch(const std::exception& e)
		{
			std::cerr << e.what() << '\n';
		}
		try
		{
			std::cout << "\n>> Ajout liste pile de la bonne taille" << std::endl;
			std::vector<int> vector(5, 5);
			std::vector<int>::iterator first = vector.begin();
			std::vector<int>::iterator last = vector.end();
			sp.addNumber(first, last);
		}
		catch(const std::exception& e)
		{
			std::cerr << e.what() << '\n';
		}
	}
	{
		Span sp = Span(100000);
		try
		{	std::srand(unsigned(std::time(NULL)));
			std::vector<int> v(100000);
			std::generate(v.begin(), v.end(), std::rand);
			std::vector<int>::iterator first = v.begin();
			std::vector<int>::iterator last = v.end();
			sp.addNumber(first, last);
			std::cout << "\n>> Les 1000000 ont normalement ete insere, j'ajoute un chiffre pour voir si l'exception se jette bien." << std::endl;
			sp.addNumber(0);
		}
		catch(const std::exception& e)
		{
			std::cerr << e.what() << '\n';
		}
	}
	return 0;
}