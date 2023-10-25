/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hanryu <hanryu@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/24 16:06:54 by hanryu            #+#    #+#             */
/*   Updated: 2023/10/25 12:31:45 by hanryu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARRAY_HPP
#define ARRAY_HPP

template <typename T>
class Array
{
private:
	T *_arr;
	unsigned int _len;
public:
	Array(void);
	Array(unsigned int n);
	~Array(void);
	Array(const Array &origin);
	Array &operator=(const Array &origin);
	T &operator[](unsigned int n);
	const T &operator[](unsigned int n) const;
	unsigned int size(void) const;
};

#include "Array.tpp"

#endif