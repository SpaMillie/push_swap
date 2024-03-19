/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checking_if_sorted.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mspasic <mspasic@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/19 12:58:59 by mspasic           #+#    #+#             */
/*   Updated: 2024/03/19 16:00:01 by mspasic          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	check_if_sorted_big(t_params *params)
{
	int	i;
	int	j;

	i = params->length_aux - 1;
	j = params->length_a - 1;
	while (j != -1)
	{
		if (params->stack_a[j] == params->aux_stack[i])
		{
			i--;
			j--;
		}
		else
			return (1);
	}
	return (0);
}

int	check_if_sorted_all(t_params *params)
{
	int	i;

	i = 0;
	while (i < params->length_aux && params->aux_stack[i] == params->stack_a[i])
		i++;
	if (params->length_aux == i)
		return (0);
	else
		return (1);
}

int	check_if_sorted(t_params *params, int option)
{
	int	i;

	i = 0;
	if (option == 0)
		i = check_if_sorted_all(params);
	else
		i = check_if_sorted_big(params);
	if (i == 0)
		return (0);
	else
		return (1);
}

