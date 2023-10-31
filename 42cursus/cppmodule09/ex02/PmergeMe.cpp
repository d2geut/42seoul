/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hanryu <hanryu@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/31 11:02:01 by hanryu            #+#    #+#             */
/*   Updated: 2023/10/31 19:45:07 by hanryu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

static void isValidArgv(int argc, char **argv, std::vector<int> &vec, std::list<int> &list)
{
	for (int i = 1; i < argc; i++)
	{
		long num;
		char *e;
		num = strtol(argv[i], &e, 10);
		if (*e || num > std::numeric_limits<int>::max() || num < 0)
			throw std::runtime_error("is not positive integer");
		vec.push_back(static_cast<int>(num));
		list.push_back(static_cast<int>(num));
	}
}

static bool isAlreadySorted(std::vector<int> &vec)
{
	size_t i;

	for (i = 1; i < vec.size(); i++)
	{
		if (vec[i - 1] > vec[i])
			break ;
	}
	if (i == vec.size())
	{
		std::cout << "Already Sorted" << std::endl;
		return true;
	}
	return false;
}

static std::pair<int, int> makePair(int a, int b)
{
	if (a < b)
		return std::make_pair(b, a);
	else
		return std::make_pair(a, b);
}

static void mergeVectorPair(std::vector< std::pair<int, int> > &pair, size_t left, size_t mid, size_t right)
{
	std::vector< std::pair<int, int> > temp;
	size_t i = left;
	size_t j = mid + 1;
	size_t t = 0;
	
	while (i <= mid && j <= right)
	{
		if (pair[i].first <= pair[j].first)
		{
			temp.push_back(pair[i++]);
			t++;
		}
		else
		{
			temp.push_back(pair[j++]);
			t++;
		}
	}
	while (j <= right)
	{
		temp.push_back(pair[j++]);
		t++;
	}
	while (i <= mid)
	{
		temp.push_back(pair[i++]);
		t++;
	}
	t = 0;
	for (size_t l = left; l <= right; l++)
		pair[l] = temp[t++];
}

static void msortVectorPair(std::vector< std::pair<int, int> > &pair, size_t left, size_t right)
{
	size_t mid;

	if (left < right)
	{
		mid = (left + right) / 2;
		msortVectorPair(pair, left, mid);
		msortVectorPair(pair, mid + 1, right);
		mergeVectorPair(pair, left, mid, right);
	}
}

static void binaryInsertVector(std::vector<int> &vec, int t, int left, int right)
{
	size_t mid = (left + right) / 2;

	if (left > right)
	{
		vec.insert(vec.begin() + left, t);
		return ;
	}
	if (t == vec[mid])
		vec.insert(vec.begin() + mid, t);
	else if (t < vec[mid])
		binaryInsertVector(vec, t, left, mid - 1);
	else
		binaryInsertVector(vec, t, mid + 1, right);
}

static void isortVector(std::vector<int> &vec, std::vector< std::pair<int, int> > &pair, size_t n1, size_t n2)
{
	size_t len;
	size_t i;

	len = n1 + 2 * n2;

	if (len == 1)
	{
		vec.push_back(pair[0].second);
		vec.push_back(pair[0].first);
	}
	if (pair.size() > len)
	{
		for (i = n1 + 1; i <= len; i++)
		{
			if (pair[i - 1].first >= 0)
				vec.push_back(pair[i - 1].first);
		}
		for (i = len; i > n1; i--)
			binaryInsertVector(vec, pair[i - 1].second, 0, len + n1 - 2);
		isortVector(vec, pair, len, n1);
	}
	else
	{
		for (i = n1 + 1; i <= pair.size(); i++)
		{
			if (pair[i - 1].first >= 0)
				vec.push_back(pair[i - 1].first);
		}
		for (i = pair.size(); i > n1; i--)
			binaryInsertVector(vec, pair[i - 1].second, 0, pair.size() + n1 - 2);
	}
}

static void sortVector(std::vector<int> &vec)
{
	std::vector< std::pair<int, int> > temp;

	while (vec.size() > 1)
	{
		int a = vec.back();
		vec.pop_back();
		int b = vec.back();
		vec.pop_back();
		temp.push_back(makePair(a, b));
	}
	msortVectorPair(temp, 0, temp.size() - 1);
	if (vec.size() == 1)
	{
		temp.push_back(std::make_pair(-1, vec.back()));
		vec.pop_back();
	}
	isortVector(vec, temp, 1, 0);
}

static void mergeListPair(std::list< std::pair<int, int> > &pair, size_t left, size_t mid, size_t right)
{
	std::list< std::pair<int, int> > temp;
	size_t i = left;
	size_t j = mid + 1;
	size_t t = 0;
	
	while (i <= mid && j <= right)
	{
		if (atList(pair, i)->first <= atList(pair, j)->first)
		{
			temp.push_back(*atList(pair, i++));
			t++;
		}
		else
		{
			temp.push_back(*atList(pair, j++));
			t++;
		}
	}
	while (j <= right)
	{
		temp.push_back(*atList(pair, j++));
		t++;
	}
	while (i <= mid)
	{
		temp.push_back(*atList(pair, i++));
		t++;
	}
	t = 0;
	for (size_t l = left; l <= right; l++)
		*atList(pair, l) = *atList(temp, t++);
}

static void msortListPair(std::list< std::pair<int, int> > &pair, size_t left, size_t right)
{
	size_t mid;

	if (left < right)
	{
		mid = (left + right) / 2;
		msortListPair(pair, left, mid);
		msortListPair(pair, mid + 1, right);
		mergeListPair(pair, left, mid, right);
	}
}

static void binaryInsertList(std::list<int> &list, int t, int left, int right)
{
	size_t mid = (left + right) / 2;

	if (left > right)
	{
		list.insert(atList(list, left), t);
		return ;
	}
	if (t == *atList(list, mid))
		list.insert(atList(list, mid), t);
	else if (t < *atList(list, mid))
		binaryInsertList(list, t, left, mid - 1);
	else
		binaryInsertList(list, t, mid + 1, right);
}

static void isortList(std::list<int> &list, std::list< std::pair<int, int> > &pair, size_t n1, size_t n2)
{
	size_t len;
	size_t i;

	len = n1 + 2 * n2;

	if (len == 1)
	{
		list.push_back(pair.front().second);
		list.push_back(pair.front().first);
	}
	if (pair.size() > len)
	{
		for (i = n1 + 1; i <= len; i++)
		{
			if (atList(pair, i - 1)->first >= 0)
				list.push_back(atList(pair, i - 1)->first);
		}
		for (i = len; i > n1; i--)
			binaryInsertList(list, atList(pair, i - 1)->second, 0, len + n1 - 2);
		isortList(list, pair, len, n1);
	}
	else
	{
		for (i = n1 + 1; i <= pair.size(); i++)
		{
			if (atList(pair, i - 1)->first >= 0)
				list.push_back(atList(pair, i - 1)->first);
		}
		for (i = pair.size(); i > n1; i--)
			binaryInsertList(list, atList(pair, i - 1)->second, 0, len + n1 - 2);
	}
}

static void sortList(std::list<int> &list)
{
	std::list< std::pair<int, int> > temp;

	while (list.size() > 1)
	{
		int a = list.back();
		list.pop_back();
		int b = list.back();
		list.pop_back();
		temp.push_back(makePair(a, b));
	}
	msortListPair(temp, 0, temp.size() - 1);
	if (list.size() == 1)
	{
		temp.push_back(std::make_pair(-1, list.back()));
		list.pop_back();
	}
	isortList(list, temp, 1, 0);
}

static void printVec(std::vector<int> vec, const std::string &str)
{
	std::cout << str;
	if (vec.size() <= 20)
	{
		for (std::vector<int>::iterator itr = vec.begin(); itr != vec.end(); itr++)
		{
			std::cout << *itr;
			if (itr != vec.end() - 1)
				std::cout << " ";
		}
	}
	else
	{
		for (int i = 0; i < 4; i++)
			std::cout << vec[i] << " ";
		std::cout << "[...]";
	}
	std::cout << std::endl;
}

// void printList(std::list<int> list, const std::string &str)
// {
// 	std::cout << str;
// 	if (list.size() <= 20)
// 	{
// 		for (std::list<int>::iterator itr = list.begin(); itr != list.end(); itr++)
// 		{
// 			std::cout << *itr << " ";
// 		}
// 	}
// 	else
// 	{
// 		for (int i = 0; i < 4; i++)
// 			std::cout << *atList(list, i) << " ";
// 		std::cout << "[...]";
// 	}
// 	std::cout << std::endl;
// }

void PmergeMe(int argc, char **argv)
{
	std::vector<int> vec;
	std::list<int> list;
	struct timeval tv;
	std::pair<double, double> tvec;
	std::pair<double, double> tlist;

	try
	{
		isValidArgv(argc, argv, vec, list);
		if (isAlreadySorted(vec))
			return ;

		printVec(vec, "Before:  ");

		gettimeofday(&tv, NULL);
		tvec.first = (tv.tv_sec) * 1000000 + tv.tv_usec;
		sortVector(vec);
		gettimeofday(&tv, NULL);
		tvec.second = (tv.tv_sec) * 1000000 + tv.tv_usec;
	
		gettimeofday(&tv, NULL);
		tlist.first = (tv.tv_sec) * 1000000 + tv.tv_usec;
		sortList(list);
		gettimeofday(&tv, NULL);
		tlist.second = (tv.tv_sec) * 1000000 + tv.tv_usec;

		printVec(vec, "After:   ");
		std::cout << std::fixed << std::setprecision(3);
		std::cout << "Time to process a range of " << argc - 1 << " elements with std::vector : " << (tvec.second - tvec.first) / 1000 << "ms" << std::endl;
		std::cout << "Time to process a range of " << argc - 1 << " elements with std::list   : " << (tlist.second - tlist.first) / 1000 << "ms" << std::endl;
		// printList(list, "After:   ");
	}
	catch(const std::exception& e)
	{
		std::cout << "Error" << std::endl;
	}
	
}