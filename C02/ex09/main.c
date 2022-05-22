#include <stdio.h>

char	*ft_strcapitalize(char *str);

int main()
{
	char	arr[70] = "salut, commEnt TU vAs ? 42Mots quArante-deux; cinquante+et+un";

	printf("%s",ft_strcapitalize(arr));
	return (0);
}
