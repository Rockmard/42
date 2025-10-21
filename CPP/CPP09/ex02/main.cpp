/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpipi <tpipi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/12 14:20:29 by tpipi             #+#    #+#             */
/*   Updated: 2025/10/15 11:43:39 by tpipi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

static bool hasDuplicates(std::vector<int> list)
{
	std::vector<int>::iterator	testIt;
	
	for (std::vector<int>::iterator it = list.begin(); it != list.end(); it++) {
		testIt = std::find(it + 1, list.end(), *it);
		if (testIt != list.end()) {
			std::cout << *it << std::endl;
			return true;
		}
	}
	return false;
}

int main(int ac, char **av)
{
	PmergeMe			pmergeme;

	if (ac == 1)
		std::cerr << "Error: argument(s) missing." << std::endl;
	else {
		if (pmergeme.fillContainers(av) == 1)
			std::cerr << "Error: Only positive integers and spaces are allowed." << std::endl;
		else if (hasDuplicates(pmergeme.getVector()))
			std::cerr << "Error: Duplicates have been found." << std::endl;
		else 
			pmergeme.start();
	}
	return 0;
}
