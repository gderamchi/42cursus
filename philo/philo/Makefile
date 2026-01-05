NAME		:= philo

CC			:= cc
CFLAGS		:= -Wall -Wextra -Werror
CPPFLAGS	:= -I.
LDFLAGS		:= -pthread

SRCS		:= main.c \
               parsing.c \
               init.c \
               dinner.c \
               monitor.c \
               write.c \
               getters_setters.c \
               safe_functions.c \
               synchro_utils.c \
               clean.c \
               utils.c

OBJDIR		:= .obj
OBJS		:= $(SRCS:%.c=$(OBJDIR)/%.o)

RM			:= rm -rf

.PHONY: all clean fclean re

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) $(LDFLAGS) -o $@

$(OBJDIR)/%.o: %.c main.h | $(OBJDIR)
	$(CC) $(CFLAGS) $(CPPFLAGS) -c $< -o $@

$(OBJDIR):
	mkdir -p $(OBJDIR)

clean:
	$(RM) $(OBJDIR)

fclean: clean
	$(RM) $(NAME)

re: fclean all
