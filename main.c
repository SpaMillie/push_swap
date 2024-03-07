/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mspasic <mspasic@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/04 19:07:22 by mspasic           #+#    #+#             */
/*   Updated: 2024/03/07 15:23:28 by mspasic          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	create_a(char **str, t_params *params)
{
	int	i;
	int	j;

	i = 0;
	j = params->args;
	while (str[params->length_a] != '\0')
		params->length_a++;
	params->list = malloc(sizeof(int) * params->length_a);
	if (!params->list)
		return (1);
	while (j-- > 1)
	{
		params->list[i] = ft_atoi(str[i]);
		i++;
	}
	return (0);
}

int	check_passed(char **str, t_params *params)
{
	int		i;
	int		j;
	char	**list;

	i = 0;
	j = params->args;
	if (params->args == 2)
	{
		list = ft_split(str[i], ' ');
		if (list == NULL)
			return (1);
	}
	else
		list = str;
	params->check = create_a(list, params);
	if (params->check == 1)
	{
		if (j == 2)
			free(list);
		return (1);
	}
	if (params->args == 2)
		free(list);
	return (0);
}

//check if the new line should also be in 2
int	error_message(void)
{
	write(2, "Error", 6);
	write(2, "\n", 1);
	return (0);
}

void	init_params(t_params *params, int argc)
{
	params->list = NULL;
	params->check = 0;
	params->counter = 0;
	params->args = argc;
	params->length_a = 0;
	params->length_b = 0;
	params->stack = a;
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
		params.check = check_passed(argv + 1, &params);
		if (params.check != 0)
			return (error_message());
		// push_swap(params.list);
		//free(params.list);
	}
	else
		return (error_message());
}
