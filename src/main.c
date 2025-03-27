/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghoyaux <ghoyaux@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/24 09:06:53 by ghoyaux           #+#    #+#             */
/*   Updated: 2025/03/27 08:50:29 by ghoyaux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

#include "../includes/minishell.h"

int	main(int ac, char **av, char **env)
{
	t_mem_manager	*manager;
	char			*input;

	(void)ac;
	(void)av;
	(void)env;

	manager = init_mem_manager();
	if (!(manager))
		return (1);

	setup_signals();
	read_history(".minishell_history");
	while (1)
	{
		input = readline(PROMPT);
		if (!(input))
			break ;
		if (*input)
			add_history(input);
		free(input);
	}

	write_history(".minishell_history");
	return (destroy_mem_manager(manager));
}