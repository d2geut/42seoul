#include <stdio.h>

char	**ft_split(char *str, char *charset);

int main()
{
	char charset[10] = "2RUjz";
	char str[100] = "JOCdSv8Sub19Cn71qZjgTzVOwHPG3C07Y";
	char **strs = ft_split(str, charset);
	int i = 0;
	while (strs[i])
	{
		printf("%s\n", strs[i]);
		i++;
	}
}
