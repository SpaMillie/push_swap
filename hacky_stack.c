/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hacky_stack.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mspasic <mspasic@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/13 15:25:42 by mspasic           #+#    #+#             */
/*   Updated: 2024/03/14 22:25:04 by mspasic          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sixty_smallest(t_params *params)
{
	params->counter = 0;
	while (params->counter < params->length)
	{
		if (params->stack_a[0] < params->aux_stack[60])
		{
			push(params->stack_a, params->stack_b, 'b', params);
			if (params->length_b > 1 && \
			params->stack_b[0] < params->aux_stack[30])
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

void	half_half(int start, int end, int half, t_params *params)
{
	int	half;

	params->counter = 0;
	while (params->counter < end - start)
	{
		if (params->stack_a[0] == params->aux_stack[params->length_aux] ||
		params->stack_a[0] == params->aux_stack[params->length_aux - 1] ||
		params->stack_a[0] == params->aux_stack[params->length_aux - 2])
			params->counter += 0;
		else if (params->stack_a[0] < params->aux_stack[end])
		{
			push(params->stack_a, params->stack_b, 'b', params);
			if (params->stack_b[0] < params->aux_stack[start + half])
				r_stack(params->stack_b, params, 'b');
			else
			{
				if (params->length_b > 1 && \
				params->stack_b[0] < params->stack_b[1])
					swap(params->stack_b, params, params->length_b);
			}
		}
		else
			r_stack(params->stack_a, params, 'a');
		params->counter++;
	}
}

void	hacky_stack(t_params *params)
{
	int	start;
	int	end;

	start = 0;
	end = 0;
	if (params->length > 60)
	{
		sixty_smallest(params);
		params->length -= 60;
		start += 60;
	}
	while (params->length > 120)
	{
		end += 60;
		half_half(start, end, params);
		start += 60;
		params->length -= 60;
	}
	end = params->length_aux;
	half_half(start, end, (end - start) / 2, params);
	if (check_if_sorted(params) == 0)
		return ;
	else if (params->length_a == 3)
		three_nums(params);
}


