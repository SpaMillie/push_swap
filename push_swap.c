/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mspasic <mspasic@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/12 17:26:01 by mspasic           #+#    #+#             */
/*   Updated: 2024/03/19 15:28:34 by mspasic          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// int	find_the_big(t_params *params, int *stack, int length)
// {
// 	int	i;

// 	i = stack[0];
// 	params->counter = 1;
// 	while (params->counter < length)
// 	{
// 		if (i < stack[params->counter])
// 		{
// 			i = stack[params->counter];
// 			params->counter++;
// 		}
// 		else
// 			params->counter++;
// 	}
// 	params->counter = 0;
// 	while (stack[params->counter] != i)
// 		params->counter++;
// 	return (params->counter);
// }

void	three_nums(t_params *params, int option)
{
	if (params->stack_a[1] > params->stack_a[0] && \
		params->stack_a[1] > params->stack_a[2])
	{
		rr_stack(params->stack_a, params, 'a');
		if (check_if_sorted(params, option) != 0)
			swap(params->stack_a, 3, 'a');
	}
	else if (params->stack_a[0] > params->stack_a[1] && \
		params->stack_a[0] > params->stack_a[2])
	{
		r_stack(params->stack_a, params, 'a');
		if (check_if_sorted(params, option) != 0)
			swap(params->stack_a, 3, 'a');
	}
	else
		swap(params->stack_a, 3, 'a');
	return ;
}

void	push_swap(t_params *params)
{
	if (check_if_sorted_all(params) == 0)
		return ;
	if (params->length == 2)
	{
		swap(params->stack_a, 2, 'a');
		return ;
	}
	else if (params->length == 3)
		three_nums(params, 0);
	else
		hacky_stack(params);
}
