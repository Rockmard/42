/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpipi <tpipi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/20 17:51:57 by tpipi             #+#    #+#             */
/*   Updated: 2025/06/10 18:12:47 by tpipi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARRAY_HPP
# define ARRAY_HPP

template <typename T>
class Array
{
	public:
		Array(void) {
			array = NULL;
			_size = 0;
		}

		Array(unsigned int n) {
			array = new T[n]();
			_size = n;
		}

		Array(const Array &copy) {
			array = NULL;
			_size = 0;
			*this = copy;
		}

		Array &operator=(const Array &copy) {
			if (this != &copy)
			{
				if (_size != copy._size)
				{
					_size = copy._size;
					delete [] array;
					array = new T[_size];
				}
				for (int i = 0; i < _size; i++)
					array[i] = copy[i];
			}
			return *this;
		}

		T &operator [](int i) {
			if (i >= 0 && i < _size)
				return array[i];
			throw std::out_of_range("Bad index out of range");
		}
	
		T operator [](int i) const {
			if (i >= 0 && i < _size)
				return array[i];
			throw std::out_of_range("Bad index out of range");
		}
		
		int	size(void) {
			return this->_size;
		}

		~Array(void) {
			delete [] array;;
		}
	private:
		T 				*array;
		int	_size;
};

#endif
