/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_simple.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saalagor <saalagor@student.42kl.edu.m      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/17 18:04:07 by saalagor          #+#    #+#             */
/*   Updated: 2026/08/17 19:36:50 by saalagor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../push_swap.h"

void	sort_simple(t_stack **a, t_stack **b)
{
	t_stack	*min_node;
	int		pos;

	if (!a || !*a)
		return ;
	while (*a)
	{
		min_node = find_min(*a);
		pos = get_pos(*a, min_node);
		while (*a != min_node)
		{
			if (pos <= ft_stacksize(*a) / 2)
				ra(a);
			else
				rra(a);
		}
		pb(a, b);
	}
	while (*b)
		pa(a, b);
}
