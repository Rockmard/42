/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpipi <tpipi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/04 14:56:55 by tpipi             #+#    #+#             */
/*   Updated: 2025/06/04 18:05:37 by tpipi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPAN_HPP
# define SPAN_HPP

# include <vector>
# include <stdexcept>
# include <iostream>
# include <algorithm>

class Span
{
	public :
		Span(unsigned int N);
		Span(const Span &cpy);
		Span   &operator=(const Span &cpy);
		~Span(void);

		void			addNumber(int nb);
		void			addNumber(std::vector<int>::iterator first, std::vector<int>::iterator last);
		unsigned int	shortestSpan(void);
		unsigned int	longestSpan(void);
	private :
		std::vector<int>	numbers;
		unsigned int		size;
};

#endif