/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mspasic <mspasic@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/12 17:26:01 by mspasic           #+#    #+#             */
/*   Updated: 2024/03/21 13:44:59 by mspasic          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	check_where_next(t_params *params)
{
	int	i;
	int	j;
	int	num1;
	int	num2;

	i = 0;
	j = 0;
	num1 = params->aux_stack[params->length_aux - params->length_a - 1];
	num2 = params->aux_stack[params->length_aux - params->length_a - 2];
	while (num1 != params->stack_b[i])
		i++;
	while (num2 != params->stack_b[j])
		j++;
	params->master = i;
	params->student = j;
}

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

	while (params->length_b > 0)
	{
		check_where_next(params);
		if (params->master > params->student)
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
