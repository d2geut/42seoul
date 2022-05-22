#include <unistd.h>

void	ft_swap(int *a, int *b);

int	main()
{
	int	a;
	int	b;
	char c[2];

	a = 2;
	b = 4;
	ft_swap(&a, &b);
	c[0] = a + 48;
	c[1] = b + 48;
	write(1, &c[0], 1);
	write(1, "\n", 1);
	write(1, &c[1], 1);
	return (0);
}
