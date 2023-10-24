/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hanryu <hanryu@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/24 16:06:54 by hanryu            #+#    #+#             */
/*   Updated: 2023/10/24 18:23:18 by hanryu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARRAY_HPP
#define ARRAY_HPP

template <typename T>
class Array
{
private:
	T *_arr;
	std::size_t _len;
public:
	Array(void);
	Array(unsigned int n);
	~Array(void);
	Array(const Array &origin);
	Array &operator=(const Array &origin);
	T &operator[](unsigned int n);
	unsigned int size(void) const;
};

#include "Array.tpp"

#endif