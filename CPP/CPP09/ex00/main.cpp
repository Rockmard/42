/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpipi <tpipi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/10 21:17:34 by tpipi             #+#    #+#             */
/*   Updated: 2025/09/12 10:41:53 by tpipi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

int main(int ac, char **av)
{
	if (ac < 2)
		std::cerr << "Error: could not open file." << std::endl;
	else if (ac > 2)
		std::cerr << "Error: too much inputs." << std::endl;
	else {
		return ft_bitcoin_exchange(av[1]);
	}
	return 0;
}
