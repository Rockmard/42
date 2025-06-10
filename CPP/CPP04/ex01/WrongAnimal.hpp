/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpipi <tpipi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/05 16:26:29 by tpipi             #+#    #+#             */
/*   Updated: 2025/02/06 00:42:46 by tpipi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WRONGANIMAL_HPP
# define WRONGANIMAL_HPP

# include <string>
# include <iostream>

class WrongAnimal
{
	public:
		WrongAnimal();
		WrongAnimal(const WrongAnimal &animal);
		WrongAnimal &operator = (const WrongAnimal &animal);
		
		void			makeSound()	const;
		std::string		getType()	const;
		
		virtual	~WrongAnimal();
	protected:
		std::string type;

		WrongAnimal(std::string type);
};

#endif