/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_recursive_power.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hanryu <hanryu@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/26 10:26:30 by hanryu            #+#    #+#             */
/*   Updated: 2022/05/28 17:49:38 by hanryu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_recursive_power(int nb, int power)
{
	int	sum;

	sum = 1;
	if (power < 0)
		return (0);
	else if (power == 0)
		return (1);
	else
	{
		sum *= ft_recursive_power(nb, power - 1);
		sum *= nb;
		return (sum);
	}
}
