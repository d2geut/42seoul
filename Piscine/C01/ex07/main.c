#include <unistd.h>
#include <stdio.h>

void	ft_rev_int_tab(int *tab, int size);

int	main()
{
	int	a[11] = {1,2,3,4,5,6,7,8,9,10, 11};
	int i = 11;

	ft_rev_int_tab(a, i);

	for(int k=0; k<11; k++)
	{
		printf("%d ", a[k]);
	}

	return (0);
}
