/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saalagor <saalagor@student.42kl.edu.m      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/08 11:45:31 by saalagor          #+#    #+#             */
/*   Updated: 2026/08/14 11:20:12 by saalagor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	handle_specifier(char spec, va_list args)
{
	int	count;

	count = 0;
	if (spec == 'c')
		count += ft_print_char(va_arg(args, int));
	else if (spec == 's')
		count += ft_print_str(va_arg(args, char *));
	else if (spec == 'p')
		count += ft_print_ptr((unsigned long long)va_arg(args, void *));
	else if (spec == 'd' || spec == 'i')
		count += ft_print_nbr(va_arg(args, int));
	else if (spec == 'u')
		count += ft_print_unsigned(va_arg(args, unsigned int));
	else if (spec == 'x' || spec == 'X')
		count += ft_print_hex(va_arg(args, unsigned int), spec);
	else if (spec == '%')
		count += ft_print_char('%');
	return (count);
}

int	ft_printf(const char *format, ...)
{
	va_list	args;
	int		i;
	int		total_len;

	if (!format)
		return (-1);
	va_start(args, format);
	i = 0;
	total_len = 0;
	while (format[i])
	{
		if (format[i] == '%')
		{
			i++;
			if (format[i])
				total_len += handle_specifier(format[i], args);
		}
		else
			total_len += ft_print_char(format[i]);
		if (format[i])
			i++;
	}
	va_end(args);
	return (total_len);
}
