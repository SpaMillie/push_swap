/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_and_push.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mspasic <mspasic@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/06 17:35:32 by mspasic           #+#    #+#             */
/*   Updated: 2024/03/07 16:33:12 by mspasic          ###   ########.fr       */
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
		write(1, '\n', 1);
	}
	else if (params->stack == 'a')
	{
		write(1, "sa", 3);
		write(1, '\n', 1);
	}
}

void	swap_both(int *a, int *b, t_params *params)
{
	swap(a, params, params->length_a);
	swap(b, params, params->length_b);
	write(1, "ss", 3);
	write(1, '\n', 1);
}

int	*push_temp_1(int *stack_1, int*stack_2, t_params *params, int length)
{
	int	*temp;

	temp = malloc(sizeof(int) * length);
	if (!temp)
		return (NULL);
	params->counter = 0;
	while (params->counter < length)
	{
		if (params->counter == 0)
			temp[params->counter] = stack_2[params->counter];
		else
			temp[params->counter] = stack_1[params->counter - 1];
		params->counter++;
	}
	free (stack_1);
	return (temp);
}

int	*push_temp_2(int*stack_2, t_params *params, int length)
{
	int	*temp;

	temp = malloc(sizeof(int) * length);
	if (!temp)
		return (NULL);
	params->counter = 0;
	while (params->counter < length)
	{
		temp[params->counter] = stack_2[params->counter + 1];
		params->counter++;
	}
	free (stack_2);
	return (temp);
}

void	push(int *stack_1, int *stack_2, char c, t_params *params)
{
	int	length;

	if (!stack_1 || !stack_2)
		return ;
	if (c == 'a')
		length = params->length_a + 1;
	else
		length = params->length_b + 1;
	stack_1 = push_temp_1(stack_1, stack_2, params, length);
	if (c == 'a')
		stack_2 = push_temp_2(stack_2, params, params->length_b - 1);
	else
		stack_2 = push_temp_2(stack_2, params, params->length_a - 1);
	if (!stack_1 || !stack_2)
	{
		malloc_fail(params);
		return ;
	}
	if (c == 'a')
		write(1, "pa", 3);
	else
		write(1, "pb", 3);
	write(1, '\n', 1);
}
