#include <stdlib.h>
#include <stdio.h>

int	ft_count_if(char **tab, int length, int (*f)(char *));
int	fff(char *str)
{
	if (*(str) > 95)
		return (1);
	else
		return (0);
}
int main()
{
	char **tab;
	tab = (char **)malloc(sizeof(char *) * 5);
	for (int i = 0; i < 5; i ++)
		*(tab + i) = (char *)malloc(sizeof(char) * 4);
	*(*(tab)) = 'A';
	*(*(tab + 1)) = 'B';
	*(*(tab + 2)) = 'C';
	*(*(tab + 3)) = 'D';
	*(tab + 4) = 0;
	*(*(tab + 2)) = 'c';
	printf("1 : %d\n", ft_count_if(tab, 4, &fff));
	*(*(tab + 1)) = 'b';
	*(*(tab + 3)) = 'd';
	printf("3 : %d\n", ft_count_if(tab, 4, &fff));
}
