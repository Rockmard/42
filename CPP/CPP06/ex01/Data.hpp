/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Data.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpipi <tpipi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/15 20:34:26 by tpipi             #+#    #+#             */
/*   Updated: 2025/06/10 16:51:04 by tpipi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DATA_HPP
# define DATA_HPP

# include <iostream>

class Data
{
	public:
		Data(int val, std::string str);
		Data(const Data &copy);
		Data &operator=(const Data &copy);

		std::string	getStr(void);
		int			getVal(void);

		~Data(void);
	private:
		int			_val;
		std::string	_str;
};

#endif