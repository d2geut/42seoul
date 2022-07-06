#include <stdio.h>

char	*ft_convert_base(char *nbr, char *base_from, char *base_to);

int main()
{
	char str[30] = "---00000";
	char *arr;

	arr = ft_convert_base(str, "0123456789", "k123456789abcdef");

	printf("%s\n",arr);
}
