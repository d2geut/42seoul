/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printcontents.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hanryu <hanryu@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/02 14:36:01 by hanryu            #+#    #+#             */
/*   Updated: 2022/06/02 18:35:53 by hanryu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <fcntl.h>

void	write_rdcont(int fd)
{
	char	buff;
	ssize_t	rdsize;

	while (1)
	{
		rdsize = read(fd, &buff, 1);
		if (0 < rdsize)
			write(1, &buff, 1);
		else
			break ;
	}
	close(fd);
}

int	main(int argc, char **argv)
{
	int	fd;

	if (argc < 2)
		write(2, "File name missing.\n", 19);
	else if (argc > 2)
		write(2, "Too many arguments.\n", 20);
	else
	{
		fd = open(argv[1], O_RDONLY);
		if (fd >= 0)
			write_rdcont(fd);
		else
			write(2, "Cannot read file.\n", 18);
	}
	return (0);
}
