SRCS	= main.c 

SRCSBON	=

INC		= -I includes

OBJS	= ${SRCS:.c=.o}

OBJSBON	= ${SRCSBON:.c=.o}

NAME 	= so_long

CC 		= gcc

RM 		= rm -f

CFLAGS	= -Wall -Wextra -Werror #-g3 -fsanitize=address

.c.o :
			${CC} ${CFLAGS} ${INC} -o $@ -c $<

${NAME}:	${OBJS} 
			${CC}  ${CFLAGS} ${OBJS} -o ${NAME}

bonus:		${OBJS} ${OBJSBON} 
			${CCLIB} ${OBJS} ${OBJSBON}

all:		${NAME}

clean:		
			${RM} ${OBJS} ${OBJSBON}

fclean:		clean
			${RM} ${NAME} 

re:			fclean all

.PHONY:		all clean fclean re bonus