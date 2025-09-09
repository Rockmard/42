/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iter.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpipi <tpipi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/20 16:50:14 by tpipi             #+#    #+#             */
/*   Updated: 2025/07/01 19:53:04 by tpipi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ITER_HPP
# define ITER_HPP

# include <iostream>

template <typename T, typename R>
void	iter(T *array, int length, R (*func)(const T&))
{
	for (int i = 0; i < length; i++)
	{
		func(array[i]);
	}
};

#endif
