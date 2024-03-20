/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_and_push.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mspasic <mspasic@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/06 17:35:32 by mspasic           #+#    #+#             */
/*   Updated: 2024/03/20 14:42:47 by mspasic          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap(int *stack, int length, char c)
{
	int	temp;

	temp = stack[0];
	stack[0] = stack[1];
	stack[1] = temp;
	if (length <= 1)
		return ;
	if (c == 'b')
	{
		write(1, "sb", 2);
		write(1, "\n", 1);
	}
	else if (c == 'a')
	{
		write(1, "sa", 2);
		write(1, "\n", 1);
	}
}

void	swap_both(int *a, int *b, t_params *params)
{
	swap(a, params->length_a, 'c');
	swap(b, params->length_b, 'c');
	write(1, "ss", 2);
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

void	push_from(int *stack, int length)
{
	int	i;

	i = 0;
	while (i < length)
	{
		stack[i] = stack[i + 1];
		i++;
	}
}

void	push(int *stack_a, int *stack_b, char c, t_params *params)
{
	if (c == 'a')
	{
		if (params->length_b == 0)
			return ;
		params->length_a = params->length_a + 1;
		params->length_b = params->length_b - 1;
		push_to(stack_b[0], stack_a, params->length_a - 1);
		push_from(stack_b, params->length_b);
		write(1, "pa", 2);
		write(1, "\n", 1);
	}
	else
	{
		if (params->length_a == 0)
			return ;
		params->length_b = params->length_b + 1;
		params->length_a = params->length_a - 1;
		push_to(stack_a[0], stack_b, params->length_b - 1);
		push_from(stack_a, params->length_a);
		write(1, "pb", 2);
		write(1, "\n", 1);
	}
}
