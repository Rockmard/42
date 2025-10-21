/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpipi <tpipi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/04 13:28:39 by tpipi             #+#    #+#             */
/*   Updated: 2025/06/04 14:44:25 by tpipi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EASYFIND_HPP
# define EASYFIND_HPP

#include <iostream>
#include <algorithm>

class NumberNotFoundException : public std::exception
{
	public:
		const char* what() const throw() {
			return "Number Not Found Exception";
		}
};

template <typename T>
int find(T container, int nb)
{
	typename T::iterator it = find(container.begin(), container.end(), nb);
	
	if (it != container.end())
		return *it;
	else
		throw NumberNotFoundException();
}

#endif