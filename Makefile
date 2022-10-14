NAME = push_swap

SRCS = ft_atoi.c move1.c move2.c sort.c check.c check_args.c ft_split.c index.c move.c main.c push_swap.c radix.c t_list.c utils.c 

OBJS = ${SRCS:.c=.o}

CC = gcc
CFLAGS = -Wall -Wextra -Werror

RM = rm -rf

all: ${NAME} ${CHECK}
${NAME}: ${OBJS}
	${CC} ${CFLAGS} ${OBJS} -o ${NAME}

clean: 
	${RM} ${OBJS}

fclean: clean
	${RM} ${NAME}

re: fclean all

.PHONY: all clean fclean re
