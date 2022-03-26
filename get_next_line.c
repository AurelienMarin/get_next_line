/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aumarin <aumarin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/16 14:11:19 by aumarin           #+#    #+#             */
/*   Updated: 2022/03/26 15:59:26 by aumarin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*new_str;
	size_t	total_len;
	size_t	i;
	size_t	s1_len;

	i = 0;
	s1_len = ft_strlen(s1);
	total_len = (s1_len + ft_strlen(s2));
	new_str = malloc(sizeof(char) * (total_len + 1));
	if (new_str == NULL)
		return (NULL);
	while (i < total_len)
	{
		if (i < s1_len)
			new_str[i] = s1[i];
		else
			new_str[i] = s2[i - s1_len];
		i++;
	}
	new_str[i] = '\0';
	free((char *)s1);
	return (new_str);
}

char	*wrap_line(char *line)
{
	size_t	i;
	size_t	j;
	char	*wrapped_line;

	i = 0;
	j = 0;
	while (line[i] != '\n' && line[i])
		i++;
	wrapped_line = malloc(sizeof(char) * (i + 2));
	if (wrapped_line == NULL)
		return (NULL);
	while (line[j] != '\n' && line[j])
	{
		wrapped_line[j] = line[j];
		j++;
	}
	wrapped_line[j] = '\n';
	wrapped_line[j + 1] = '\0';
	free(line);
	return (wrapped_line);
}

void	update_buffer(char *buffer)
{
	char	*tmp;
	char	*strchr_result;

	strchr_result = ft_strchr(buffer, '\n');
	if (strchr_result)
	{
		tmp = ft_strdup(strchr_result + 1);
		ft_bzero(buffer, BUFFER_SIZE);
		ft_strlcpy(buffer, tmp, BUFFER_SIZE);
		free(tmp);
	}
	else
		ft_bzero(buffer, BUFFER_SIZE);
}

char	*get_next_line(int fd)
{
	static char	buffer[BUFFER_SIZE + 1];
	char		*line;

	if (fd < 0)
		return (NULL);
	line = NULL;
	if (ft_strlen(buffer) > 0)
	{
		line = ft_strjoin(line, buffer);
		update_buffer(buffer);
	}
	while (!ft_strchr(line, '\n'))
	{
		if (read(fd, buffer, BUFFER_SIZE) < 1)
		{
			if (!line)
				return (NULL);
			return (ft_strjoin(line, buffer));
		}
		buffer[BUFFER_SIZE] = '\0';
		line = ft_strjoin(line, buffer);
		update_buffer(buffer);
	}
	return (wrap_line(line));
}
