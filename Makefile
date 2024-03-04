# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mspasic <mspasic@student.hive.fi>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/02/28 21:44:20 by mspasic           #+#    #+#              #
#    Updated: 2024/03/04 19:52:51 by mspasic          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap

CC = cc
CFLAGS = -Wall -Wextra -Werror

# LIBFT_PATH = Libft/
# LIBFT_NAME = libft.a
# LIBFT = $(LIBFT_PATH)$(LIBFT_NAME)

SOURCE_FILES = main.c \
			checking_if_valid.c \
			# push_swap.c

OBJECT_FILES = $(SOURCE_FILES:.c=.o)

# ************************************* #

all: $(NAME)

$(NAME): $(OBJECT_FILES)
	$(CC) $(CFLAGS) $(OBJECT_FILES) -o $(NAME)

# $(NAME): $(LIBFT) $(OBJECT_FILES)
# 	$(CC) $(CFLAGS) $(OBJECT_FILES) $(LIBFT) $(HEADER) -o $(NAME)

# $(LIBFT):
# 	make -C $(LIBFT_PATH)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJECT_FILES)
	# @make -C $(LIBFT_PATH) clean

fclean: clean
	rm -f $(NAME)
	# @make -C $(LIBFT_PATH) fclean

re: fclean all

.PHONY: clean fclean all re libft