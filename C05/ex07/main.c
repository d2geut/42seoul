#include <stdio.h>

int	ft_find_next_prime(int nb);

int main()
{
	int i = 0;

	while (i < 101)
	{
		printf("%d ",ft_find_next_prime(i));
		i++;
	}
	return 0;
}
