/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_complex_utils.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saalagor <saalagor@student.42kl.edu.m      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/22 15:32:33 by saalagor          #+#    #+#             */
/*   Updated: 2026/08/22 15:32:54 by saalagor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	update_pos(t_stack *stack)
{
	int	i;

	i = 0;
	while (stack)
	{
		stack->pos = i++;
		stack = stack->next;
	}
}

t_stack	*get_target_b(t_stack *a_node, t_stack *b)
{
	t_stack	*target;
	t_stack	*curr;
	long	match_val;

	curr = b;
	target = NULL;
	match_val = LONG_MIN;
	while (curr)
	{
		if (curr->value < a_node->value && curr->value > match_val)
		{
			match_val = curr->value;
			target = curr;
		}
		curr = curr->next;
	}
	if (!target)
		return (find_max(b));
	return (target);
}

t_stack	*get_target_a(t_stack *b_node, t_stack *a)
{
	t_stack	*target;
	t_stack	*curr;
	long	match_val;

	curr = a;
	target = NULL;
	match_val = LONG_MAX;
	while (curr)
	{
		if (curr->value > b_node->value && curr->value < match_val)
		{
			match_val = curr->value;
			target = curr;
		}
		curr = curr->next;
	}
	if (!target)
		return (find_min(a));
	return (target);
}

static int	calc_cost(t_stack *node_a, t_stack *node_b, int size_a, int size_b)
{
	int	cost_a;
	int	cost_b;

	if (node_a->pos <= size_a / 2)
		cost_a = node_a->pos;
	else
		cost_a = size_a - node_a->pos;
	if (node_b->pos <= size_b / 2)
		cost_b = node_b->pos;
	else
		cost_b = size_b - node_b->pos;
	if ((node_a->pos <= size_a / 2 && node_b->pos <= size_b / 2)
		|| (node_a->pos > size_a / 2 && node_b->pos > size_b / 2))
	{
		if (cost_a > cost_b)
			return (cost_a);
		return (cost_b);
	}
	return (cost_a + cost_b);
}

t_stack	*get_cheapest_node(t_stack *a, t_stack *b)
{
	t_stack	*curr;
	t_stack	*cheapest;
	int		min_cost;
	int		cost;

	update_pos(a);
	update_pos(b);
	curr = a;
	cheapest = a;
	min_cost = INT_MAX;
	while (curr)
	{
		cost = calc_cost(curr, get_target_b(curr, b),
				ft_stacksize(a), ft_stacksize(b));
		if (cost < min_cost)
		{
			min_cost = cost;
			cheapest = curr;
		}
		curr = curr->next;
	}
	return (cheapest);
}
