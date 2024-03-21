/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mspasic <mspasic@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/01 18:49:31 by mspasic           #+#    #+#             */
/*   Updated: 2024/03/21 13:44:55 by mspasic          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H

# define PUSH_SWAP_H
# include <unistd.h>
# include <stdlib.h>
# include "Libft/include/libft.h"

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
	int		master;
	int		student;
}	t_params;

//main.c
int		fill_a(t_params *params, char **str, int length);
int		create_stacks(char **str, t_params *params);
int		check_passed(char **str, t_params *params);
int		main(int argc, char **argv);
//checking_if_valid.c
int		soft_check_for_limit(char *str, int length);
int		check_for_spaces(char *str);
int		check_str(char *str, int i, t_params *params);
int		check_if_valid_one(char *str, t_params *params);
int		check_if_valid(char **str, t_params *params);
//checking_if_sorted.c
int		check_if_sorted_big(t_params *params);
int		check_if_sorted_all(t_params *params);
int		check_if_sorted(t_params *params, int option);
//ft_atol.c
long	ft_atol(const char *str);
//sort_aux.c
void	add_number(t_params *params, int num, int start, int end);
int		sort_aux(t_params *params, int length);
//push_swap.c
void	check_where_next(t_params *params);
void	training_montage(t_params *params, int index);
void	sorting_hat(t_params *params);
void	three_nums(t_params *params, int option);
void	push_swap(t_params *params);
//rotate.c
void	r_stack(int *stack, t_params *params, char c);
void	r_both(int *a, int *b, t_params *params);
void	rr_stack(int *stack, t_params *params, char c);
void	rr_both(int *a, int *b, t_params *params);
//swap_and_push.c
void	swap(int *stack, int length, char c);
void	swap_both(int *a, int *b, t_params *params);
void	push_to(int temp, int *stack, int length);
void	push_from(int *stack, int length);
void	push(int *stack_a, int *stack_b, char c, t_params *params);
//error_handling.c
int		something_went_wrong(t_params *params);
void	malloc_fail(t_params *params);
int		error_message(void);
//hacky_stack.c
void	hacky_stack(t_params *params);
void	half_half(t_params *params);
void	sixty_smallest(t_params *params);

#endif