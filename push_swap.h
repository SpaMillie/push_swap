/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mspasic <mspasic@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/01 18:49:31 by mspasic           #+#    #+#             */
/*   Updated: 2024/03/07 15:48:11 by mspasic          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include <unistd.h>
# include "Libft/libft.h"

typedef struct s_params
{
	int		*stack_a;
	int		*stack_b;
	int		check;
	int		counter;
	int		args;
	int		length_a;
	int		length_b;
	char	stack;
}	t_params;

//main.c
int		create_a(char **str, t_params *params);
int		check_passed(char **str, t_params *params);
void	init_params(t_params *params, int argc);
int		main(int argc, char **argv);
//checking_if_valid.c
int		soft_check_for_limit(char *str, int length);
int		check_for_spaces(char *str);
int		check_str(char *str, int i);
int		check_if_valid_one(char *str, t_params *params);
int		check_if_valid(char **str, t_params *params);
//push_swap.c
//swap_and_push.c
//error_handling.c
void	malloc_fail(t_params *params);
int		error_message(void);
#endif