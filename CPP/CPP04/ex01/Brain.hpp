/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpipi <tpipi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/05 20:33:27 by tpipi             #+#    #+#             */
/*   Updated: 2025/03/05 16:22:36 by tpipi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BRAIN_HPP
# define BRAIN_HPP

# include <string>

class Brain
{
	public:
		Brain();
		Brain(std::string ideas[100]);
		Brain(const Brain &brain);
		Brain &operator = (const Brain &brain);

		std::string	*getIdeas(void);	

		~Brain();
	private:
		std::string	ideas[100];
};

#endif