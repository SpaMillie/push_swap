/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_and_push.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mspasic <mspasic@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/06 17:35:32 by mspasic           #+#    #+#             */
/*   Updated: 2024/03/13 16:05:54 by mspasic          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap(int *stack, t_params *params, int length)
{
	int	temp;

	temp = stack[0];
	stack[0] = stack[1];
	stack[1] = temp;
	if (length <= 1)
		return ;
	if (params->stack == 'b')
	{
		write(1, "sb", 3);
		write(1, "\n", 1);
	}
	else if (params->stack == 'a')
	{
		write(1, "sa", 3);
		write(1, "\n", 1);
	}
}

void	swap_both(int *a, int *b, t_params *params)
{
	swap(a, params, params->length_a);
	swap(b, params, params->length_b);
	write(1, "ss", 3);
	write(1, "\n", 1);
}

void	push_to(int temp, int *stack, int length)
{
	while (length > 0)
	{
		stack[length] = stack[length - 1];
		length--;
	}
	stack[length] = temp;
}

void	push_from(int *stack, t_params *params, int length)
{
	params->counter = 0;
	while (params->counter < length)
	{
		stack[params->counter] = stack[params->counter + 1];
		params->counter++;
	}
}

void	push(int *stack_a, int *stack_b, char c, t_params *params)
{
	if (c == 'a')
	{
		if (stack_b == NULL)
			return ;
		params->length_a = params->length_a + 1;
		params->length_b = params->length_b - 1;
		push_to(stack_b[0], stack_a, params->length_a);
		push_from(stack_b, params, params->length_b);
		write(1, "pa", 3);
		write(1, "\n", 1);
	}
	else
	{
		if (stack_a == NULL)
			return ;
		params->length_b = params->length_b + 1;
		params->length_a = params->length_a - 1;
		push_to(stack_a[0], stack_b, params->length_b);
		push_from(stack_a, params, params->length_a);
		write(1, "pb", 3);
		write(1, "\n", 1);
	}
}
