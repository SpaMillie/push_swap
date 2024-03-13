/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hacky_stack.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mspasic <mspasic@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/13 15:25:42 by mspasic           #+#    #+#             */
/*   Updated: 2024/03/13 17:56:06 by mspasic          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	check_if_fits(int start, int end, t_params *params, int index)
{
	while (start < end)
	{
		if (params->stack_a[index] == params->aux_stack[start])
			return (0);
		else
			start++;
	}
	return (1);
}

void	sixty_smallest(t_params *params)
{
	params->counter = 0;
	while (params->counter < params->length)
	{
		if (check_if_fits(0, 60, params, params->counter) == 0)
		{
			push(params->stack_a, params->stack_b, 'b', params);
			if (params->length_b > 1 && \
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
	end = 60;
	while (params->length > 60)
	{
		if (params->length > 60 && start == 0)
		{
			sixty_smallest(params);
			params->length -= 60;
		}

	}

}



void	more_than_sixty(t_params *params)
{
	int	start;
	int	end;

	start = 0;
	end = 60;
	while (params->length > 60)
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

