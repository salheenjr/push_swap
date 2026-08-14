/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saalagor <saalagor@student.42kl.edu.m      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/29 16:13:31 by saalagor          #+#    #+#             */
/*   Updated: 2026/07/29 16:34:26 by saalagor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t amount, size_t size)
{
	void	*ptr;

	if (amount != 0 && (amount * size) / amount != size)
		return (NULL);
	ptr = malloc(amount * size);
	if (!ptr)
		return (NULL);
	ft_bzero(ptr, amount * size);
	return (ptr);
}
