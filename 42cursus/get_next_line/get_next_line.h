/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hanryu <hanryu@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/13 10:55:20 by hanryu            #+#    #+#             */
/*   Updated: 2022/07/13 15:01:09 by hanryu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

// # define BUFFER_SIZE 1

# include <unistd.h>
# include <stdlib.h>

typedef struct s_list
{
	int				fd;
	char			buff[BUFFER_SIZE + 1];
	int				index;
	struct s_list	*next;
}	t_list;

char	*get_next_line(int fd);
void	ft_lstadd_back(t_list **lst, t_list *new);
char	*ft_strjoin(char *s1, t_list *now, int size, int flag);

#endif