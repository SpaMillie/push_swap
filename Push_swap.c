/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mspasic <mspasic@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/27 17:57:41 by mspasic           #+#    #+#             */
/*   Updated: 2024/02/28 21:43:56 by mspasic          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	push_swap(char **argv)
{
	
}

int	main(int argc, char **argv)
{
	int	i;
	int	j;
	int	**list;

	if (argc >= 2)
	{
		i = 0;
		j = argc;
		int c = check_if_valid (argv);
		if (c != 0)
			return(error_message);
		while (j-- > 1)
		{
			list[i] = ft_atoi(argv[i]);
			i++;
		}
		push_swap(list);
	}
	else
		write(1, "Error", 6);
	write(1, "\n", 1);
}
