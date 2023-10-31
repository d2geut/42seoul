/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hanryu <hanryu@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/31 11:01:59 by hanryu            #+#    #+#             */
/*   Updated: 2023/10/31 18:59:09 by hanryu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <iostream>
#include <vector>
#include <list>
#include <cstdlib>
#include <limits>
#include <stdexcept>
#include <utility>
#include <string>
#include <sys/time.h>
#include <ctime>
#include <iomanip>

void PmergeMe(int argc, char **argv);

template <typename T>
typename std::list<T>::iterator atList(std::list<T> &list, size_t i)
{
	typename std::list<T>::iterator itr;
	size_t t = 0;

	for (itr = list.begin(); itr != list.end(); itr++)
	{
		if (i == t)
			break ;
		t++;
	}
	return itr;
}

#endif