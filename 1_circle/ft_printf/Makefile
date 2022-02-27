# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jibae <jibae@student.42seoul.kr>           +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/01/21 20:11:22 by jibae             #+#    #+#              #
#    Updated: 2022/02/23 18:14:47 by jibae            ###   ########seoul.kr   #
#                                                                              #
# **************************************************************************** #

NAME		= libftprintf.a

CC			= gcc
CFLAGS		= -Wall -Wextra -Werror

RM			= rm
RMFLAGS		= -f

AR			= ar
ARFLAGS		= rcs

SRCS		= ft_printf.c			\
			  ft_format_c.c			\
			  ft_format_p.c			\
			  ft_format_s.c			\
			  ft_format_d.c			\
			  ft_format_i.c			\
			  ft_format_u.c			\
			  ft_format_x.c			\
			  ft_format_upperx.c	\
			  ft_format_per.c		\
			  ft_printf_utils.c		\
			  ft_printf_utils2.c	\

OBJS		= $(SRCS:.c=.o)

all : $(NAME)

$(NAME) : $(OBJS)
	$(AR) $(ARFLAGS) $@ $^

%.o : %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean :
	$(RM) $(RMFLAGS) $(OBJS)

fclean : clean
	$(RM) $(RMFLAGS) $(NAME)

re : fclean all

.PHONY : all clean fclean re