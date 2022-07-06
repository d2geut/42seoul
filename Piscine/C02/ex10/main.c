#include <stdio.h>
#include <string.h>

unsigned int	ft_strlcpy(char *dest, char *src, unsigned int size);

int	main()
{
	char	*src = "abcd";
	char	dest[10] = "0";
	char	dest1[10] = "0";

	int	ret = ft_strlcpy(dest, src, 4);
	int ret1 = strlcpy(dest1, src, 4);
	printf("%s %d\n", dest1, ret1);
	printf("%s %d", dest, ret);
	return (0);
}
