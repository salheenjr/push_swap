/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wchan-ha <wchan-ha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/11 15:04:34 by wchan-ha          #+#    #+#             */
/*   Updated: 2026/08/22 08:31:19 by wchan-ha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*ft_strcopy(char *stash, char *buffer, size_t size, size_t s_len)
{
	size_t	i;
	size_t	j;
	char	*new;

	i = 0;
	j = 0;
	new = (char *)malloc(size);
	if (!new)
		return (free(stash), NULL);
	while (i < size - 1)
	{
		if (i < s_len)
			new[i] = stash[i];
		else
		{
			new[i] = buffer[j];
			j++;
		}
		i++;
	}
	new[i] = 0;
	return (free(stash), new);
}

char	*ft_strjoin_get(char *stash, char *buffer)
{
	size_t	s_len;
	size_t	b_len;
	size_t	size;

	if (!buffer)
		return (free(stash), NULL);
	if (!stash)
		s_len = 0;
	else
		s_len = ft_strlen(stash);
	b_len = ft_strlen(buffer);
	size = s_len + b_len + 1;
	return (ft_strcopy(stash, buffer, size, s_len));
}
