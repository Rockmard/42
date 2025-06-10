/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpipi <tpipi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/05 16:26:29 by tpipi             #+#    #+#             */
/*   Updated: 2025/02/05 18:44:18 by tpipi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ANIMAL_HPP
# define ANIMAL_HPP

# include <string>
# include <iostream>

class Animal
{
	public:
		Animal();
		Animal(const Animal &animal);
		Animal &operator = (const Animal &animal);
		
		virtual	void	makeSound()	const;
		std::string		getType()	const;
		
		virtual	~Animal();
	protected:
		std::string type;

		Animal(std::string type);
};

#endif