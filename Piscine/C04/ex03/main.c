#include <stdio.h>

int	ft_atoi(char *str);

int main()
{
	char str[30] = "  \n\v\t\f\r-+--+-12312321a4as";

	printf("%d\n",ft_atoi(str));
	return 0;
}
