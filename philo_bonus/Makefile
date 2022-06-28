
SRCS			= $(addprefix srcs/, check_input_bonus.c error_bonus.c\
				  semaphore_bonus.c philo_bonus.c routine_bonus.c\
				  time_bonus.c main_bonus.c)

HEADERS			= $(addprefix headers/, check_input_bonus.h error_bonus.h\
				  struct_bonus.h philo_bonus.h time_bonus.h routine_bonus.h\
				  semaphore_bonus.h)

OBJS			= ${SRCS:.c=.o}

NAME			= philo_bonus

CC				= gcc
RM				= rm -f
CFLAGS			= -Wall -Wextra -Werror

%.o: %.c ${HEADERS}
	${CC} ${CFLAGS} -Iheaders/ -c $< -o ${<:.c=.o}

${NAME}: ${OBJS}
	${CC} ${CFLAGS} -pthread -o ${NAME} ${OBJS}

all: ${NAME}

bonus: all

clean:
	${RM} ${OBJS}

fclean: clean
	${RM} ${NAME}

re: fclean all

.PHONY: all clean fclean re bonus
