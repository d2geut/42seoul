/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.tpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hanryu <hanryu@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/24 16:41:52 by hanryu            #+#    #+#             */
/*   Updated: 2023/10/25 13:40:35 by hanryu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Array.hpp"

template <typename T>
Array<T>::Array(void) : _len(0)
{
	_arr = new T[0];
}

template <typename T>
Array<T>::Array(unsigned int n) : _len(n)
{
	_arr = new T[n];
	for (unsigned int i = 0; i < n; i++)
		_arr[i] = 0;
}

template <typename T>
Array<T>::~Array(void)
{
	delete[] _arr;
}

template <typename T>
Array<T>::Array(const Array<T> &origin) : _len(origin._len)
{
	_arr = new T[origin._len];
	for (unsigned int i = 0; i < origin._len; i++)
		_arr[i] = origin._arr[i];
}

template <typename T>
Array<T>& Array<T>::operator=(const Array<T> &origin)
{
	if (this != &origin)
	{
		delete[] _arr;
		_len = origin._len;
		_arr = new T[origin._len];
		for (unsigned int i = 0; i < origin._len; i++)
			_arr[i] = origin._arr[i];
	}
	return (*this);
}

template <typename T>
T& Array<T>::operator[](unsigned int n)
{
	if (_len <= n)
		throw std::out_of_range("out of bounds");
	return _arr[n];
}

template <typename T>
const T& Array<T>::operator[](unsigned int n) const
{
	if (_len <= n)
		throw std::out_of_range("out of bounds");
	return _arr[n];
}

template <typename T>
unsigned int Array<T>::size(void) const
{
	return _len;
}
