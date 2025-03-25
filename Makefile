# **************************************************************************** #
#                                  Makefile                                    #
# **************************************************************************** #

NAME = minishell

# COLORS

BLUE				= 		\033[1;34m
GREEN				= 		\033[1;32m
YELLOW				=		\033[1;33m
CYAN				=		\033[1;36m
RESET				= 		\033[0m

# COMMANDS

RM					=		/usr/bin/rm -fr
ECHO				=		/usr/bin/echo
RM_LINE 			= 		@tput cuu1 && tput el

# FLAGS && COMPIL

CC = gcc
CFLAGS = -Wall -Werror -Wextra -g
LIBFLAGS = -L/usr/lib -lX11 -lXext -lXrandr -lXi -lXinerama -lXcursor -lm
IFLAGS = -I$(INC_DIR)


SRCDIR = src
OBJDIR = .obj
INCDIR = includes
BUILTINS = builtins


BUILTINS_SRCS = $(wildcard $(BUILTINS)/*.c)

SRCS = src/main.c
SRCS += $(BUILTINS_SRCS)
OBJS = $(SRCS:src/%.c=$(OBJDIR)/%.o)

# LIBFT COMPILATION

LIBFT_GIT			= 		https://github.com/LaGuibole/Libft_Boosted.git
LIBFT_DIR			= 		Libft_Boosted
LIBFT_PATH			= 		$(LIB_DIR)/$(LIBFT_DIR)
LIBFT_H				= 		libft.h
LIBFT_H_PATH		= 		$(LIBFT_PATH)/includes/$(LIBFT_H)
LIBFT_INC_H			= 		$(INC_DIR)/$(LIBFT_H)
LIBFT_TARGET		= 		libft.a
LIBFT_TARGET_PATH	= 		$(LIBFT_PATH)/$(LIBFT_TARGET)


$(OBJDIR)/%.o: src/%.c | $(OBJDIR)
	$(CC) $(CFLAGS) -c $< -o $@

$(OBJDIR):
	mkdir -p $(OBJDIR)

$(NAME): $(OBJDIR) $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

# RULES

all: $(NAME)

clean:
	rm -rf $(OBJDIR)

fclean: clean
	rm -f $(NAME)

re: fclean all

cleanlibs:
							@$(MAKE) clean --no-print-directory -C $(LIBFT_PATH)
							@$(MAKE) clean --no-print-directory -C $(MLX_PATH)

fcleanlibs: fclean
							@$(RM) -r $(LIBFT_PATH)
							@$(RM) -r $(MLX_PATH)

relibs: fcleanlibs $(LIBFT_INC_H) $(MLX_INC_H)

norminette:
							@norminette $(SRC_DIR) $(BONUS_SRC) $(INC_DIR) | grep -Ev '^Notice|OK!$$'	\
							&& $(ECHO) -e '\033[1;31mNorminette KO!'						\
							|| $(ECHO) -e '\033[1;32mNorminette OK!'

.PHONY: all clean fclean re cleanlibs fcleanlibs relibs norminette

$(LIBFT_INC_H): $(LIBFT_TARGET)
							@cp $(LIBFT_H_PATH) $@

$(LIBFT_TARGET):
							@if [ ! -d "$(LIBFT_PATH)/.git" ]; then \
								printf "Cloning lib \"%s\" into \"%s\"..." $(LIBFT_GIT) $(LIBFT_PATH);\
								git clone $(LIBFT_GIT) $(LIBFT_PATH);\
							fi
							@printf "\nMaking \"%s\"..." $@
							@$(MAKE) --no-print-directory -C $(LIBFT_PATH)
							@cp $(LIBFT_TARGET_PATH) ./
							@printf "\n✅ Done copying archive $(GREEN) \"%s\" $(RESET)... \n\n" $@