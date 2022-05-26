#include <stdio.h>

int	ft_fibonacci(int index);

int main()
{
	int i = 20;
	while (--i)
	{
		printf("%d ",ft_fibonacci(i));
	}
	printf("\n");
	printf("%d",ft_fibonacci(-1));
	return (0);
}
