/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_handling.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mspasic <mspasic@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/07 15:26:52 by mspasic           #+#    #+#             */
/*   Updated: 2024/03/07 16:08:46 by mspasic          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	malloc_fail(t_params *params)
{
	if (params->stack_a != NULL)
		free(params->stack_a);
	if (params->stack_b != NULL)
		free(params->stack_b);
	if (params->aux_stack != NULL)
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
