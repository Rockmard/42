/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpipi <tpipi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/15 20:42:25 by tpipi             #+#    #+#             */
/*   Updated: 2025/06/10 16:51:48 by tpipi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"

int	main(void)
{
	Data data(1275, "data");
	
	std::cout << "Data address : " << &data << std::endl;
	uintptr_t ptr = Serializer::serialize(&data);
	std::cout << "\nSerializing the data..." << std::endl;
	Data *dataptr = Serializer::deserialize(ptr);
	std::cout << "Deserializing the data..." << std::endl;
	std::cout << "\nData address : " << dataptr << std::endl;
	std::cout << "Data str : " << dataptr->getStr() << std::endl;
	std::cout << "Data val : " << dataptr->getVal() << std::endl;

	return (0);
}