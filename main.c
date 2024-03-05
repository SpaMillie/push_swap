/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mspasic <mspasic@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/04 19:07:22 by mspasic           #+#    #+#             */
/*   Updated: 2024/03/05 19:22:46 by mspasic          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

// void	push_swap(char **argv)
// {
// }

int	create_a(char **str, t_params *params)
{
	int		i;
	int		j;
	char	**list;

	j = params->args;
	i = 1;
	if (params->args == 2)
	{
		printf("checking the string %s\n", str[i]);
		list = ft_split(str[i], ' ');
		if (list == NULL)
			return (1);
	}
	else
		list = str;
	while (j > 1)
	{
		params->list[i - 1] = ft_atoi(list[i]);
		i++;
		j--;
	}
	if (params->args == 2)
		free(list);
	return (0);
}

//check if the new line should also be in 2
int	error_message(void)
{
	write(2, "Error", 6);
	write(1, "\n", 1);
	return (0);
}

void	init_params(t_params *params, int argc)
{
	params->list = NULL;
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
		params.check = create_a(argv, &params);
		if (params.check != 0)
			return (error_message());
		printf("check passed = %d\n", params.check);
		// if (params.counter == 0)
		// {
		// 	while (params.list)
		// 		printf("%d\n", params.list[params.counter++]);
		// }
		// push_swap(params->list);
	}
	else
		return (error_message());
}
