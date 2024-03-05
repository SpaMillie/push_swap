/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mspasic <mspasic@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/01 18:49:31 by mspasic           #+#    #+#             */
/*   Updated: 2024/03/05 18:57:01 by mspasic          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include <unistd.h>
# include "Libft/libft.h"

typedef struct s_params
{
	int	*list;
	int	check;
	int	counter;
	int	args;
}	t_params;

//main.c
int		error_message(void);
void	init_params(t_params *params, int argc);
int		main(int argc, char **argv);
//checking_if_valid.c
int		soft_check_for_limit(char *str, int length);
int		check_for_spaces(char *str);
int		check_str(char *str, int i);
int		check_if_valid_one(char *str, t_params *params);
int		check_if_valid(char **str, t_params *params);
#endif