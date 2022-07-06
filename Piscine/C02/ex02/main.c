#include <unistd.h>
#include <stdio.h>

int	ft_str_is_alpha(char *str);

int	main()
{
	char	arr[10] = "aAd'";

	printf("%d",ft_str_is_alpha(arr));
	return (0);
}
