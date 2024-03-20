/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_aux.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mspasic <mspasic@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/12 13:49:11 by mspasic           #+#    #+#             */
/*   Updated: 2024/03/20 13:19:19 by mspasic          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	add_number(t_params *params, int num, int start, int end)
{
	while (start < end)
	{
		params->aux_stack[end] = params->aux_stack[end - 1];
		end--;
	}
	params->aux_stack[start] = num;
}

int	sort_aux(t_params *params, int length)
{
	int	i;

	params->counter = 0;
	params->length_aux = 0;
	params->aux_stack[params->counter] = params->stack_a[params->counter];
	params->counter++;
	params->length_aux++;
	while (params->length_aux < length)
	{
		i = 0;
		while (i < params->length_aux)
		{
			if (params->aux_stack[i] == params->stack_a[params->counter])
				return (duplicate_found(params));
			else if (params->aux_stack[i] < params->stack_a[params->counter])
				i++;
			else
				break ;
		}
		add_number(params, params->stack_a[params->counter], \
					i, params->length_aux);
		params->counter++;
		params->length_aux++;
	}
	return (0);
}
