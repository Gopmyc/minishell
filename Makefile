# **************************************************************************** #
#                                  Makefile                                    #
# **************************************************************************** #

NAME = minishell

SRCDIR = src
OBJDIR = .obj
INCDIR = includes

SRCS = src/main.c \
       src/utiles/memory.c \
	   src/interactive/ctrl.c

OBJS = $(SRCS:$(SRCDIR)/%.c=$(OBJDIR)/%.o)

CC = gcc
CFLAGS = -Wall -Werror -Wextra -I $(INCDIR)
LDFLAGS = -lreadline

$(OBJDIR)/%.o: $(SRCDIR)/%.c
	mkdir -p $(dir $@)
	$(CC) $(CFLAGS) -c $< -o $@

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) $(LDFLAGS) -o $(NAME)

all: $(NAME)

clean:
	rm -rf $(OBJDIR)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re