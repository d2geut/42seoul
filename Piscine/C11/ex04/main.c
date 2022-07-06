#include <stdio.h>

int	ft_is_sort(int *tab, int length, int (*f)(int, int));
int	comp(int n, int m)
{
	return (n - m);
}
int main()
{
	printf("\n===============EX04===============\n\n");
	int tab2[6] = {1, 2, 3, 4, 5, 6};
	printf("1 2 3 4 5 6\n");
	if (ft_is_sort(tab2, 6, &comp))
		printf("OK : OK\n\n");
	else
		printf("OK : KO\n\n");
	int tab3[6] = {1, 3, 2, 4, 6, 5};
	printf("1 3 2 4 6 5\n");
	if (ft_is_sort(tab3, 6, &comp))
		printf("KO : OK\n\n");
	else
		printf("KO : KO\n\n");
	printf("6 5 4 3 2 1\n");
	int tab4[6] = {6, 5, 4, 3, 2, 1};
	if (ft_is_sort(tab4, 6, &comp))
		printf("OK : OK\n");
	else
		printf("OK : KO\n");
	int tab5[1] = {0};
	printf("0\n");
	if (ft_is_sort(tab5, 0, &comp))
		printf("OK : OK\n");
	else
		printf("OK : KO\n");
}
