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

// int	check_if_fits(int start, int end, t_params *params, int index)
// {
// 	while (start < end)
// 	{
// 		if (params->stack_a[index] < params->aux_stack[end])
// 			return (0);
// 		else
// 			start++;
// 	}
// 	return (1);
// }

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

void	hacky_stack(t_params *params)
{
	int	start;
	int	end;

	start = 0;
	end = 0;
	// if (params->length > 60)
	// 	end = 60;
	// else
	// 	end = params->length;
	while (params->length > 120)
	{
		end += 60;
		if (start == 0)
			sixty_smallest(params);
		else
			half_half(start, end, params);
		start += 60;
		params->length -= 60;
	}

}

void	half_half(int start, int end, t_params *params)
{
	int	half;

	half = (end - start) / 2;
	params->counter = 0;
	while (params->counter < end - start)
	{
		if (params->stack_a[0] < params->aux_stack[end])
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

void	more_than_sixty(t_params *params)
{
	int	start;
	int	end;

	start = 0;
	end = 60;
	while (params->length > 120)
	{
		params->counter = 0;
		while (params->counter < params->length)
		{
			if (check_if_fits(start, end, params, params->counter) == 0)
			{
				push(params->stack_a, params->stack_b, 'b', params);
				if (params->stack_b[0] < params->stack_b[1])
					swap(params->stack_b, params, params->length_b);
			}
			else
				r_stack(params->stack_a, params, 'a');
			params->counter++;
		}
		start += 60;
		end += 60;
		params->length -+ 60;
	}
}

