/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_bonus.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hanryu <hanryu@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/22 09:26:36 by hanryu            #+#    #+#             */
/*   Updated: 2022/10/17 15:20:58 by hanryu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_BONUS_H
# define PUSH_SWAP_BONUS_H

# include "libft.h"
# include <unistd.h>
# include <stdlib.h>
# include <limits.h>

typedef struct s_stack
{
	int				number;
	struct s_stack	*next;
}	t_stack;

typedef struct s_data
{
	t_stack	*top_a;
	t_stack	*top_b;
	int		num_a;
	int		num_b;
}	t_data;

int		ft_lstadd_back_stack(t_stack **lst, t_stack *new);
void	ft_lstadd_front_stack(t_stack **lst, t_stack *new);
void	ft_lstclear_stack(t_stack **lst);
t_stack	*ft_lstlast_stack(t_stack *lst);
t_stack	*ft_lstnew_stack(int num);
int		ft_lstsize_stack(t_stack *lst);
void	ft_free(void **ptr);
void	ft_2darray_free(char ***arr);
void	write_error(void);
void	swap_a(t_data *data);
void	swap_b(t_data *data);
void	swap_s(t_data *data);
void	push_a(t_data *data);
void	push_b(t_data *data);
void	rotate_a(t_data *data);
void	rotate_b(t_data *data);
void	rotate_r(t_data *data);
void	r_rotate_a(t_data *data);
void	r_rotate_b(t_data *data);
void	r_rotate_r(t_data *data);
void	enter_command(t_data *data);
char	*get_next_line(int fd);

#endif