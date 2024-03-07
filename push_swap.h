/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mspasic <mspasic@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/01 18:49:31 by mspasic           #+#    #+#             */
/*   Updated: 2024/03/07 16:35:12 by mspasic          ###   ########.fr       */
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
	int		*aux_stack;
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
void	swap(int *stack, t_params *params, int length);
void	swap_both(int *a, int *b, t_params *params);
int		*push_temp_1(int *stack_1, int*stack_2, t_params *params, int length);
int		*push_temp_2(int*stack_2, t_params *params, int length);
void	push(int *stack_1, int *stack_2, char c, t_params *params);
//error_handling.c
void	malloc_fail(t_params *params);
int		error_message(void);

#endif