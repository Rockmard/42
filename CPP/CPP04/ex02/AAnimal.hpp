/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AAnimal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpipi <tpipi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/05 16:26:29 by tpipi             #+#    #+#             */
/*   Updated: 2025/02/05 21:11:42 by tpipi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AAnimal_HPP
# define AAnimal_HPP

# include <string>
# include <iostream>

class AAnimal
{
	public:
		AAnimal();
		AAnimal(const AAnimal &AAnimal);
		AAnimal &operator = (const AAnimal &AAnimal);
		
		virtual	void	makeSound()	const = 0;
		std::string		getType()	const;
		
		virtual	~AAnimal();
	protected:
		std::string type;

		AAnimal(std::string type);
};

#endif