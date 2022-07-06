#include <unistd.h>
#include <stdio.h>

int	ft_str_is_lowercase(char *str);

int	main()
{
	char	arr[10] = "dsa";

	printf("%d",ft_str_is_lowercase(arr));
	return (0);
}
