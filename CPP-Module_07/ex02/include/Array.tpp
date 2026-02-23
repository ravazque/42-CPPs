/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.tpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ravazque <ravazque@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/23 12:00:00 by ravazque          #+#    #+#             */
/*   Updated: 2026/02/23 12:00:00 by ravazque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARRAY_TPP
# define ARRAY_TPP

template <typename T>
Array<T>::Array(void) : _array(NULL), _size(0) {}

template <typename T>
Array<T>::Array(unsigned int n) : _array(new T[n]()), _size(n) {}

template <typename T>
Array<T>::Array(const Array &src) : _array(NULL), _size(0)
{
	*this = src;
}

template <typename T>
Array<T>::~Array(void)
{
	delete [] _array;
}

template <typename T>
Array<T> &Array<T>::operator=(const Array &src)
{
	if (this == &src)
		return (*this);
	delete [] _array;
	_size = src._size;
	_array = new T[_size]();
	for (unsigned int i = 0; i < _size; i++)
		_array[i] = src._array[i];
	return (*this);
}

template <typename T>
T &Array<T>::operator[](unsigned int index)
{
	if (index >= _size)
		throw std::exception();
	return (_array[index]);
}

template <typename T>
T const &Array<T>::operator[](unsigned int index) const
{
	if (index >= _size)
		throw std::exception();
	return (_array[index]);
}

template <typename T>
unsigned int Array<T>::size(void) const
{
	return (_size);
}

#endif
