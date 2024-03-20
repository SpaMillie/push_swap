# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mspasic <mspasic@student.hive.fi>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/02/28 21:44:20 by mspasic           #+#    #+#              #
#    Updated: 2024/03/20 15:49:31 by mspasic          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap

CC = cc
CFLAGS = -Wall -Wextra -Werror

LIBFT_PATH = Libft/
LIBFT_NAME = libft.a
LIBFT = $(LIBFT_PATH)$(LIBFT_NAME)

SOURCE_FILES = main.c \
			checking_if_valid.c \
			checking_if_sorted.c \
			ft_atol.c \
			push_swap.c \
			swap_and_push.c \
			sort_aux.c \
			rotate.c \
			error_handling.c \
			hacky_stack.c

OBJECT_FILES = $(SOURCE_FILES:.c=.o)

# ************************************* #

all: $(NAME)

$(NAME): $(LIBFT) $(OBJECT_FILES)
	$(CC) $(CFLAGS) $(OBJECT_FILES) $(LIBFT) -o $(NAME)

$(LIBFT):
	make -C $(LIBFT_PATH)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJECT_FILES)
	@make -C $(LIBFT_PATH) clean

fclean: clean
	rm -f $(NAME)
	@make -C $(LIBFT_PATH) fclean

re: fclean all

.PHONY: clean fclean all re libft push_swap