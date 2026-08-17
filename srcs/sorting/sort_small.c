/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_small.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saalagor <saalagor@student.42kl.edu.m      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/16 13:37:35 by saalagor          #+#    #+#             */
/*   Updated: 2026/08/16 13:43:15 by saalagor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../push_swap.h"

void	sort_3(t_stack **stack)
{
	t_stack	*max_node;

	if (!stack || !*stack || ft_stacksize(*stack) != 3)
		return ;
	max_node = find_max(*stack);
	if (max_node == *stack)
		ra(stack);
	else if (max_node == (*stack)->next)
		rra(stack);
	if ((*stack)->value > (*stack)->next->value)
		sa(stack);
}

void	sort_5(t_stack **a, t_stack **b)
{
	t_stack	*min;
	int		pos;
	int		size;

	if (!a || !*a || ft_stacksize(*a) > 5)
		return ;
	while (ft_stacksize(*a) > 3)
	{
		min = find_min(*a);
		pos = get_pos(*a, min);
		size = ft_stacksize(*a);
		while (*a != min)
		{
			if (pos <= size / 2)
				ra(a);
			else
				rra(a);
		}
		pb(a, b);
	}
	sort_3(a);
	while (*b)
		pa(a, b);
}
