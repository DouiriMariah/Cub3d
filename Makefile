SRCS		=	srcs/color_info.c \
		srcs/cub.c \
		srcs/free_fct.c \
		srcs/get_mapinfo.c \
		srcs/hook3d.c \
		srcs/init.c \
		srcs/parsing_utils.c \
		srcs/parsing.c \
		srcs/texture.c \
		srcs/main.c \
		srcs/window.c \
		srcs/raycasting.c \
		srcs/move3d.c \
		srcs/get_next_line.c \
		srcs/get_next_line_utils.c \
		srcs/error.c \
		srcs/utils.c \
		srcs/check.c \
		srcs/utils_color.c \
		srcs/tox.c


OBJS 		= ${SRCS:.c=.o}

UNAME		:= $(shell uname)

CC 			= clang
CFLAGS		= -Wall -Wextra -Werror -g3
RM			= rm -f
NAME		= cub3d
FLAGS		= -lXext -lX11 -lm ./Libft/libft.a ./mlx/libmlx.a ./mlx/libmlx_Linux.a 

all: 		 ./Libft/libft.a ${NAME}

.c.o:
			${CC} ${CFLAGS} -Imlx -c $< -o ${<:.c=.o}

$(NAME): 	./mlx/libmlx.a  $(OBJS)
			${CC} $(CFLAGS) -o $(NAME) $(OBJS) $(FLAGS)

./Libft/libft.a:
	make -s -C ./Libft

./mlx/libmlx.a :
	make -s -C ./mlx

clean:
			${RM} ${OBJS} $(BOBJS)

fclean: 	clean
			${RM} ${NAME} $(NAMEBONUS)

re: 		fclean all
