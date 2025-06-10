/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpipi <tpipi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/05 16:24:49 by tpipi             #+#    #+#             */
/*   Updated: 2025/02/05 20:56:58 by tpipi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DOG_HPP
# define DOG_HPP

# include "Animal.hpp"
# include "Brain.hpp"

class Dog : public Animal
{
	public :
		Dog();
		Dog(const Dog &dog);
		Dog &operator = (const Dog &dog);

		void	makeSound()	const;

		~Dog();
	private :
		Brain	*brain;
};

#endif