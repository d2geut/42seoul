#include <stdio.h>

char	*ft_strcat(char *dest, char *src);

int	main()
{
	char *src = "QQW";
	char dest[50] = "asdasd";

	ft_strcat(dest,src);

	printf("%s",dest);
	return (0);
}
