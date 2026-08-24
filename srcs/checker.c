/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wchan-ha <wchan-ha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/21 08:40:46 by wchan-ha          #+#    #+#             */
/*   Updated: 2026/08/24 11:57:31 by saalagor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	ft_error(t_stack **a, t_stack **b)
{
	if (a)
		free(a);
	if (b)
		free(b);
	write (2, "Error\n", 6);
	exit(EXIT_FAILURE);
}

static void	sort_based_on_arg(t_stack **a, t_stack **b,
	char *operation, t_bench *bench)
{
	bench->not_write = true;
	if (ft_strncmp(operation, "sa\n", 3) == 0)
		sa(a, bench);
	else if (ft_strncmp(operation, "sb\n", 3) == 0)
		sb(b, bench);
	else if (ft_strncmp(operation, "ss\n", 3) == 0)
		ss(a, b, bench);
	else if (ft_strncmp(operation, "pa\n", 3) == 0)
		pa(a, b, bench);
	else if (ft_strncmp(operation, "pb\n", 3) == 0)
		pb(a, b, bench);
	else if (ft_strncmp(operation, "ra\n", 3) == 0)
		ra(a, bench);
	else if (ft_strncmp(operation, "rb\n", 3) == 0)
		rb(b, bench);
	else if (ft_strncmp(operation, "rr\n", 3) == 0)
		rr(a, b, bench);
	else if (ft_strncmp(operation, "rra\n", 4) == 0)
		rra(a, bench);
	else if (ft_strncmp(operation, "rrb\n", 4) == 0)
		rrb(b, bench);
	else if (ft_strncmp(operation, "rrr\n", 4) == 0)
		rrr(a, b, bench);
	else
		ft_error(a, b);
}

int	main(int argc, char **argv)
{
	t_stack	*a;
	t_stack	*b;
	char	*line;
	t_bench	bench;

	if (argc < 2)
		return (0);
	a = NULL;
	b = NULL;
	init_stack_a(&a, argv + 1);
	line = get_next_line(0);
	while (line)
	{
		sort_based_on_arg(&a, &b, line, &bench);
		free(line);
		line = get_next_line(0);
	}
	if (is_sorted(a) && !b)
		write (1, "OK\n", 3);
	else
		write (1, "KO\n", 3);
	ft_free_stack(&a);
	ft_free_stack(&b);
	return (0);
}
