# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jibae <jibae@student.42seoul.kr>           +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/05/25 17:07:58 by jibae             #+#    #+#              #
#    Updated: 2022/06/27 22:03:36 by jibae            ###   ########seoul.kr   #
#                                                                              #
# **************************************************************************** #

NAME	= pipex

CC	= cc
CFLAGS	= -Wall -Wextra -Werror

RM	= rm
RMFLAGS	= -f

LIB_NAME	= ft

LIB_DIR	= ./libft/

INCLUDE = -I ./Libft

SRCS	= pipex.c	\
			pipex_utils.c	\
			pipex_utils2.c	\

SRCS_BONUS = pipex_bonus.c				\
				pipex_utils_bonus.c		\
				pipex_utils2_bonus.c	\
				here_doc_bonus.c		\
				child_bonus.c			\

OBJS	= $(SRCS:.c=.o)

OBJS_BONUS = $(SRCS_BONUS:.c=.o)

ifdef WITH_BONUS
	OBJ_FILES = $(OBJS_BONUS)
else
	OBJ_FILES = $(OBJS)
endif

$(NAME) : $(OBJ_FILES)
	make bonus -C $(LIB_DIR)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJ_FILES) -L $(LIB_DIR) -l $(LIB_NAME)

%.o : %.c
	$(CC) $(CFLAGS) $(INCLUDE) -c $< -o $@

all : $(NAME)

clean :
	make -C $(LIB_DIR) clean
	$(RM) $(RMFLAGS) $(OBJS)
	$(RM) $(RMFLAGS) $(OBJS_BONUS)

fclean : clean
	make -C $(LIB_DIR) fclean
	$(RM) $(RMFLAGS) $(NAME)

re : fclean
	make all

bonus : $(OBJS_BONUS)
	make WITH_BONUS=1 all

.PHONY : all clean fclean re bonus