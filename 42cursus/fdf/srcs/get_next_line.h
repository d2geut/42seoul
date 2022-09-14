/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hanryu <hanryu@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/13 10:55:20 by hanryu            #+#    #+#             */
/*   Updated: 2022/08/30 14:12:49 by hanryu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <unistd.h>
# include <stdlib.h>
# define BUFFER_SIZE 4096

typedef struct s_list
{
	int				fd;
	char			buff[BUFFER_SIZE + 1];
	int				index;
	struct s_list	*next;
}	t_list;

char	*get_next_line(int fd);
void	ft_lstadd_back(t_list **lst, t_list *now);
int		ft_strlen_and(char *str, int flag);
char	*ft_strjoin(char *s1, t_list *now, int size, int flag);
int		check_line(int index, char *str);
char	*free_now(t_list **lst, t_list **now);

#endif