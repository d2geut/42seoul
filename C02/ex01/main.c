#include <unistd.h>
#include <stdio.h>
#include <string.h>

char	*ft_strncpy(char *dest, char *src, unsigned int n);

int	main()
{
	char a[20];
	char b[20] = "Hello";
	char a2[20];

	printf("%s\n",strncpy(a2, b, 7));
	printf("%s",ft_strncpy(a, b, 7));
	return (0);
}
