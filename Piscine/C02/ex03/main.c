#include <unistd.h>
#include <stdio.h>

int	ft_str_is_numeric(char *str);

int	main()
{
	char	arr[10] = "12310321l";

	printf("%d",ft_str_is_numeric(arr));
	return (0);
}
