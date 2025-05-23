/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gnl.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghoyaux <ghoyaux@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/01 03:45:51 by ghoyaux           #+#    #+#             */
/*   Updated: 2025/04/01 03:46:09 by ghoyaux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

static char	*ft_malloc_size(char **line, char *buf, t_mem_manager *manager)
{
	char	*ret;
	int		line_len;
	int		buf_len;

	line_len = 0;
	while (*line && (*line)[line_len] && (*line)[line_len] != '\n')
		line_len++;
	buf_len = 0;
	while (buf[buf_len] && buf[buf_len] != '\n')
		buf_len++;
	ret = (char *)mem_alloc(manager, sizeof(char) * (buf_len + line_len + 1));
	if (!ret)
		return (NULL);
	return (ret);
}

static int	ft_add_to_line(char **line, char *buf, t_mem_manager *manager)
{
	char	*tmp;
	int		i;
	int		j;

	tmp = ft_malloc_size(line, buf, manager);
	if (!tmp)
		return (-1);
	i = 0;
	j = 0;
	while (*line && (*line)[i] && (*line)[i] != '\n')
		tmp[i++] = (*line)[j++];
	j = 0;
	while (buf[j] && buf[j] != '\n')
		tmp[i++] = buf[j++];
	tmp[i] = buf[j];
	*line = tmp;
	i = 0;
	while (buf[j])
		buf[i++] = buf[++j];
	buf[i] = '\0';
	i = 0;
	while ((*line)[i] && (*line)[i] != '\n')
		i++;
	return (i);
}

static int	ft_get_next_line(int fd, char **line, t_mem_manager *manager)
{
	static char		buf[FD_MAX][BUFFER_SIZE + 1];
	int				ret;

	*line = NULL;
	ret = ft_add_to_line(line, buf[fd], manager);
	while (ret != -1 && (*line)[ret] != '\n')
	{
		ret = read(fd, buf[fd], BUFFER_SIZE);
		if (ret < 1)
			return (ret);
		buf[fd][ret] = '\0';
		ret = ft_add_to_line(line, buf[fd], manager);
	}
	if (ret == -1)
		return (-1);
	(*line)[ret] = '\0';
	return (1);
}

int	get_next_line(int fd, char **line, t_mem_manager *manager)
{
	if (fd < 0 || fd > FD_MAX || !line || BUFFER_SIZE < 1)
		return (-1);
	return (ft_get_next_line(fd, line, manager));
}