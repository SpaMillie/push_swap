/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checking_if_valid.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mspasic <mspasic@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/04 19:00:25 by mspasic           #+#    #+#             */
/*   Updated: 2024/03/04 19:52:17 by mspasic          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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
	if (i == 0)
	{
		i = check_str(str, 0);
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
	if (params->args == 1)
	{
		params->check = check_if_valid_one(str[0], params);
		if (params->check != 0)
			return (1);
	}
	else
	{
		while (i < params->args)
		{
			params->check = check_str(str[i], 0);
			if (params->check == 0)
				return (1);
			i++;
		}
	}
	return (0);
}
