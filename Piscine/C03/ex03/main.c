#include <stdio.h>

char	*ft_strncat(char *dest, char *src, unsigned int nb);

int main()
{
	char *src = "QQWQQW";
	char dest[50] = "asdasd";

	ft_strncat(dest,src,6);

	printf("%s",dest);
	return (0);
}
