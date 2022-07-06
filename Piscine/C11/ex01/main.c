#include <stdio.h>

int	*ft_map(int *tab, int length, int (*f)(int));
int	add(int	n)
{
	return (n + 1);
}
int main()
{
		printf("\n\n===============EX01===============\n\n");
		int	tab[11] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
		int	*result = ft_map(tab, 10, &add);
		printf("12345678910\n");
		for (int i = 0; i < 10; i ++)
			printf("%d", *(result + i));
		return 0;
}
