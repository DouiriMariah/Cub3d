# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aperis <aperis@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/12/02 13:37:47 by aperis            #+#    #+#              #
#    Updated: 2022/10/13 13:00:04 by aperis           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS = ft_atoi.c ft_isdigit.c ft_strlcpy.c ft_toupper.c \
	ft_bzero.c ft_isprint.c ft_strlen.c ft_calloc.c \
	ft_memchr.c ft_strchr.c ft_strncmp.c ft_isalnum.c \
	ft_memcmp.c ft_strdup.c ft_strnstr.c ft_isalpha.c \
	ft_memcpy.c ft_strjoin.c ft_strrchr.c ft_isascii.c \
	ft_memmove.c ft_strlcat.c  ft_tolower.c \
	ft_strmapi.c ft_substr.c ft_strjoin.c ft_strtrim.c \
	ft_itoa.c ft_striteri.c ft_putchar_fd.c ft_putstr_fd.c \
	ft_putendl_fd.c ft_putnbr_fd.c ft_split.c ft_memset.c\

BONUS = ft_lstnew.c ft_lstdelone.c ft_lstclear.c \
		ft_lstadd_front.c ft_lstadd_back.c ft_lstsize.c \
		ft_lstiter.c ft_lstmap.c ft_lstlast.c
CC = clang
CFLAGS = -Wall -Werror -Wextra
RM = rm -f
OBJS = ${SRCS:.c=.o}

BONUS_OBJS = ${BONUS:.c=.o}
NAME = libft.a

all : ${NAME}

$(NAME) : ${OBJS}
	ar rcs ${NAME} ${OBJS}
	echo "Partie obligatoire faite !"

.c.o:
	${CC} ${CFLAGS} -c $< -o ${<:.c=.o}

clean:
	${RM} ${OBJS} ${BONUS_OBJS}

fclean: clean
	${RM} ${NAME}

re: fclean all

bonus: ${BONUS_OBJS}
	ar rcs ${NAME} ${BONUS_OBJS}

.PHONY: all, clean, fclean, re
