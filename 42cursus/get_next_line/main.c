#include <stdio.h>
#include <fcntl.h>
#include "get_next_line.h"

int main()
{
	int		fd = 0;
	char	*str;

	fd = open("test.txt", O_RDONLY);
	while (1)
	{
		printf("****\n");
		str = get_next_line(fd);
		printf("*\n");
		if (str == NULL || str[0] == 0)
			break ;
		printf("%s\n", str);
		free(str);
	}
	close(fd);
	return (0);
}