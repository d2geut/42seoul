#include <stdio.h>

void	ft_ultimate_div_mod(int *a, int *b);

int main()
{
	int a;
	int b;

	a = 231;
	b = 34;
	ft_ultimate_div_mod(&a, &b);

	printf("%d %d", a, b);
	return (0);
}
