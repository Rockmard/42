/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpipi <tpipi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/04 13:28:24 by tpipi             #+#    #+#             */
/*   Updated: 2025/06/04 14:55:08 by tpipi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "easyfind.hpp"
#include <vector>
#include <deque>
#include <list>

int	main(void)
{
	int tab[] = {1, 22, 32, 54, -26, 0, 22, 908};
	{
		std::vector<int> vec(tab, tab + sizeof(tab) / sizeof(int));
		std::cout << "Testing with a vector : \n" << std::endl;
		try
		{
			int res = ::find(vec, 1);
			std::cout << "Number found : " << res << std::endl;
			res = ::find(vec, 22);
			std::cout << "Number found : " << res << std::endl;
			res = ::find(vec, 4);
			std::cout << "Number found : " << res << std::endl;
		}
		catch(const std::exception &e)
		{
			std::cerr << e.what() << std::endl;
		}
	}
	{
		std::deque<int> deq(tab, tab + sizeof(tab) / sizeof(int));
		std::cout << "\nTesting with a deque : \n" << std::endl;
		try
		{
			int res = ::find(deq, 908);
			std::cout << "Number found : " << res << std::endl;
			res = ::find(deq, 0);
			std::cout << "Number found : " << res << std::endl;
			res = ::find(deq, 275737);
			std::cout << "Number found : " << res << std::endl;
		}
		catch(const std::exception &e)
		{
			std::cerr << e.what() << std::endl;
		}
	}
	{
		std::list<int> list(tab, tab + sizeof(tab) / sizeof(int));
		std::cout << "\nTesting with a list : \n" << std::endl;
		try
		{
			int res = ::find(list, 54);
			std::cout << "Number found : " << res << std::endl;
			res = ::find(list, -26);
			std::cout << "Number found : " << res << std::endl;
			res = ::find(list, 8);
			std::cout << "Number found : " << res << std::endl;
		}
		catch(const std::exception &e)
		{
			std::cerr << e.what() << std::endl;
		}
	}
	return 0;
}