/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpipi <tpipi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/17 12:40:27 by tpipi             #+#    #+#             */
/*   Updated: 2025/10/21 12:34:23 by tpipi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

template <typename Container>
static void printContainer(Container v)
{
	for (typename Container::iterator it = v.begin(); it != v.end(); it++) {
		std::cout << *it << " ";
	}
	std::cout << std::endl;
}

PmergeMe::PmergeMe(void) 
{
	this->_pairSize = 1;
	_nbComp = 0;
}

PmergeMe::PmergeMe(const PmergeMe &cpy)
{
	*this = cpy;
}

PmergeMe &PmergeMe::operator=(const PmergeMe &cpy)
{
	if (this != &cpy)
	{
		this->_deque = cpy._deque;
		this->_vector = cpy._vector;
	}
	return *this;
}

PmergeMe::~PmergeMe(void) {}

std::deque<int>		PmergeMe::getDeque(void) const
{
	return _deque;
}

std::vector<int>	PmergeMe::getVector(void) const
{
	return _vector;
}

size_t				PmergeMe::getNbComp(void) const
{
	return _nbComp;
}

int	PmergeMe::fillContainers(char **argsv)
{
	int 			i = 1, j = 0;
	long int		tmpInt;
	std::string		tmpString;

	while (argsv[i]) {
		j = 0;
		while (argsv[i][j]) {
			if (!std::isdigit(argsv[i][j]) && argsv[i][j] != ' ')
				return 1;

			if (std::isdigit(argsv[i][j]))
				tmpString.push_back(argsv[i][j]);
			if ((argsv[i][j] == ' ' || !argsv[i][j + 1]) && !tmpString.empty()) {
				tmpInt = strtol(tmpString.c_str(), NULL, 10);
				if (errno || tmpInt > INT_MAX)
					return 1;
				_deque.push_back(static_cast<int>(tmpInt));
				_vector.push_back(static_cast<int>(tmpInt));
				tmpString.erase(0);
			}
			j++;
		}
		i++;
	}
	return 0;
}

template <typename Container>
size_t	PmergeMe::sort(Container &container)
{
	Container			tempContainer;
	size_t				i = 0;
	int					index, indexNextPair, getToLastNb;

	while (_pairSize * (i + 1) + (_pairSize - 1) < container.size()) {

		index = _pairSize * i;
		indexNextPair = _pairSize * (i + 1);
		getToLastNb = _pairSize - 1;

		tempContainer.clear();
		_nbComp++; 
		if (container[index + getToLastNb] > container[indexNextPair + getToLastNb]) {
			for (size_t j = 0; j < _pairSize; j++)
				tempContainer.push_back(container[index + j]);
			for (size_t j = 0; j < _pairSize; j++) {
				container[index + j] = container[(indexNextPair + j)];
				container[(indexNextPair + j)] = tempContainer[j];
			}
		}
		i += 2;
	}
	
	_pairSize = _pairSize * 2;
	if (_pairSize > container.size())
		return (_pairSize);
	return (this->sort(container));
}


bool	PmergeMe::isAJacobsthalNumber(unsigned long long n)
{
	for (std::vector<unsigned long long>::iterator it = _jacobsthalNumbers.begin(); it != _jacobsthalNumbers.end(); it++) {
		if (*it == n)
			return true;
	}
	return false;
}

void PmergeMe::buildJacobsthalOrder(unsigned long long sizePend)
{
    int    i = 2;

	_jacobsthalNumbers.reserve(32);
    if (_jacobsthalNumbers.size() > 0)
        _jacobsthalNumbers.clear();
        
    _jacobsthalNumbers.push_back(0);
    _jacobsthalNumbers.push_back(1);

    while (true) {
        _jacobsthalNumbers.push_back(_jacobsthalNumbers[i - 1] + (_jacobsthalNumbers[i - 2] * 2));
        if (_jacobsthalNumbers[i] - 1 > sizePend) {
			_jacobsthalNumbers.pop_back();
            break ;
		}
        i++;
    }
}

template <typename Container, typename Container2>
Container	PmergeMe::getGreaterValue(const Container2 &main, size_t psize)
{
	size_t 				i = psize - 1;
	Container	greaterVal;

	while (i < main.size()) {
		greaterVal.push_back(main[i].first);
		i += psize;
	}
	return greaterVal;
}

template <typename Container, typename Container2>
void	PmergeMe::insertPendIntoMain(Container &main, Container2 &pend, int jacobIndex, size_t pendIndex)
{
	int					mid, left, right;
	size_t				pos, insertPos, upperlimit = 0;
	Container2 			v = getGreaterValue<Container2>(main, _pairSize);

	for (size_t i = _pairSize - 1; i < main.size(); i += _pairSize) {
		if (main[i].second == jacobIndex)
			break;
		upperlimit++;
	}
	
    left = 0;
    right = upperlimit - 1;
	while (left < right)
	{
		_nbComp++;
		mid = left + (right - left) / 2;
		if (pend[pendIndex + _pairSize - 1] < v[mid])
			right = mid;
		else
			left = mid + 1;
	}
	pos = left;

	if (left == static_cast<int>(upperlimit) - 1) {
		_nbComp++;
		if (pend[pendIndex + _pairSize - 1] > v[right])
			pos = upperlimit;
	}

	for (size_t i = 0; i < _pairSize; i++) {
		insertPos = (pos * _pairSize) + i;
		if (insertPos > main.size())
			insertPos = main.size();
		main.insert(main.begin() + insertPos, std::pair<int, int>(pend[pendIndex + i], 0));
	}
}

template <typename Container, typename Container2>
int	PmergeMe::fordJohnsonAlgorithm(Container &container)
{
	int			nbPairPassed = 0;
	bool		fillRest = false;
	Container2	main;
	Container	pend;
	Container	rest;
	
	size_t		jacobIndex = 0;
	size_t		pendIndex = 0;
	size_t		lastPendIndex = 0;

	_pairSize = _pairSize / 2;
	
	for (size_t s = 0; s < container.size(); s++) {
		if (s != 0 && s % _pairSize == 0) {
			nbPairPassed++;
			if (container.size() - s < _pairSize)
				fillRest = true;
		}
			
		if (fillRest)
			rest.push_back(container[s]);
		else if (nbPairPassed == 0 || nbPairPassed % 2 == 1) {
			if (nbPairPassed == 0 || nbPairPassed == 1)
				main.push_back(std::pair<int, int>(container[s], nbPairPassed));
			else
				main.push_back(std::pair<int, int>(container[s], nbPairPassed / 2 + 1));
		}
		else if (nbPairPassed % 2 == 0)
			pend.push_back(container[s]);
	}

	if (pend.size() > 0) {
		buildJacobsthalOrder(pend.size() / _pairSize);

		for (size_t i = 3; i < _jacobsthalNumbers.size(); i++) {
			jacobIndex = _jacobsthalNumbers[i];
			pendIndex = (jacobIndex - 2) * _pairSize;
			lastPendIndex = pendIndex;

			while (pendIndex >= 0) {
				insertPendIntoMain(main, pend, jacobIndex, pendIndex);
				pendIndex -= _pairSize;
				jacobIndex--;
				if (isAJacobsthalNumber(jacobIndex))
					break ;
			}
		}

		if (lastPendIndex == 0)
			insertPendIntoMain(main, pend, -1, 0);
		else {
			for (size_t i = pend.size() - _pairSize; i > lastPendIndex; i -= _pairSize)
				insertPendIntoMain(main, pend, -1, i);
		}
	}
	
	container.clear();
	for (typename Container2::iterator it = main.begin(); it != main.end(); it++)
		container.push_back(it->first);
	for (typename Container::iterator it = rest.begin(); it != rest.end(); it++)
		container.push_back(*it);

	if (_pairSize == 1)
		return 1;
	return this->fordJohnsonAlgorithm<Container, Container2>(container);
}

void	PmergeMe::start(void)
{
	struct timeval tv;
	double startTime, endTime, timeVector, timeDeque;

	std::cout << "Before:  ";
	printContainer(this->getVector());

    gettimeofday(&tv, NULL);
    startTime = tv.tv_sec * 1000000.0 + tv.tv_usec;

	this->sort(_vector);
	this->fordJohnsonAlgorithm<std::vector<int>, std::vector<std::pair<int, int> > >(_vector);
	
    gettimeofday(&tv, NULL);
    endTime = tv.tv_sec * 1000000.0 + tv.tv_usec;
	timeVector = endTime - startTime;

    gettimeofday(&tv, NULL);
    startTime = tv.tv_sec * 1000000.0 + tv.tv_usec;

	this->sort(_deque);
	this->fordJohnsonAlgorithm<std::deque<int>, std::deque<std::pair<int, int> > >(_deque);
	
    gettimeofday(&tv, NULL);
    endTime = tv.tv_sec * 1000000.0 + tv.tv_usec;
	timeDeque = endTime - startTime;

	std::cout << "After:   ";
	printContainer(this->getVector());

	std::cout << "Time to process a range of " << _vector.size() << " elements with std::vector : ";
	std::cout << timeVector << " us." << std::endl;
	std::cout << "Time to process a range of " << _deque.size() << " elements with std::deque :  ";
	std::cout << timeDeque << " us." << std::endl;
}
