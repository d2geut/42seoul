#include <unistd.h>
#include <stdio.h>

char	*ft_strcpy(char *dest, char *src);

int main()
{
	char a[20] = "asdassdasdsads";
	char b[20] = "Helloworld";

	printf("%s",ft_strcpy(a, b));
	return (0);
}
