
SRCS			= $(addprefix srcs/, check_input.c clear.c error.c init.c\
				  philo.c routine.c time.c main.c)

HEADERS			= $(addprefix headers/, check_input.h error.h struct.h philo.h\
				  init.h clear.h time.h routine.h)

OBJS			= ${SRCS:.c=.o}

NAME			= philo

CC				= gcc
RM				= rm -f
CFLAGS			= -Wall -Wextra -Werror

%.o: %.c ${HEADERS}
	${CC} ${CFLAGS} -Iheaders/ -c $< -o ${<:.c=.o}

${NAME}: ${OBJS}
	${CC} ${CFLAGS} -pthread -o ${NAME} ${OBJS}

all: ${NAME}

clean:
	${RM} ${OBJS}

fclean: clean
	${RM} ${NAME} philo_debug

re: fclean all

debug: CFLAGS	+= -g
debug: NAME		 = philo_debug
debug: re

.PHONY: all clean fclean re
