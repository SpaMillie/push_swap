/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mspasic <mspasic@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/04 19:07:22 by mspasic           #+#    #+#             */
/*   Updated: 2024/03/20 14:15:09 by mspasic          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	create_stacks(char **str, t_params *params)
{
	int	i;
	int	j;

	i = 0;
	params->length = 0;
	while (str[params->length] != '\0')
		params->length++;
	j = params->length;
	params->stack_a = (int *)malloc(sizeof(int) * params->length);
	params->stack_b = (int *)malloc(sizeof(int) * params->length);
	params->aux_stack = (int *)malloc(sizeof(int) * params->length);
	if (!params->stack_a || !params->stack_b || !params->aux_stack)
	{
		malloc_fail(params);
		return (1);
	}
	while (j-- > 0)
	{
		params->stack_a[i] = ft_atoi(str[i]);
		i++;
	}
	params->length_a = params->length;
	if (sort_aux(params, params->length) == 1)
		return (1);
	return (0);
}

char	**free_all(char **res);

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
	params->check = create_stacks(list, params);
	if (params->check == 1)
	{
		if (j == 2)
			free_all(list);
		return (1);
	}
	if (params->args == 2)
		free_all(list);
	return (0);
}

int	main(int argc, char **argv)
{
	t_params	params;

	if (argc >= 2)
	{
		params.args = argc;
		params.check = check_if_valid (argv, &params);
		if (params.check != 0)
			return (error_message());
		params.check = check_passed(argv + 1, &params);
		if (params.check != 0)
			return (error_message());
		push_swap(&params);
		free(params.stack_a);
		free(params.stack_b);
		free(params.aux_stack);
	}
	else
		return (error_message());
}
