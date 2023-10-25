/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iter.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hanryu <hanryu@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/24 13:02:14 by hanryu            #+#    #+#             */
/*   Updated: 2023/10/25 18:45:59 by hanryu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ITER_HPP
#define ITER_HPP

template <typename T>
void iter(const T *addr, unsigned int len, void (*f)(const T&))
{
	for (unsigned int i = 0; i < len; i++)
		f(addr[i]);
}

template <typename T>
void iter(T *addr, unsigned int len, void (*f)(T&))
{
	for (unsigned int i = 0; i < len; i++)
		f(addr[i]);
}

#endif