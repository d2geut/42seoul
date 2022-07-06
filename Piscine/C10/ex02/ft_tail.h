/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tail.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hanryu <hanryu@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/05 14:22:54 by hanryu            #+#    #+#             */
/*   Updated: 2022/06/07 20:26:23 by hanryu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_TAIL_H
# define FT_TAIL_H

# include <unistd.h>
# include <fcntl.h>
# include <errno.h>
# include <string.h>
# include <stdlib.h>

void	ft_putstr(char *str);
char	is_byte(char *str);
void	byte_error(char *str);
void	argu_error(void);
void	fd_error(int err, char *str);
int		ft_atoi(char *str);
int		is_space(char c);
void	ft_putstr(char *str);
int		ft_strlen(char *str);
void	shift(char *buff, char buff_temp);
void	print_noav(int size_byte);
void	print_noone(void);

#endif
