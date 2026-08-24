# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: wchan-ha <wchan-ha@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/08/15 14:55:56 by saalagor          #+#    #+#              #
#    Updated: 2026/08/24 09:40:26 by saalagor         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME        = push_swap
BONUS_NAME  = checker

CC          = cc
CFLAGS      = -Wall -Wextra -Werror -I. -I$(LIBFT_DIR)

LIBFT_DIR   = libft
LIBFT       = $(LIBFT_DIR)/libft.a

HEADERS     = push_swap.h

SRC_DIR     = srcs
OBJ_DIR     = obj

SRCS        = $(SRC_DIR)/operations/op_swap.c \
              $(SRC_DIR)/operations/op_push.c \
              $(SRC_DIR)/operations/op_rotate.c \
              $(SRC_DIR)/operations/op_rev_rotate.c \
              $(SRC_DIR)/stack/stack_init.c \
              $(SRC_DIR)/stack/stack_utils.c \
              $(SRC_DIR)/sorting/sort_utils.c \
              $(SRC_DIR)/sorting/sort_small.c \
              $(SRC_DIR)/sorting/sort_simple.c \
              $(SRC_DIR)/sorting/sort_medium.c \
              $(SRC_DIR)/sorting/sort_complex_utils.c \
              $(SRC_DIR)/sorting/sort_complex.c \
              $(SRC_DIR)/sorting/sort_adaptive.c \
              $(SRC_DIR)/bench/bench_print.c \
              $(SRC_DIR)/stack/stack_validation.c

MAIN        = $(SRC_DIR)/main.c

BONUS_MAIN  = $(SRC_DIR)/checker.c

OBJS        = $(SRCS:$(SRC_DIR)/%.c=$(OBJ_DIR)/%.o)

all: $(NAME)

$(LIBFT):
	@make -C $(LIBFT_DIR)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c $(HEADERS)
	@mkdir -p $(dir $@)
	$(CC) $(CFLAGS) -c $< -o $@

$(NAME): $(LIBFT) $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) $(MAIN) $(LIBFT) -o $(NAME)

clean:
	rm -rf $(OBJ_DIR)
	@make -C $(LIBFT_DIR) clean

fclean: clean
	rm -f $(NAME)
	rm -f $(BONUS_NAME)
	@make -C $(LIBFT_DIR) fclean

re: fclean all

bonus:	$(LIBFT) $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) $(BONUS_MAIN) $(LIBFT) -o $(BONUS_NAME)

.PHONY: all clean fclean re bonus
