#include <unistd.h>
#include <stdio.h>

int	ft_str_is_uppercase(char *str);

int	main()
{
	char	arr[10] = "DASaSAD";

	printf("%d",ft_str_is_uppercase(arr));
	return (0);
}
