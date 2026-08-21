/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wchan-ha <wchan-ha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/21 08:40:46 by wchan-ha          #+#    #+#             */
/*   Updated: 2026/08/21 12:06:56 by wchan-ha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	sort_based_on_arg(t_stack **a, t_stack **b, char *operation)
{
	if (ft_strncmp(operation, "sa\n", 4) == 0)
		sa(a, NULL);
	else if (ft_strncmp(operation, "sb\n", 4) == 0)
		sb(b, NULL);
	else if (ft_strncmp(operation, "ss\n", 4) == 0)
		ss(a, b, NULL);
	else if (ft_strncmp(operation, "pa\n", 4) == 0)
		pa(a, b, NULL);
	else if (ft_strncmp(operation, "pb\n", 4) == 0)
		pb(a, b, NULL);
	else if (ft_strncmp(operation, "ra\n", 4) == 0)
		ra(a, NULL);
	else if (ft_strncmp(operation, "rb\n", 4) == 0)
		rb(b, NULL);
	else if (ft_strncmp(operation, "rr\n", 4) == 0)
		rr(a, b, NULL);
	else if (ft_strncmp(operation, "rra\n", 5) == 0)
		rra(a, NULL);
	else if (ft_strncmp(operation, "rrb\n", 5) == 0)
		rrb(b, NULL);
	else if (ft_strncmp(operation, "rrr\n", 5) == 0)
		rrr(a, b, NULL);
	else
		write (2, "Error\n", 6);
}

int	main(int argc, char **argv)
{
	t_stack	*a;
	t_stack	*b;
	char	*line;

	if (argc < 2)
		return (0);
	a = NULL;
	b = NULL;
	init_stack_a(&a, argv + 1);
	while (1)
	{
		line = get_next_line(0);
		if (!line)
			break ;
		sort_based_on_arg(&a, &b, line);
		free(line);
	}
	if (is_sorted(a) && !b)
		write (1, "OK\n", 3);
	else
		write (1, "KO\n", 3);
	ft_free_stack(&a);
	ft_free_stack(&b);
	return (0);
}
