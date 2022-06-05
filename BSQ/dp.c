#include <unistd.h>
#include <fcntl.h>
#include "ft.h"

void	dynamic(t_field (*str)[28], int height);

int	main(int argc, char **argv)
{
	int	i;
	int	j;
	ssize_t rdsize;
	char	buff;
	int	fd;
	t_field	str[10][28];

	fd = open(argv[argc - 1], O_RDONLY);
	i = 0;
	while (i < 9)
	{
		j = 0;
		while (j < 28)
		{
			rdsize = read(fd, &buff, 1);
			str[i][j].element = buff;
			if (j == 27)
				str[i][j].element = '\0';
			j++;
		}
		i++;
	}
	close(fd);

	i = 0;
	while (i < 9)
	{
		j = 0;
		while (j < 27)
		{
			if (str[i][j].element == 'o')
				str[i][j].dp = 0;
			else if (str[i][j].element == '.')
				str[i][j].dp = 1;
			j++;
		}
		i++;
	}

	dynamic(str, 9);

	int	i_max;
	int	j_max;
	int	num_max = 0;
	i = 0;
	while (i < 9)
	{
		j = 0;
		while (j < 27)
		{
			if (num_max < str[i][j].dp)
			{
				i_max = i;
				j_max = j;
				num_max = str[i][j].dp;
			}
			j++;
		}
		i++;
	}
	int i_index = i_max - num_max + 1;
	int j_index;
	while (i_index <= i_max)
	{
		j_index = j_max - num_max + 1;
		while (j_index <= j_max)
		{
			str[i_index][j_index].element = 'x';
			j_index++;
		}
		i_index++;
	}
	i = 0;
	while (i < 9)
	{
		j = 0;
		while (j < 28)
		{
			write(1, &str[i][j].element, 1);
			j++;
		}
		write(1, "\n", 1);
		i++;
	}
	return (0);
}
