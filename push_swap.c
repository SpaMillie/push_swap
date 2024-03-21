/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mspasic <mspasic@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/12 17:26:01 by mspasic           #+#    #+#             */
/*   Updated: 2024/03/21 15:29:42 by mspasic          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	training_montage(t_params *params, int index)
{
	int	num;

	num = params->stack_b[index];
	if (index < params->length_b / 2)
	{
		while (params->stack_b[0] != num)
			r_stack(params->stack_b, params, 'b');
		push(params->stack_a, params->stack_b, 'a', params);
	}
	else
	{
		while (params->stack_b[0] != num)
			rr_stack(params->stack_b, params, 'b');
		push(params->stack_a, params->stack_b, 'a', params);
	}
}

void	sorting_hat(t_params *params)
{
	int	i;

	while (params->length_b > 1)
	{
		if (check_where_next(params) == 1)
		{
			i = 0;
			params->master = params->stack_b[params->master];
			training_montage(params, params->student);
			while (params->master != params->stack_b[i])
				i++;
			training_montage(params, i);
			swap(params->stack_a, params->length_a, 'a');
		}
		else
			training_montage(params, params->master);
	}
	if (params->length_b == 1)
		push(params->stack_a, params->stack_b, 'a', params);
}

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
	if (params->length_aux == 2)
	{
		swap(params->stack_a, 2, 'a');
		return ;
	}
	else if (params->length_aux == 3)
		three_nums(params, 0);
	else
		hacky_stack(params);
	sorting_hat(params);
}
