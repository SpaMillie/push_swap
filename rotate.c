/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mspasic <mspasic@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/07 18:13:39 by mspasic           #+#    #+#             */
/*   Updated: 2024/03/07 18:54:53 by mspasic          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	r_stack(int *stack, t_params *params, char c)
{
	int	i;
	int	temp;

	params->counter = 0;
	temp = stack[params->counter];
	if (c == 'a')
		i = params->length_a;
	else
		i = params->length_b;
	while (params->counter < i)
	{
		stack[params->counter] = stack[params->counter + 1];
		params->counter++;
	}
	stack[params->counter] = temp;
}

// void	r_stack(int *stack, int length)
// {
// 	int	i;
// 	int	temp;

// 	i = 0;
// 	temp = stack[i];
// 	while (i < length - 1)
// 	{
// 		printf("stack[i] = %d\n", stack[i]);
// 		stack[i] = stack[i + 1];
// 		printf("stack[i] = %d\n", stack[i]);
// 		i++;
// 	}
// 	stack[i] = temp;
// 	printf("stack[i] = %d\n", stack[i]);
// }