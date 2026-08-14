/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_nbr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saalagor <saalagor@student.42kl.edu.m      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/08 14:47:24 by saalagor          #+#    #+#             */
/*   Updated: 2026/08/08 15:11:58 by saalagor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	ft_put_nbr(long n)
{
	if (n < 0)
	{
		ft_print_char('-');
		n = -n;
	}
	if (n >= 10)
		ft_put_nbr(n / 10);
	ft_print_char((n % 10) + '0');
}

static int	ft_nbr_len(long n)
{
	int	len;

	len = 0;
	if (n <= 0)
	{
		len++;
		n = -n;
	}
	while (n > 0)
	{
		len++;
		n /= 10;
	}
	return (len);
}

int	ft_print_nbr(int n)
{
	ft_put_nbr((long)n);
	return (ft_nbr_len((long)n));
}
