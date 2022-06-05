#include <stdio.h>
#include <stdlib.h>

int	ft_strcmp(char *src, char *dest)
{
	int	i;

	i = 0;
	while (src[i])
	{
		if (src[i] > dest[i])
			return (src[i] - dest[i]);
		else if (src[i] < dest[i])
			return (src[i] - dest[i]);
		i++;
	}
	if (!dest[i])
		return (src[i] - dest[i]);
	return (0);
}

void	ft_advanced_sort_string_tab(char **tab, int(*cmp)(char *, char *));
int main()
{
	char **tab;
	tab = (char **)malloc(sizeof(char *) * 10);
	for (int i = 0; i < 5; i ++)
		tab[i] = (char *)malloc(sizeof(char) * 20);
	tab[0] = "HTqQr";
	tab[1] = "IgkqMdjxzpC1";
	tab[2] = "Jk0LFzosVphR";
	tab[3] = "K";
	tab[4] = "LSwVD2TrAin";
	tab[5] = "UXuacowtjk";
	tab[6] = "gRSvP5x8e";
	tab[7] = "p5zc";
	tab[8] = "rJluky916t";
	tab[9] = NULL;
	printf("\n===============EX06===============\n\n");
	int i = 0;
	while (tab[i])	
		printf("%s ", tab[i++]);
	printf("\nvvvvvvv\n");
	ft_advanced_sort_string_tab(tab, ft_strcmp);
	i = 0;
	while (tab[i])	
		printf("%s\n", tab[i++]);

	return 0;
}
