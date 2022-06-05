/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft.h                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yehyun <yehyun@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/04 13:33:27 by yehyun            #+#    #+#             */
/*   Updated: 2022/06/04 22:15:18 by yehyun           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_H
# define FT_H
# define ERROR -1
# define ERR_MSG "Map Error!\n"
# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>

typedef struct s_field
{
	int		dp;
	char	element;
}			t_field;

typedef struct s_charset
{
	char	empty;
	char	obstacle;
	char	fill;
}			t_charset;

int		ft_check_height(int fd, t_charset *mapchar);
int		ft_check_line(int fd, t_charset mapchar, int height, int i);
void	ft_make_map(int fd, char **map, int height, int line);
void	ft_putstr(char *str);
void	into_field(int line, int height, char **arr, t_charset cs);
int		ft_strlen(char *str);
int		ft_atoi(char *str);
int		min(int n1, int n2, int n3);
#endif