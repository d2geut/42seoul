#include <stdio.h>
#include <string.h>

unsigned int	ft_strlcat(char *dest, char *src, unsigned int size);

int main()
{
	char	dest1[30] = "12";
	char	dest2[30] = "12";
	char	str[30] = "456\022";
	unsigned int ret;

	ret = strlcat(dest1, str, 30);
	printf("%s %d\n",dest1,ret);
	ret = ft_strlcat(dest2, str, 75);
	printf("%s %d",dest2,ret);
	return 0;
}
