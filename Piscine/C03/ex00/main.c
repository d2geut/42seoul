#include <stdio.h>
#include <string.h>

int	ft_strcmp(char *s1, char *s2);

int	main()
{
	char str1[20] = "123456aa";
	char str2[20] = "123456aa";
	printf("%d\n",strcmp(str1,str2));
	printf("%d",ft_strcmp(str1,str2));
	return (0);
}
