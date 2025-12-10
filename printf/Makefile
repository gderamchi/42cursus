SRC			= ft_printf printf_utils

SRCS		= $(addsuffix .c, ${SRC})

HEAD		= ./includes/

OBJS		= ${SRCS:.c=.o}

NAME		= libftprintf.a

CC			= gcc
RM			= rm -f
AR			= ar rc
RN			= ranlib

CFLAGS		= -Wall -Wextra -Werror

.c.o:
			${CC} ${CFLAGS} -c $< -o ${<:.c=.o}

$(NAME):	${OBJS}
			${AR} ${NAME} ${OBJS}
			${RN} ${NAME}

all:		$(NAME)

clean:
			${RM} ${OBJS} ${B_OBJS}

fclean:		clean
			${RM} $(NAME)

.PHONY:		all bonus clean fclean re
