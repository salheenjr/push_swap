/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_medium.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saalagor <saalagor@student.42kl.edu.m      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/17 21:56:28 by saalagor          #+#    #+#             */
/*   Updated: 2026/08/18 19:11:33 by saalagor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../push_swap.h"

static int	get_range(int size)
{
	if (size <= 100)
		return (16);
	if (size <= 500)
		return (32);
	return (45);
}

static void	push_to_b(t_stack **a, t_stack **b, int range, t_bench *bench)
{
	int	i;

	i = 0;
	while (*a)
	{
		if ((*a)->index <= i)
		{
			pb(a, b, bench);
			rb(b, bench);
			i++;
		}
		else if ((*a)->index <= i + range)
		{
			pb(a, b, bench);
			i++;
		}
		else
			ra(a, bench);
	}
}

void	sort_medium(t_stack **a, t_stack **b, t_bench *bench)
{
	t_stack	*max_node;
	int		size;
	int		pos;

	if (!a || !*a)
		return ;
	assign_index(*a);
	push_to_b(a, b, get_range(ft_stacksize(*a)), bench);
	while (*b)
	{
		max_node = find_max(*b);
		pos = get_pos(*b, max_node);
		size = ft_stacksize(*b);
		while (*b != max_node)
		{
			if (pos <= size / 2)
				rb(b, bench);
			else
				rrb(b, bench);
		}
		pa(a, b, bench);
	}
}
