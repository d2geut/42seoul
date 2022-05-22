#include <unistd.h>
#include <stdio.h>

int	ft_str_is_printable(char *str);

int	main()
{
	char	arr[10] = "";

	printf("%d",ft_str_is_printable(arr));
	return (0);
}
