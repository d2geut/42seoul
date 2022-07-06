#include <stdio.h>

char	*ft_strdup(char *src);

int main()
{
	char	*ptr;
	char	src[20] = "123456";

	ptr = ft_strdup(src);

	printf("%s",ptr);
	return 0;
}
