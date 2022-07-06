#include <stdio.h>
#include <string.h>

int	ft_strncmp(char *s1, char *s2, unsigned int n);

int	main()
{
	char str1[20] = "asdasdasd";
	char str2[20] = "asdask";
	printf("%d\n",strncmp(str1,str2,6));
	printf("%d",ft_strncmp(str1,str2,6));
	return (0);
}
