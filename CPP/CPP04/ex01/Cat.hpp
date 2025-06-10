/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpipi <tpipi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/05 16:25:41 by tpipi             #+#    #+#             */
/*   Updated: 2025/03/05 16:08:26 by tpipi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CAT_HPP
# define CAT_HPP

# include "Animal.hpp"
# include "Brain.hpp"

class Cat : public Animal
{
	public :
		Cat();
		Cat(Brain &brain);
		Cat(const Cat &cat);
		Cat &operator = (const Cat &cat);

		void	makeSound()	const;
		void	getBrain()	const;

		~Cat();
	private :
		Brain	*brain;
};

#endif