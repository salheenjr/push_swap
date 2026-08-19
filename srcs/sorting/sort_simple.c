/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_simple.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saalagor <saalagor@student.42kl.edu.m      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/17 18:04:07 by saalagor          #+#    #+#             */
/*   Updated: 2026/08/18 19:08:58 by saalagor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../push_swap.h"

void	sort_simple(t_stack **a, t_stack **b, t_bench *bench)
{
	t_stack	*min_node;
	int		pos;
	int		size;

	if (!a || !*a)
		return ;
	while (*a)
	{
		min_node = find_min(*a);
		pos = get_pos(*a, min_node);
		size = ft_stacksize(*a);
		while (*a != min_node)
		{
			if (pos <= size / 2)
				ra(a, bench);
			else
				rra(a, bench);
		}
		pb(a, b, bench);
	}
	while (*b)
		pa(a, b, bench);
}
