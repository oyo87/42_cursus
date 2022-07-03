# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jibae <jibae@student.42seoul.kr>           +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/05/03 14:02:31 by jibae             #+#    #+#              #
#    Updated: 2022/05/17 15:16:31 by jibae            ###   ########seoul.kr   #
#                                                                              #
# **************************************************************************** #

NAME		= push_swap

BONUS		= checker

CC			= cc
CFLAGS		= -Wall -Wextra -Werror

LIB_NAME	= ft

LIB_DIR		= ./libft/

LIBFT		= libft.a

LIB			= $(LIB_DIR)$(LIBFT)

INCLUDE		= -I ./Libft

RM			= rm
RMFLAGS		= -f

CP			= cp

SRCS		= argv_to_arr.c				\
				list_utils.c			\
				push_swap.c				\
				sort.c					\
				sort_rotate_utils.c		\
				check_arr_sort.c		\
				operation_r.c			\
				operation_rr.c			\
				operation_sp.c			\
				push_swap_utils.c		\
				sort_rotate.c			\
				sort_utils.c			\

SRCS_BONUS	= checker_bonus.c			\
				argv_to_arr_bonus.c		\
				list_utils_bonus.c		\
				check_arr_sort_bonus.c	\
				check_bonus.c			\
				operation_r_bonus.c		\
				operation_rr_bonus.c	\
				operation_sp_bonus.c	\
				push_swap_utils_bonus.c	\
				
OBJS		= $(SRCS:.c=.o)

OBJS_BONUS	= $(SRCS_BONUS:.c=.o)

$(NAME) :$(LIB) $(OBJS)
	$(CC) $(CFLAGS) -L$(LIB_DIR) -l$(LIB_NAME) $(OBJS) -o $(NAME)

$(BONUS) :$(LIB) $(OBJS_BONUS)
	$(CC) $(CFLAGS) -L$(LIB_DIR) -l$(LIB_NAME) $(OBJS_BONUS) -o $(BONUS)

%.o : %.c
	$(CC) $(CFLAGS) $(INCLUDE) -c $< -o $@

$(LIB) :
	make -C $(LIB_DIR)
	$(CP) $(LIB) .

all : $(NAME)

clean :
	make -C $(LIB_DIR) clean
	$(RM) $(RMFLAGS) $(OBJS)
	$(RM) $(RMFLAGS) $(OBJS_BONUS)

fclean : clean
	make -C $(LIB_DIR) fclean
	$(RM) $(RMFLAGS) $(NAME)
	$(RM) $(RMFLAGS) $(BONUS)
	$(RM) $(RMFLAGS) $(LIBFT)

re : fclean
	make all

bonus : $(BONUS)

.PHONY : all clean fclean re bonus