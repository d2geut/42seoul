/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tailtail.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hanryu <hanryu@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/05 14:22:07 by hanryu            #+#    #+#             */
/*   Updated: 2022/06/07 19:46:25 by hanryu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_tail.h"

void	fd_open(int fd, int size_byte)
{
	char	*buff;
	char	buff_temp;
	ssize_t	size;
	int		i;

	buff = (char *)malloc(sizeof(char) * (size_byte + 1));
	i = 0;
	buff[0] = '\0';
	while (1)
	{
		size = read(fd, &buff_temp, 1);
		if (size <= 0)
			break ;
		if (i < size_byte)
		{
			buff[i++] = buff_temp;
			buff[i] = '\0';
		}
		else
			shift(buff, buff_temp);
	}
	ft_putstr(buff);
	free(buff);
	close(fd);
}

void	argc_4(char *argv, int size_byte)
{
	int	fd;

	fd = open(argv, O_RDONLY);
	if (fd <= 0)
		fd_error(errno, argv);
	else
	{
		if (size_byte == 0)
			return ;
		fd_open(fd, size_byte);
	}
}

void	argc_over4(int i, char **argv, int size_byte)
{
	int	fd;

	fd = open(argv[i], O_RDONLY);
	if (fd <= 0)
		fd_error(errno, argv[i]);
	else
	{
		if (i != 3)
			write(1, "\n", 1);
		write(1, "==> ", 4);
		ft_putstr(argv[i]);
		write(1, " <==\n", 5);
		if (size_byte == 0)
			return ;
		fd_open(fd, size_byte);
	}
}

void	main2(int argc, char **argv)
{
	int		i;
	int		size_byte;

	size_byte = ft_atoi(argv[2]);
	if (argc == 3)
	{
		if (size_byte == 0)
			print_noone();
		else
			print_noav(size_byte);
	}
	else if (argc == 4)
		argc_4(argv[3], size_byte);
	else
	{
		i = 3;
		while (i < argc)
		{
			argc_over4(i, argv, size_byte);
			i++;
		}
	}
}

int	main(int argc, char **argv)
{
	if (argc == 2)
		argu_error();
	else if (argc > 2)
	{
		if (is_byte(argv[2]))
		{
			byte_error(argv[2]);
			return (0);
		}
		main2(argc, argv);
	}
	return (0);
}
