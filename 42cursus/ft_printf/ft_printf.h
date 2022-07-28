/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hanryu <hanryu@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/11 09:56:38 by hanryu            #+#    #+#             */
/*   Updated: 2022/07/18 09:46:51 by hanryu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>
# include "libft.h"

int	ft_printf(const char *format, ...);
int	print_char(va_list ap);
int	print_str(va_list ap);
int	print_nbr(va_list ap);
int	print_unbr(va_list ap);
int	print_hexa(va_list ap, int flag);
int	print_memory(va_list ap);

#endif