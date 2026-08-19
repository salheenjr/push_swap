/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_small.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saalagor <saalagor@student.42kl.edu.m      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/16 13:37:35 by saalagor          #+#    #+#             */
/*   Updated: 2026/08/18 18:57:12 by saalagor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../push_swap.h"

void	sort_2(t_stack **a, t_bench *bench)
{
	if (!a || !*a || !(*a)->next)
		return ;
	if ((*a)->value > (*a)->next->value)
		sa(a, bench);
}

void	sort_3(t_stack **stack, t_bench *bench)
{
	t_stack	*max_node;

	if (!stack || !*stack || ft_stacksize(*stack) < 2)
		return ;
	if (ft_stacksize(*stack) == 2)
	{
		sort_2(stack, bench);
		return ;
	}
	max_node = find_max(*stack);
	if (max_node == *stack)
		ra(stack, bench);
	else if (max_node == (*stack)->next)
		rra(stack, bench);
	if ((*stack)->value > (*stack)->next->value)
		sa(stack, bench);
}

void	sort_5(t_stack **a, t_stack **b, t_bench *bench)
{
	t_stack	*min;
	int		pos;
	int		size;

	if (!a || !*a)
		return ;
	while (ft_stacksize(*a) > 3)
	{
		min = find_min(*a);
		pos = get_pos(*a, min);
		size = ft_stacksize(*a);
		while (*a != min)
		{
			if (pos <= size / 2)
				ra(a, bench);
			else
				rra(a, bench);
		}
		pb(a, b, bench);
	}
	sort_3(a, bench);
	while (*b)
		pa(a, b, bench);
}
