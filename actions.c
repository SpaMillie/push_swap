/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mspasic <mspasic@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/06 17:35:32 by mspasic           #+#    #+#             */
/*   Updated: 2024/03/06 18:10:37 by mspasic          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap(int *stack, t_params *params, int length)
{
	int	temp;

	temp = stack[0];
	stack[0] = stack[1];
	stack[1] = temp;
	if (length <= 1)
		return ;
	if (params->stack == 'b')
	{
		write(1, "sb", 3);
		write(1, '\n', 1);
	}
	else if (params->stack == 'a')
	{
		write(1, "sa", 3);
		write(1, '\n', 1);
	}
}

void	swap_both(int *a, int *b, t_params *params)
{
	swap(a, params, params->length_a);
	swap(b, params, params->length_b);
	write(1, "ss", 3);
	write(1, '\n', 1);
}


