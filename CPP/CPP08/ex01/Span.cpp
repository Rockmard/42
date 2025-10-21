/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpipi <tpipi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/04 14:57:32 by tpipi             #+#    #+#             */
/*   Updated: 2025/06/04 18:07:12 by tpipi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

Span::Span(unsigned int N)
{
	numbers = std::vector<int>(0);
	size = N;
}

Span::Span(const Span &cpy)
{
	*this = cpy;
}

Span   &Span::operator=(const Span &cpy)
{
	if (this != &cpy)
	{
		this->size = cpy.size;
		this->numbers = cpy.numbers;
	}
	return *this;
}

Span::~Span(void) {}

void	Span::addNumber(int nb)
{
	if (numbers.size() == size)
		throw std::length_error("Can't add the number, list full.");
	numbers.push_back(nb);
}

void	Span::addNumber(std::vector<int>::iterator first, std::vector<int>::iterator last)
{
	int distance = std::distance(first, last);
	if (numbers.size() + distance > size)
		throw std::length_error("Can't add the number, list full.");
	numbers.insert(numbers.end(), first, last);
}

unsigned int	Span::shortestSpan(void)
{
	unsigned int i = 0;
	int minDiff = __INT_MAX__;
	int tempDiff;

	if (numbers.size() < 2)
		throw std::length_error("List has not enough numbers to be able to perform a span.");
	std::vector<int> sortedTmp = numbers;
	std::sort(sortedTmp.begin(), sortedTmp.end());
	while (i < size - 1)
	{
		tempDiff = sortedTmp[i + 1] - sortedTmp[i];
		if (tempDiff < minDiff)
			minDiff = tempDiff;
		i++;
	}
	return minDiff;
}

unsigned int	Span::longestSpan(void)
{
	if (numbers.size() < 2)
		throw std::length_error("List has not enough numbers to be able to perform a span.");
	std::vector<int>::iterator min = std::min_element(numbers.begin(), numbers.end());
	std::vector<int>::iterator max = std::max_element(numbers.begin(), numbers.end());
	return *max - *min;
}