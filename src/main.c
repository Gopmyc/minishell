/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghoyaux <ghoyaux@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/24 09:06:53 by ghoyaux           #+#    #+#             */
/*   Updated: 2025/04/01 04:01:40 by ghoyaux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
		write(1, PROMPT, ft_strlen(PROMPT));
		if (get_next_line(0, &input, manager) <= 0)
			break ;
		if (*input)
			add_history(input); // leak a cause de add_history, recoder un add_history avec le memory manager
	}
	write_history(".minishell_history");
	return (destroy_mem_manager(manager));
}