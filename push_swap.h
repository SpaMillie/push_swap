/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mspasic <mspasic@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/01 18:49:31 by mspasic           #+#    #+#             */
/*   Updated: 2024/03/12 14:24:18 by mspasic          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H

# define PUSH_SWAP_H
# include <unistd.h>
# include <stdlib.h>
# include "Libft/libft.h"
/* length == index */
typedef struct s_params
{
	int		*stack_a;
	int		*stack_b;
	int		*aux_stack;
	int		check;
	int		counter;
	int		args;
	int		length;
	int		length_a;
	int		length_b;
	int		length_aux;
	char	stack;
}	t_params;

//main.c
int		create_stacks(char **str, t_params *params);
int		check_passed(char **str, t_params *params);
void	init_params(t_params *params, int argc);
int		main(int argc, char **argv);
//checking_if_valid.c
int		soft_check_for_limit(char *str, int length);
int		check_for_spaces(char *str);
int		check_str(char *str, int i);
int		check_if_valid_one(char *str, t_params *params);
int		check_if_valid(char **str, t_params *params);
//sort_aux.c
void	add_number(t_params *params, int num, int start, int end);
int		sort_aux(t_params *params, int length);
//push_swap.c
//rotate.c
void	r_stack(int *stack, t_params *params, char c);
void	r_both(int *a, int *b, t_params *params);
void	rr_stack(int *stack, t_params *params, char c);
void	rr_both(int *a, int *b, t_params *params);
//swap_and_push.c
void	swap(int *stack, t_params *params, int length);
void	swap_both(int *a, int *b, t_params *params);
void	push_to(int temp, int *stack, t_params *params, int length);
void	push_from(int *stack, t_params *params, int length);
void	push(int *stack_1, int *stack_2, char c, t_params *params);
//error_handling.c
int		duplicate_found(t_params *params);
void	malloc_fail(t_params *params);
int		error_message(void);

#endif