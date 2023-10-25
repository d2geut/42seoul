#include <iostream>
#include <array>

int main()
{
	std::array<int, 3> arr;

	arr[0] = 1;
	arr[1] = 2;
	arr[2] = 3;

	std::cout << arr[UINT_MAX] << std::endl;

	return 0;
}