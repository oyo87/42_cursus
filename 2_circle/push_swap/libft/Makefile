# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jibae <jibae@student.42seoul.kr>           +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/12/17 14:47:21 by jibae             #+#    #+#              #
#    Updated: 2022/05/04 15:35:54 by jibae            ###   ########seoul.kr   #
#                                                                              #
# **************************************************************************** #

NAME		= libft.a

CC			= cc
CFLAGS		= -Wall -Wextra -Werror

RM			= rm
RMFLAGS		= -f

AR			= ar
ARFLAGS		= rcs

SRCS_1		= ft_isalpha.c		\
			ft_isdigit.c		\
			ft_isalnum.c		\
			ft_isascii.c		\
			ft_isprint.c		\
			ft_strlen.c			\
			ft_strlcpy.c		\
			ft_strlcat.c		\
			ft_strchr.c			\
			ft_strnstr.c		\
			ft_strncmp.c		\
			ft_strdup.c			\
			ft_strrchr.c		\
			ft_memset.c			\
			ft_memcpy.c			\
			ft_memmove.c		\
			ft_memchr.c			\
			ft_memcmp.c			\
			ft_bzero.c			\
			ft_atoi.c			\
			ft_calloc.c			\
			ft_tolower.c		\
			ft_toupper.c		\
			ft_isspace.c		\
			get_next_line.c		\
			get_next_line_utils.c	\

SRCS_2		= ft_substr.c		\
			ft_strjoin.c		\
			ft_strtrim.c		\
			ft_strmapi.c		\
			ft_striteri.c		\
			ft_itoa.c			\
			ft_split.c			\
			ft_putchar_fd.c		\
			ft_putstr_fd.c		\
			ft_putendl_fd.c		\
			ft_putnbr_fd.c		\

SRCS_BONUS		= ft_lstnew.c		\
			ft_lstadd_front.c	\
			ft_lstsize.c		\
			ft_lstlast.c		\
			ft_lstadd_back.c	\
			ft_lstdelone.c		\
			ft_lstclear.c		\
			ft_lstiter.c		\
			ft_lstmap.c			\

SRCS		= $(SRCS_1)			\
			$(SRCS_2)			\

OBJS		= $(SRCS:.c=.o)

OBJS_BONUS	= $(SRCS_BONUS:.c=.o)

ifdef WITH_BONUS
	OBJ_FILES = $(OBJS) $(OBJS_BONUS)
else
	OBJ_FILES = $(OBJS)
endif

all : $(NAME)

$(NAME) : $(OBJ_FILES)
	$(AR) $(ARFLAGS) $@ $^

%.o : %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean :
	$(RM) $(RMFLAGS) $(OBJS) $(OBJS_BONUS)

fclean : clean
	$(RM) $(RMFLAGS) $(NAME)

re : fclean
	make all

bonus :
	make WITH_BONUS=1 all

.PHONY : all clean fclean re bonus