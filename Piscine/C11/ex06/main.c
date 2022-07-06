#include <stdio.h>
#include <stdlib.h>

void	ft_sort_string_tab(char **tab);
int main()
{
	char **tab;
	tab = (char **)malloc(sizeof(char *) * 5);
	for (int i = 0; i < 5; i ++)
		tab[i] = (char *)malloc(sizeof(char) * 10);
	tab[0] = "asdasd";
	tab[1] = "basdad";
	tab[2] = "absd";
	tab[3] = "aeasd";
	tab[4] = NULL;
	printf("\n===============EX06===============\n\n");
	int i = 0;
	while (tab[i])	
		printf("%s ", tab[i++]);
	printf("\nvvvvvvv\n");
	ft_sort_string_tab(tab);
	i = 0;
	while (tab[i])	
		printf("%s ", tab[i++]);

	return 0;
}
