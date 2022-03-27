SRCS	= main.c get_next_line.c get_next_line_utils.c map.c param_verif_map.c tool.c error.c

SRCSBON	=

INC		= -I includes -I mlx_linux -I /usr/include

OBJS	= ${SRCS:.c=.o}

OBJSBON	= ${SRCSBON:.c=.o}

NAME 	= so_long

CC 		= clang

RM 		= rm -f

CFLAGS	= -Wall -Wextra -Werror -O3 #-fsanitize=address

.c.o :
			$(CC) -Wall -Wextra -Werror -I/usr/include -Imlx_linux -O3 -c $< -o $@

${NAME}:	${OBJS}
			@make --no-print-directory -C mlx_linux
			$(CC) $(OBJS) -Lmlx_linux -lmlx -L/usr/lib -Imlx_linux -lXext -lX11 -lm -lz -o $(NAME)

bonus:		${OBJS} ${OBJSBON} 
			${CCLIB} ${OBJS} ${OBJSBON}

all:		${NAME}

clean:		
			${RM} ${OBJS} ${OBJSBON}

fclean:		clean
			${RM} ${NAME}
			@make clean --no-print-directory  -C mlx_linux/

re:			fclean all

.PHONY:		all clean fclean re bonus