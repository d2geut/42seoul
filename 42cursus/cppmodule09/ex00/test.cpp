#include <iostream>
#include <string>
#include <map>

int main()
{
	std::map<std::string, int> m;
	std::map<std::string, int>::iterator itr;

	m["2020-01-01"] = 1;
	m["2020-03-01"] = 2;
	m["2020-02-01"] = 3;
	m["2020-05-01"] = 4;
	m["2020-04-01"] = 5;

	itr = m.lower_bound("2020-03-20");
	std::cout << itr->first << " " << itr->second << std::endl;

	return (0);
}