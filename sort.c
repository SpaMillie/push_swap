/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mspasic <mspasic@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/19 15:15:19 by mspasic           #+#    #+#             */
/*   Updated: 2024/03/19 17:11:34 by mspasic          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	check_where_next(t_params *params)
{
	int	i;
	int	num;

	i = 0;
	num = params->aux_stack[params->length_aux - params->length_a - 1];
	while (num != params->stack_b[i])
		i++;
	return(i);
}


void	sorting_hat(t_params *params)
{	int	index;
	int	num;

	while (params->length_b > 0)
	{
		index = check_where_next(params);
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
}
