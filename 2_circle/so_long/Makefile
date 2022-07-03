# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jibae <jibae@student.42seoul.kr>           +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/05/08 06:07:17 by jibae             #+#    #+#              #
#    Updated: 2022/05/29 22:29:27 by jibae            ###   ########seoul.kr   #
#                                                                              #
# **************************************************************************** #

NAME = so_long

CC	= cc
CFLAGS	= -Wall -Wextra -Werror

RM		= rm
RMFLAGS	= -f

LIB_NAME	= ft

LIB_DIR	= ./libft/

INCLUDE	= -I ./Libft

SRCS	= error.c			\
			image.c			\
			key.c			\
			map.c			\
			so_long.c		\
			so_long_utils.c	\

OBJS	= $(SRCS:.c=.o)

$(NAME) : $(OBJS)
		make all -C $(LIB_DIR)
		gcc -o $(NAME) $(OBJS) -L libft -l $(LIB_NAME) -L ./mlx -l mlx -framework OpenGL -framework AppKit

%.o : %.c
	$(CC) $(CFLAGS) $(INCLUDE) -c $< -o $@

all: $(NAME)

clean :
	make -C $(LIB_DIR) clean
	$(RM) $(RMFLAGS) $(OBJS)

fclean : clean
	make -C $(LIB_DIR) fclean
	$(RM) $(RMFLAGS) $(NAME)

re : fclean
	make all

.PHONY : all clean fclean re