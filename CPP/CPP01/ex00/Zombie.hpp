/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpipi <tpipi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 01:11:27 by tpipi             #+#    #+#             */
/*   Updated: 2024/11/16 00:05:10 by tpipi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIE_HPP
# define ZOMBIE_HPP

# include <string>

class Zombie
{
	public:
		Zombie(void);
		Zombie(std::string name);

		std::string	getName(void);
		void		setName(std::string name);
		void		announce(void);
		
		~Zombie(void);
	private:
		std::string	name;
};

Zombie* newZombie(std::string name);
void	randomChump(std::string name);

#endif