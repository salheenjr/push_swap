# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: saalagor <saalagor@student.42kl.edu.m      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/08/15 14:55:56 by saalagor          #+#    #+#              #
#    Updated: 2026/08/18 13:52:27 by saalagor         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME        = push_swap
CC          = cc
CFLAGS      = -Wall -Wextra -Werror

SRC_DIR     = srcs
SRCS        = $(SRC_DIR)/main.c \
              $(SRC_DIR)/operations/op_swap.c \
              $(SRC_DIR)/operations/op_push.c \
              $(SRC_DIR)/operations/op_rotate.c \
              $(SRC_DIR)/operations/op_rev_rotate.c \
              $(SRC_DIR)/stack/stack_utils.c \
              $(SRC_DIR)/sorting/sort_utils.c \
              $(SRC_DIR)/sorting/sort_small.c \
              $(SRC_DIR)/sorting/sort_simple.c \
              $(SRC_DIR)/sorting/sort_medium.c \
              $(SRC_DIR)/sorting/sort_adaptive.c \
              $(SRC_DIR)/sorting/sort_complex.c

OBJS        = $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
