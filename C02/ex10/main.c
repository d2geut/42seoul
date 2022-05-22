#include <stdio.h>

unsigned int	ft_strlcpy(char *dest, char *src, unsigned int size);

int	main()
{
	char	*src = "123456";
	char	dest[20];

	int	ret = ft_strlcpy(dest,src,7);
	printf("%s\n%d", dest, ret);
	return (0);
}
