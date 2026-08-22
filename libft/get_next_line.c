/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wchan-ha <wchan-ha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/08 10:36:01 by wchan-ha          #+#    #+#             */
/*   Updated: 2026/08/22 08:30:34 by wchan-ha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include "libft.h"

static char	*formatting_stash(char	*stash);
static char	*extract_line_stash(char *stash);
static int	stash_has_newline(char *stash);
static char	*read_to_stash(char *buffer, char *stash, int fd);

char	*get_next_line(int fd)
{
	char		*buffer;
	static char	*stash;
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (0);
	buffer = (char *)malloc(BUFFER_SIZE + 1);
	if (!buffer)
		return (NULL);
	stash = read_to_stash(buffer, stash, fd);
	free(buffer);
	if (!stash || stash[0] == 0)
		return (free(stash), stash = NULL, NULL);
	line = extract_line_stash(stash);
	stash = formatting_stash(stash);
	return (line);
}

static char	*read_to_stash(char *buffer, char *stash, int fd)
{
	ssize_t		read_status;

	read_status = 1;
	while (!stash_has_newline(stash) && read_status > 0)
	{
		read_status = read(fd, buffer, BUFFER_SIZE);
		if (read_status < 0)
		{
			free(stash);
			return (NULL);
		}
		buffer[read_status] = 0;
		stash = ft_strjoin_get(stash, buffer);
	}
	return (stash);
}

static int	stash_has_newline(char *stash)
{
	size_t	i;

	i = 0;
	if (!stash)
		return (0);
	while (stash[i])
	{
		if (stash[i] == '\n')
			return (1);
		i++;
	}
	return (0);
}

static char	*extract_line_stash(char *stash)
{
	char	*new;
	size_t	i;

	i = 0;
	while (stash[i] != '\n' && stash[i])
		i++;
	if (stash[i] == '\n')
		new = (char *)malloc((i + 2) * sizeof(char));
	else
		new = (char *)malloc((i + 1) * sizeof(char));
	if (!new)
		return (free(stash), NULL);
	i = 0;
	while (stash[i] != '\n' && stash[i])
	{
		new[i] = stash[i];
		i++;
	}
	if (stash[i] == '\n')
	{
		new[i] = '\n';
		i++;
	}
	new[i] = 0;
	return (new);
}

static char	*formatting_stash(char	*stash)
{
	char	*new;
	size_t	stash_len;
	size_t	j;
	size_t	k;

	if (!stash)
		return (0);
	stash_len = ft_strlen(stash);
	j = 0;
	while (stash[j] != '\n' && j < stash_len)
		j++;
	if (!stash[j])
		return (free(stash), NULL);
	j++;
	new = (char *)malloc(stash_len - j + 1);
	if (!new)
		return (free(stash), NULL);
	k = 0;
	while (j < stash_len)
		new[k++] = stash[j++];
	new[k] = 0;
	return (free(stash), new);
}
/*#include "get_next_line.h"
#include <stdio.h>
#include <fcntl.h>

int	main(void)
{
	char	*s;
	int		i;
	int		fd;

	i = 0;
	fd = open("test.txt", O_RDONLY);
	while (i < 5)
	{
		s = get_next_line(54);
		printf("%s", s);
		free(s);
		i++;
	}
	printf("%s", get_next_line(42));
	return (0);
}*/
