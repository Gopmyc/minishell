/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghoyaux <ghoyaux@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/24 09:07:19 by ghoyaux           #+#    #+#             */
/*   Updated: 2025/03/27 08:46:39 by ghoyaux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

/* --- BASE CONSTS --- */
# ifndef PROMPT
#  define PROMPT "Yes is a girou/minishell> "
# endif
/* ------------------ */

/* --- BASE LIBS --- */
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include <sys/types.h>
# include <sys/wait.h>
# include <sys/stat.h>
# include <signal.h>
# include <dirent.h>
# include <string.h>
# include <termios.h>
# include <curses.h>
# include <term.h>
# include <readline/readline.h>
# include <readline/history.h>
# include <sys/ioctl.h>
/* ------------------ */

/* --- CUSTOMS LIBS --- */
// TODO : LIBFT, ect.
/* ------------------ */

/* --- STRUCT --- */
typedef struct s_mem_node
{
	void				*address;
	struct s_mem_node	*next;
}	t_mem_node;

typedef struct s_mem_manager
{
	t_mem_node	*head;
}	t_mem_manager;
/* ------------------ */

/* --- FUNCT --- */
	/* Memory function(s) */
t_mem_manager	*init_mem_manager(void);
void			*mem_alloc(t_mem_manager *manager, size_t size);
void			free_all(t_mem_manager *manager);
int				destroy_mem_manager(t_mem_manager *manager);
void			ft_free_tbl(char **array, size_t j);

	/* Interactive(SIG) function(s) */
void			handle_sigint(int sig);
void			handle_sigquit(int sig);
void			setup_signals(void);

/* ------------------ */

// Use chained list for parsing
// Init all structs
// Init hidden file logs

#endif