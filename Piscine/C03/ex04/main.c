#include <stdio.h>
#include <string.h>

char	*ft_strstr(char *str, char *to_find);

int main()
{
	char *str = "A Garden Diary A Garden Diary A Garden Diary";

	char *ptr = ft_strstr(str,"den");
	while (ptr != NULL)
	{
		printf("%s\n",ptr);
		ptr = strstr(ptr + 1, "den");
	}
	return 0;
}
