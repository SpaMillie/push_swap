/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mspasic <mspasic@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/27 17:57:41 by mspasic           #+#    #+#             */
/*   Updated: 2024/03/01 20:04:16 by mspasic          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

typedef struct s_params
{
	int	**list;
	int	check;
	int	counter;
	int	args;
}	t_params;

void	push_swap(char **argv)
{
	
}
//check if the new line should also be in 2
int	error_message(void)
{
	write(2, "Error", 6);
	write(1, '\n', 1);
	return (0);
}

void	init_params(t_params *params, int argc)
{
	params->list = NULL;
	params->check = 0;
	params->counter = 0;
	params->args = argc;
}

int	check_str(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		if (i == 0 && (str[i] == '+' || str[i] == '-'))
			i++;
		else if (str[i] < '0' || str[i] > '9')
			return (1);
		i++;
	}
	return(0);
}
int	check_if_valid_one(char *str, t_params *params)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		while (str[i] != ' ')
		{
			
		}
		if (i == 0 && (str[i] == '+' || str[i] == '-'))
			i++;	
		i++;
	}	
}


int	check_if_valid(char **str, t_params *params)
{
	int	i;

	i = 0;
	if (params->args == 1)
		check_if_valid_one(str[i], params);
	else
		check_if_valid_more(str, params);
	while (i < params->args)
	{
		params->check = check_str(str[i]);
		if (params->check != 0)
			return (1);
		i++;
	}
}

int	main(int argc, char **argv)
{
	int			i;
	t_params	*params;

	init_params(params, argc);
	if (argc >= 2)
	{
		i = 0;
		params->check = check_if_valid (argv, params);
		if (params->check != 0)
			return (error_message());
		// while (params->args > 1)
		// {
		// 	params->list[i] = ft_atoi(argv[i]);
		// 	i++;
		// }
		// push_swap(params->list);
	}
	else
		return(error_message());
}
