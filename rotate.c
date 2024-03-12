/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mspasic <mspasic@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/07 18:13:39 by mspasic           #+#    #+#             */
/*   Updated: 2024/03/12 14:58:14 by mspasic          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	r_stack(int *stack, t_params *params, char c)
{
	int	i;
	int	temp;

	params->counter = 0;
	temp = stack[params->counter];
	if (c == 'a')
		i = params->length_a;
	else
		i = params->length_b;
	while (params->counter < i - 1)
	{
		stack[params->counter] = stack[params->counter + 1];
		params->counter++;
	}
	stack[params->counter] = temp;
	if (c == 'a')
	{
		write (1, "ra", 3);
		write (1, "\n", 1);
	}
	else if (c == 'b')
	{
		write(1, "rb", 3);
		write (1, "\n", 1);
	}
}

void	r_both(int *a, int *b, t_params *params)
{
	r_stack(a, params, 'a');
	r_stack(b, params, 'b');
	write (1, "rr", 3);
	write (1, "\n", 1);
}

void	rr_stack(int *stack, t_params *params, char c)
{
	int	temp;

	if (c == 'a')
		params->counter = params->length_a - 1;
	else
		params->counter = params->length_b - 1;
	temp = stack[params->counter];
	while (params->counter > 0)
	{
		stack[params->counter] = stack[params->counter - 1];
		params->counter--;
	}
	stack[params->counter] = temp;
	if (c == 'a')
	{
		write (1, "rra", 4);
		write (1, "\n", 1);
	}
	else if (c == 'b')
	{
		write(1, "rrb", 4);
		write (1, "\n", 1);
	}
}

void	rr_both(int *a, int *b, t_params *params)
{
	rr_stack(a, params, 'a');
	rr_stack(b, params, 'b');
	write (1, "rrr", 4);
	write (1, "\n", 1);
}

