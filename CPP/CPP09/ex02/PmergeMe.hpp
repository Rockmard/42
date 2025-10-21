/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpipi <tpipi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/12 14:20:43 by tpipi             #+#    #+#             */
/*   Updated: 2025/10/16 08:28:53 by tpipi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PMERGEME_HPP
# define PMERGEME_HPP

# include <iostream>
# include <cctype>
# include <deque>
# include <vector>
# include <cmath>
# include <errno.h>
# include <limits.h>
# include <algorithm>
# include <sys/time.h>

class PmergeMe
{
	public :
		PmergeMe(void);
		PmergeMe(const PmergeMe &cpy);
		PmergeMe &operator=(const PmergeMe &cpy);
		~PmergeMe(void);

		std::deque<int>		getDeque(void) const;
		std::vector<int>	getVector(void) const;
		size_t				getNbComp(void) const;

		int		fillContainers(char **argsv);
		
		template <typename Container, typename Container2>
		void	insertPendIntoMain(Container &main, Container2 &pend, int jacobIndex, size_t pendIndex);

		void	start(void);
	private :
		template <typename Container>
		size_t	sort(Container &container);

		template <typename Container, typename Container2>
		Container	getGreaterValue(const Container2 &main, size_t psize);
		
		template <typename Container, typename Container2>
		int		fordJohnsonAlgorithm(Container &container);

		bool	isAJacobsthalNumber(unsigned long long n);
		void	buildJacobsthalOrder(unsigned long long sizePend);

		std::deque<int>					_deque;
		std::vector<int>				_vector;
		std::vector<unsigned long long>	_jacobsthalNumbers;
		size_t              			_pairSize;
		size_t							_nbComp;
};

#endif