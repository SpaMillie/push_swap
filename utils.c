/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mspasic <mspasic@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/21 14:54:29 by mspasic           #+#    #+#             */
/*   Updated: 2024/03/21 15:20:20 by mspasic          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	calculate_cost(t_params *params, int index)
{
	int	cost;

	if (index < params->length_b / 2)
		cost = index;
	else
		cost = params->length_b - index;
	return (cost);
}

int	check_where_next(t_params *params)
{
	int	i;
	int	j;
	int	num1;
	int	num2;
	int cost;

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
	num1 = calculate_cost(params, i);
	num2 = calculate_cost(params, j);
	if (num1 > num2)
		cost = 1;
	else
		cost = 0;
	return (cost);
}
