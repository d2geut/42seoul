#include <stdio.h>
#include <string.h>

void	ft_putstr_non_printable(char *str);

int	main()
{
	printf("======ex11======\n");
	char str[10] = "abcdef ? ";
	char str1[30] = "Coucou\ntu \nvas bien ?";
	ft_putstr_non_printable(str);
	printf("\n");
	ft_putstr_non_printable(str1);
	printf("\n");
	return 0;
}
