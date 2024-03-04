/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checking_if_valid.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mspasic <mspasic@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/04 19:00:25 by mspasic           #+#    #+#             */
/*   Updated: 2024/03/04 21:57:21 by mspasic          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

int	check_for_spaces(char *str)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (str[i] != '\0')
	{
		if (str[i] == ' ')
			j++;
		i++;
	}
	return (j);
}

int	check_str(char *str, int i)
{
	int	k;

	k = i;
	while (str[k] != ' ' || str[k] != '\0')
	{
		printf("str[k] = %c\n", str[k]);
		printf("str = %s\n", str);
		if (k == i && (str[k] == '+' || str[k] == '-'))
			k++;
		else if (str[k] < '0' || str[k] > '9')
			return (0);
		else
			k++;
	}
	return (k);
}

int	check_if_valid_one(char *str, t_params *params)
{
	int	i;

	i = check_for_spaces(str);
	printf("spaces = %d\n", i);
	if (i == 0)
	{
		i = check_str(str, 0);
		printf("i = %d\n", i);
		if (i == 0)
			return (1);
	}
	else
	{
		params->check = 0;
		i = 0;
		while (str[i] != '\0')
		{
			params->check = check_str(str, i);
			printf("has spaces, check = %d\n", params->check);
			if (params->check == 0)
				return (1);
			i += params->check;
		}
	}
	return (0);
}

int	check_if_valid(char **str, t_params *params)
{
	int	i;

	i = 0;
	if (params->args == 2)
	{
		params->check = check_if_valid_one(str[1], params);
		printf("args = 1, check = %d\n", params->check);
		if (params->check != 0)
			return (1);
	}
	else
	{
		i = 1;
		while (i < params->args)
		{
			params->check = check_str(str[i], 0);
			printf("args > 1, check = %d\n", params->check);
			if (params->check == 0)
				return (1);
			i++;
		}
	}
	return (0);
}
