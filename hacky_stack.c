/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hacky_stack.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mspasic <mspasic@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/13 15:25:42 by mspasic           #+#    #+#             */
/*   Updated: 2024/03/15 21:23:11 by mspasic          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

void	sixty_smallest(t_params *params)
{
	int	i;

	i = params->length_aux - (params->length_aux - params->length_a);
	params->counter = 0;
	while (params->counter < 60)
	{
		if (params->stack_a[0] < params->aux_stack[i + 60])
		{
			push(params->stack_a, params->stack_b, 'b', params);
			if (params->length_b > 1 && \
			params->stack_b[0] < params->aux_stack[i + 30])
				r_stack(params->stack_b, params, 'b');
			else if (params->length_b > 1 && \
			params->stack_b[0] < params->stack_b[1])
				swap(params->stack_b, params, params->length_b);
		}
		else
			r_stack(params->stack_a, params, 'a');
		params->counter++;
	}
}

void	half_half(t_params *params)
{
	int	i;
	
	i = params->length_aux - (params->length_aux - params->length_a);
	params->counter = 0;
	while (params->counter < i + (params->length_a / 2))
	{
		if (params->stack_a[0] < params->aux_stack[i + (params->length_a / 2)])
		{
			push(params->stack_a, params->stack_b, 'b', params);
			if (params->length_b > 1 && \
			params->stack_b[0] < params->aux_stack[i + ((params->length_a / 2) / 2)])
				r_stack(params->stack_b, params, 'b');
			else if (params->length_b > 1 && \
			params->stack_b[0] < params->stack_b[1])
				swap(params->stack_b, params, params->length_b);
		}
		else
			r_stack(params->stack_a, params, 'a');
		params->counter++;
	}
}

void	hacky_stack(t_params *params)
{
	while (params->length_a > 120)
		sixty_smallest(params);
	while (params->length_a > 3)
		half_half(params);
	if (check_if_sorted(params) == 0)
		return ;
	if (params->length_a == 2)
	{
		swap(params->stack_a, params, 2);
		return ;
	}
	else if (params->length_a == 3)
		three_nums(params);

	int i = 0;
	while (params->stack_a[i] < params->length_a)
	{
		printf("A[%d] je %d\n", i, params->stack_a[i]);
		i++;
	}
	i = 0;
	while (params->stack_b[i] < params->length_b)
	{
		printf("B[%d] je %d\n", i, params->stack_b[i]);
		i++;
	}
}


