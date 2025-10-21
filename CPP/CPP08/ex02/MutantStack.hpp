/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpipi <tpipi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/04 18:12:37 by tpipi             #+#    #+#             */
/*   Updated: 2025/10/02 10:46:40 by tpipi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MUTANTSTACK_HPP
# define MUTANTSTACK_HPP

# include <stack>

template<class T>
class MutantStack : public std::stack<T>
{
	public:
		MutantStack(void) : std::stack<T>() {}
		MutantStack(const MutantStack &cpy) : std::stack<T>(cpy) {}
		MutantStack	&operator=(const MutantStack &cpy) { 
			if (this != &cpy)
			{
				std::stack<T>::operator=(cpy);
			}
			return *this; 
		}
		~MutantStack(void) {}

		typedef typename std::stack<T>::container_type::iterator iterator;

		iterator	begin(void) { return this->c.begin(); }
		iterator	end(void) { return this->c.end(); }
};

#endif