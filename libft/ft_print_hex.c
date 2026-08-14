/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_hex.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saalagor <saalagor@student.42kl.edu.m      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/08 13:21:41 by saalagor          #+#    #+#             */
/*   Updated: 2026/08/08 15:42:35 by saalagor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	ft_put_hex(unsigned int num, char specifier)
{
	if (num >= 16)
	{
		ft_put_hex(num / 16, specifier);
		ft_put_hex(num % 16, specifier);
	}
	else
	{
		if (num <= 9)
			ft_print_char(num + '0');
		else if (specifier == 'x')
			ft_print_char(num - 10 + 'a');
		else if (specifier == 'X')
			ft_print_char(num - 10 + 'A');
	}
}

static int	ft_hex_len(unsigned int num)
{
	int	len;

	len = 0;
	while (num > 0)
	{
		len++;
		num /= 16;
	}
	return (len);
}

int	ft_print_hex(unsigned int num, char specifier)
{
	if (num == 0)
		return (ft_print_char('0'));
	ft_put_hex(num, specifier);
	return (ft_hex_len(num));
}
