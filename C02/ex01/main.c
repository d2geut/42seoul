#include <unistd.h>
#include <stdio.h>

char	*ft_strncpy(char *dest, char *src, unsigned int n);

int	main()
{
	char a[20] = "asdassdasdsads";
	char b[20] = "Helloworld";

	printf("%s",ft_strncpy(a, b, 4));
	return (0);
}
