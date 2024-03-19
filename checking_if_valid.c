/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checking_if_valid.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mspasic <mspasic@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/04 19:00:25 by mspasic           #+#    #+#             */
/*   Updated: 2024/03/19 17:08:40 by mspasic          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	soft_check_for_limit(char *str, int length)
{
	int	i;

	i = 0;
	if (length > 11)
		return (0);
	if (length == 11)
	{
		if (str[i] != '-' && str[i] != '+')
			return (0);
		i++;
	}
	if (str[i] < '0' || str[i] > '2')
		return (0);
	return (1);
}


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

int	check_str(char *str, int i, t_params *params)
{
	int	k;
	int	j;

	k = i;
	j = ft_strlen(str);
	if (j >= 10 && params->args != 2)
	{
		j = soft_check_for_limit(str, j);
		if (j == 0)
			return (0);
	}
	while (str[k] != '\0' && str[k] != ' ')
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
	int	check;

	i = check_for_spaces(str);
	if (i == 0)
	{
		i = check_str(str, 0, params);
		if (i == 0)
			return (1);
	}
	else
	{
		i = 0;
		while (str[i] != '\0')
		{
			check = check_str(str, i, params);
			if (check == 0)
				return (1);
			i = check;
			if (str[i] != '\0')
				i += 1;
		}
	}
	return (0);
}

int	check_if_valid(char **str, t_params *params)
{
	int	i;
	int	check;

	i = 0;
	if (params->args == 2)
	{
		check = check_if_valid_one(str[1], params);
		if (check != 0)
			return (1);
	}
	else
	{
		i = 1;
		while (i < params->args)
		{
			check = check_str(str[i], 0, params);
			if (check == 0)
				return (1);
			i++;
		}
	}
	return (0);
}
