# **************************************************************************** #
#                                  Makefile                                    #
# **************************************************************************** #

NAME = minishell

SRCDIR = src
OBJDIR = .obj
INCDIR = includes

SRCS = src/main.c \
       src/utiles/memory.c \
       src/utiles/utils.c \
       src/utiles/gnl.c \
       src/interactive/ctrl.c

# Remplacer les chemins des fichiers sources pour pointer vers les objets dans .obj
OBJS = $(SRCS:$(SRCDIR)/%.c=$(OBJDIR)/%.o)

CC = gcc
CFLAGS = -Wall -Werror -Wextra -I $(INCDIR)
LDFLAGS = -lreadline

# Règle pour générer les fichiers objets en maintenant la structure des sous-dossiers
$(OBJDIR)/%.o: $(SRCDIR)/%.c
	# Créer les répertoires nécessaires dans .obj
	@mkdir -p $(OBJDIR)/$(dir $*)
	$(CC) $(CFLAGS) -c $< -o $@

# Règle de construction de l'exécutable
$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) $(LDFLAGS) -o $(NAME)

# Règle all
all: $(NAME)

# Règle clean pour supprimer les fichiers objets
clean:
	rm -rf $(OBJDIR)

# Règle fclean pour supprimer l'exécutable et les fichiers objets
fclean: clean
	rm -f $(NAME)

# Règle re pour nettoyer et reconstruire
re: fclean all

.PHONY: all clean fclean re
