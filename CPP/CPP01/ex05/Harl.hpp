/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpipi <tpipi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/16 00:19:40 by tpipi             #+#    #+#             */
/*   Updated: 2025/01/27 17:23:25 by tpipi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HARL_HPP
# define HARL_HPP

#include <string>

class Harl
{
	public:
		Harl();

		void	complain(std::string level);

		~Harl(void);
	private :
		void	debug(void);
		void	info(void);
		void	warning(void);
		void	error(void);
};

#endif