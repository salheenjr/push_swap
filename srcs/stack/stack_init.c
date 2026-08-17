/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_init.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wchan-ha <wchan-ha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/15 17:10:00 by saalagor          #+#    #+#             */
/*   Updated: 2026/08/17 15:55:11 by wchan-ha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../push_swap.h"

long	ft_atol(const char *str)
{
	long	num;
	int		sign;
	int		i;

	i = 0;
	num = 0;
	sign = 1;
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == ' ')
		i++;
	if (str[i] == '-')
	{
		sign = -1;
		i++;
	}
	else if (str[i] == '+')
		i++;
	while (str[i] >= '0' && str[i] <= '9')
	{
		num = (num * 10) + (str[i] - '0');
		i++;
	}
	return (num * sign);
}

int	is_number(char *str)
{
	int	i;

	if (!str)
		return (0);
	i = 0;
	if (str[i] == '-' || str[i] == '+')
		i++;
	if (!str[i])
		return (0);
	while (str[i])
	{
		if (!(str[i] >= '0' && str[i] <= '9'))
			return (0);
		i++;
	}
	return (1);
}

int	has_duplicate(t_stack *a, int n)
{
	if (!a)
		return (0);
	while (a)
	{
		if (a->value == n)
			return (1);
		a = a->next;
	}
	return (0);
}

void	init_stack_a(t_stack **a, char **argv)
{
	t_stack	*new_node;
	int		i;
	long	value;

	i = 1;
	while (argv[i])
	{
		if (!is_number(argv[i]))
		{
			ft_free_stack(a);
			write(2, "Error\n", 6);
			exit(EXIT_FAILURE);
		}
		value = ft_atol(argv[i]);
		if (value < INT_MIN || value > INT_MAX || has_duplicate(*a, (int)value))
		{
			ft_free_stack(a);
			write(2, "Error\n", 6);
			exit(EXIT_FAILURE);
		}
		new_node = ft_stacknew((int)value);
		if (!new_node)
		{
			ft_free_stack(a);
			exit(EXIT_FAILURE);
		}
		ft_stackadd_back(a, new_node);
		i++;
	}
}
