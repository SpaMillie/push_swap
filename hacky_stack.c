/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hacky_stack.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mspasic <mspasic@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/13 15:25:42 by mspasic           #+#    #+#             */
/*   Updated: 2024/03/21 19:48:53 by mspasic          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sixty_smallest(t_params *params)
{
	int	i;
	int	length;

	length = params->length_aux - params->length_a;
	i = 0;
	while (i < 60)
	{
		if (params->stack_a[0] < params->aux_stack[length + 60])
		{
			push(params->stack_a, params->stack_b, 'b', params);
			if (params->length_b > 1 && \
			params->stack_b[0] < params->aux_stack[length + 30])
				r_stack(params->stack_b, params, 'b');
			else if (params->length_b > 1 && \
			params->stack_b[0] < params->stack_b[1])
				swap(params->stack_b, params->length_b, 'b');
			i++;
		}
		else
			r_stack(params->stack_a, params, 'a');
	}
}

void	half_half(t_params *params)
{
	int	i;
	int	length;
	int	counter;

	counter = params->length_a / 2;
	length = params->length_a / 2 + (params->length_aux - params->length_a);
	i = params->length_a;
	while (i > 0)
	{
		if (params->stack_a[0] < params->aux_stack[length])
		{
			push(params->stack_a, params->stack_b, 'b', params);
			if (params->length_b > 1 && \
			params->stack_b[0] < \
			params->aux_stack[length / 2])
				r_stack(params->stack_b, params, 'b');
			else if (params->length_b > 1 && \
			params->stack_b[0] < params->stack_b[1])
				swap(params->stack_b, params->length_b, 'b');
			counter--;
		}
		else if (counter > 0)
			r_stack(params->stack_a, params, 'a');
		i--;
	}
}

void	hacky_stack(t_params *params)
{
	while (params->length_a > 120)
		sixty_smallest(params);
	while (params->length_a > 3)
		half_half(params);
	if (check_if_sorted_big(params) == 0)
		return ;
	else if (params->length_a == 2)
		swap(params->stack_a, 2, 'a');
	else if (params->length_a == 3)
		three_nums(params, 1);
}
