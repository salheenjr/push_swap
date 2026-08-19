/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_init.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saalagor <saalagor@student.42kl.edu.m      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/18 15:36:23 by saalagor          #+#    #+#             */
/*   Updated: 2026/08/18 17:52:51 by saalagor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../push_swap.h"

static void	free_split(char **split)
{
	int	i;

	if (!split)
		return ;
	i = 0;
	while (split[i])
	{
		free(split[i]);
		i++;
	}
	free(split);
}

static void	parse_error(t_stack **a, char **split)
{
	if (split)
		free_split(split);
	ft_free_stack(a);
	write(2, "Error\n", 6);
	exit(EXIT_FAILURE);
}

static void	process_arg(t_stack **a, char *str, char **split)
{
	long	val;
	t_stack	*node;

	if (!is_number(str))
		parse_error(a, split);
	val = ft_atol(str);
	if (val < INT_MIN || val > INT_MAX || has_duplicate(*a, (int)val))
		parse_error(a, split);
	node = ft_stacknew((int)val);
	if (!node)
		parse_error(a, split);
	ft_stackadd_back(a, node);
}

void	init_stack_a(t_stack **a, char **argv)
{
	int		i;
	int		j;
	char	**split;

	i = 0;
	while (argv[i])
	{
		split = ft_split(argv[i], ' ');
		if (!split || !split[0])
			parse_error(a, split);
		j = 0;
		while (split[j])
		{
			process_arg(a, split[j], split);
			j++;
		}
		free_split(split);
		i++;
	}
	assign_index(*a);
}
