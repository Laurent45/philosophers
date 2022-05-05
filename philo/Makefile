
SRCS			= $(addprefix srcs/, check_input.c error.c main.c)

HEADERS			= $(addprefix headers/, check_input.h error.h struct.h)

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
	${RM} ${NAME}

re: fclean all

debug: CFLAGS += -g
debug: all

.PHONY: all clean fclean re
