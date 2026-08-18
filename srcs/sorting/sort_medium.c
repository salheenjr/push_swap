/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_medium.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saalagor <saalagor@student.42kl.edu.m      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/17 21:56:28 by saalagor          #+#    #+#             */
/*   Updated: 2026/08/18 13:49:13 by saalagor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../push_swap.h"

static void	push_to_b(t_stack **a, t_stack **b, int range)
{
	int	i;

	i = 0;
	while (*a)
	{
		if ((*a)->index <= i)
		{
			pb(a, b);
			rb(b);
			i++;
		}
		else if ((*a)->index <= i + range)
		{
			pb(a, b);
			i++;
		}
		else
			ra(a);
	}
}

void	sort_medium(t_stack **a, t_stack **b)
{
	t_stack	*max_node;

	if (!a || !*a)
		return ;
	assign_index(*a);
	if (ft_stacksize(*a) <= 100)
		push_to_b(a, b, 15);
	else
		push_to_b(a, b, 35);
	while (*b)
	{
		max_node = find_max(*b);
		while (*b != max_node)
		{
			if (get_pos(*b, max_node) <= ft_stacksize(*b) / 2)
				rb(b);
			else
				rrb(b);
		}
		pa(a, b);
	}
}
