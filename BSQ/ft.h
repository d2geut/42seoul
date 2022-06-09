/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft.h                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yehyun <yehyun@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/04 13:33:27 by yehyun            #+#    #+#             */
/*   Updated: 2022/06/08 13:07:23 by yehyun           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_H
# define FT_H
# define ERROR -1
# define ERR_MSG "map error\n"
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

typedef struct s_maxfield
{
	int	i_max;
	int	j_max;
	int	dp_max;
}			t_maxfield;

int		ft_check_height(int fd, t_charset *mapchar);
int		ft_check_line(int fd, t_charset mapchar, int height, int i);
void	ft_make_map(int fd, int height, int line, char **map);
void	ft_putstr(char *str);
void	into_field(int height, int line, char **arr, t_charset cs);
int		ft_atoi(char *str);
int		min(int n1, int n2, int n3);
#endif
