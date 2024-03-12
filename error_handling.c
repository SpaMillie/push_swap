/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_handling.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mspasic <mspasic@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/07 15:26:52 by mspasic           #+#    #+#             */
/*   Updated: 2024/03/12 14:14:17 by mspasic          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	duplicate_found(t_params *params)
{
	free(params->stack_a);
	free(params->stack_b);
	free(params->aux_stack);
	error_message();
	return (1);
}

void	malloc_fail(t_params *params)
{
	free(params->stack_a);
	free(params->stack_b);
	free(params->aux_stack);
	write(2, "Error: Malloc failed", 21);
	write(2, '\n', 1);
}

int	error_message(void)
{
	write(2, "Error", 6);
	write(2, "\n", 1);
	return (0);
}
