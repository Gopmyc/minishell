/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   memory.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghoyaux <ghoyaux@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/09 11:10:23 by ghoyaux           #+#    #+#             */
/*   Updated: 2025/02/26 20:56:51 by ghoyaux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

t_mem_manager	*init_mem_manager(void)
{
	t_mem_manager	*manager;

	manager = (t_mem_manager *)malloc(sizeof(t_mem_manager));
	if (!(manager))
		exit(1);
	manager->head = NULL;
	return (manager);
}

void	*mem_alloc(t_mem_manager *manager, size_t size)
{
	void		*ptr;
	t_mem_node	*new_node;

	if (!(manager) || size == 0)
		return (NULL);
	ptr = malloc(size);
	if (!ptr)
		return (NULL);
	new_node = (t_mem_node *)malloc(sizeof(t_mem_node));
	if (!(new_node))
	{
		free(ptr);
		return (NULL);
	}
	new_node->address = ptr;
	new_node->next = manager->head;
	manager->head = new_node;
	return (ptr);
}

void	free_all(t_mem_manager *manager)
{
	t_mem_node	*current;
	t_mem_node	*tmp;

	if (!(manager))
		return ;
	current = manager->head;
	while (current)
	{
		free(current->address);
		tmp = current;
		current = current->next;
		free(tmp);
	}
	manager->head = NULL;
}

int	destroy_mem_manager(t_mem_manager *manager)
{
	if (!(manager))
		return (1);
	free_all(manager);
	free(manager);
	return (0);
}

void	ft_free_tbl(char **array, size_t j)
{
	while (j > 0)
		free(array[--j]);
	free(array);
}
