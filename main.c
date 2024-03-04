/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mspasic <mspasic@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/04 19:07:22 by mspasic           #+#    #+#             */
/*   Updated: 2024/03/04 19:51:10 by mspasic          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// void	push_swap(char **argv)
// {
// }

//check if the new line should also be in 2
int	error_message(void)
{
	write(2, "Error", 6);
	write(1, "\n", 1);
	return (0);
}

void	init_params(t_params *params, int argc)
{
	// params->list = NULL;
	params->check = 0;
	params->counter = 0;
	params->args = argc;
}

int	main(int argc, char **argv)
{
	t_params	params;

	if (argc >= 2)
	{
		init_params(&params, argc);
		params.check = check_if_valid (argv, &params);
		if (params.check != 0)
			return (error_message());
		write(1, "Valid", 6);
		write(1, "\n", 1);
		// create_a();
		// push_swap(params->list);
	}
	else
		return (error_message());
}
