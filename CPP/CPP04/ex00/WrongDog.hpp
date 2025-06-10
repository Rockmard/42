/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongDog.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpipi <tpipi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/05 16:24:49 by tpipi             #+#    #+#             */
/*   Updated: 2025/02/05 19:21:20 by tpipi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WRONGDOG_HPP
# define WRONGDOG_HPP

# include "WrongAnimal.hpp"

class WrongDog : public WrongAnimal
{
	public :
		WrongDog();
		WrongDog(const WrongDog &dog);
		WrongDog &operator = (const WrongDog &dog);

		void	makeSound()	const;

		~WrongDog();
};

#endif