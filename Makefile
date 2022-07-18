# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bgenie <bgenie@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/06/29 16:41:35 by bgenie            #+#    #+#              #
#    Updated: 2022/07/18 20:23:45 by bgenie           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc

CFLAGS = -Wall -Werror -Wextra

SRCS = 	push_swap.c \
		radix.c \
		operations_1.c \
		operations_2.c

HEADERS_DIR = ./

LIB_DIR = libft/

LIB = libft.a

OBJS = $(SRCS:.c=.o)

NAME = push_swap

all: $(NAME)

$(NAME): $(OBJS)
	@make -C $(LIB_DIR)
	@printf "\e[33m[%s]: Compiling %s...\n\e[0m" $(NAME) $(NAME)
	$(CC) $(FLAGS) -I$(HEADERS_DIR) -I$(LIB_DIR) -o $(NAME) $(LIB_DIR)$(LIB) $(OBJS)

clean:
	@make -C $(LIB_DIR) clean
	@printf "\e[33m[%s]: Cleaning object files...\n\e[0m" $(NAME)
	@rm -vf $(OBJS)

fclean:	clean
	@make -C $(LIB_DIR) fclean
	@printf "\e[33m[%s]: Cleaning binary files...\n\e[0m" $(NAME)
	@rm -vf $(NAME)

re: 	clean fclean all

.PHONY: all clean fclean re
