#include <stdio.h>

int	ft_atoi_base(char *str, char *base);

int	main()
{
	char str[30] = "  \n\v\t\f\r-+--+-asdfaddfgas";

	printf("%d\n",ft_atoi_base(str, "asdf"));
}
