/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mspasic <mspasic@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/12 17:26:01 by mspasic           #+#    #+#             */
/*   Updated: 2024/03/12 18:32:27 by mspasic          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h> //delete this

int	check_if_sorted(t_params *params)
{
	int	i;

	i = 0;
	while (i < params->length && params->aux_stack[i] == params->stack_a[i])
		i++;
	if (params->length == i)
		return (0);
	else
		return (1);
}

void	three_nums(t_params *params)
{
	if (params->stack_a[1] > params->stack_a[0] && \
		params->stack_a[1] > params->stack_a[2])
	{
		rr_stack(params->stack_a, params, 'a');
		if (check_if_sorted(params) != 0)
			swap(params->stack_a, params, 3);
	}
	else if (params->stack_a[0] > params->stack_a[1] && \
		params->stack_a[0] > params->stack_a[2])
	{
		r_stack(params->stack_a, params, 'a');
		if (check_if_sorted(params) != 0)
			swap(params->stack_a, params, 3);
	}
	else
		swap(params->stack_a, params, 3);
	return ;
}

void	push_swap(t_params *params)
{
	if (check_if_sorted(params) == 0)
		return ;
	if (params->length == 2)
	{
		if (check_if_sorted(params) != 0)
			swap(params->stack_a, params, 2);
		return ;
	}
	else if (params->length == 3)
		three_nums(params);
	else
		printf("not yet\n");
}
