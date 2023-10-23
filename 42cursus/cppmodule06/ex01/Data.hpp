/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Data.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hanryu <hanryu@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/23 14:53:43 by hanryu            #+#    #+#             */
/*   Updated: 2023/10/23 14:59:58 by hanryu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DATA_HPP
#define DATA_HPP

#include <string>

class Data
{
private:
	std::string _name;
	int _data;
	Data(void);
public:
	Data(std::string name, int data);
	~Data(void);
	Data(const Data &origin);
	Data &operator=(const Data &origin);
	std::string getName(void) const;
	int getData(void) const;
};

#endif