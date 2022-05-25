#include <stdio.h>
#include <string.h>

int	ft_strlen(char *str);

int	main()
{
	char	str[20] = "asfasdfds3	234sda";

	printf("%ld\n",strlen(str));
	printf("%d",ft_strlen(str));
	return 0;
}
