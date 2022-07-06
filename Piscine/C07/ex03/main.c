#include <stdio.h>
#include <stdlib.h>

char	*ft_strjoin(int size, char **strs, char *sep);

int main()
{
	char	*arr;
	char	**strs;
	char	*sep = "||";

	strs = (char **)malloc(sizeof(char *)*100);
	for (int i = 0; i < 20; i++)
	{
		strs[i] = (char *)malloc(sizeof(char) * 5);
		for (int j = 0; j < 5; j++)
			strs[i][j] = i + j + 48;
	}

	arr = ft_strjoin(20, strs, sep);

	printf("%s",arr);
	return 0;
}
