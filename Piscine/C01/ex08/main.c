#include <stdio.h>

void	ft_sort_int_tab(int *tab, int size);
	
int main()
{
	int acc[13] = {3,6,1,8,66,32,12,86,5,34,65,23,55};

	ft_sort_int_tab(acc, 13);

	for(int i=0; i<13; i++)
	{
		printf("%d ", acc[i]);
	}
}
