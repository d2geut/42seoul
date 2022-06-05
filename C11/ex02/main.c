#include <stdio.h>
#include <stdlib.h>

int	ft_any(char **tab, int (*f)(char *));
int	fff(char *str)
{
	if (*(str) > 95)
		return (1);
	else
		return (0);
}
int main()	
{
	printf("\n\n===============EX02===============\n\n");
	char **tab;
	tab = (char **)malloc(sizeof(char *) * 5);
	for (int i = 0; i < 5; i ++)
		*(tab + i) = (char *)malloc(sizeof(char) * 4);
	*(*(tab)) = 'A';
	*(*(tab + 1)) = 'B';
	*(*(tab + 2)) = 'C';
	*(*(tab + 3)) = 'D';
	*(tab + 4) = 0;
	printf("0 : %d\n", ft_any(tab, &fff)); 
	*(*(tab + 2)) = 'c';
	printf("1 : %d\n", ft_any(tab, &fff)); 
}
