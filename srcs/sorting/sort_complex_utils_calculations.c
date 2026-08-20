/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_complex_utils_calculations.c                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wchan-ha <wchan-ha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/20 09:56:45 by wchan-ha          #+#    #+#             */
/*   Updated: 2026/08/20 10:04:17 by wchan-ha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	assign_unsorted_index(t_stack *stack)
{
	t_stack	*curr;
	int		unsorted_index;

	if (!stack)
		return ;
	curr = stack;
	unsorted_index = 0;
	while (curr)
	{
		curr->unsorted_index = unsorted_index;
		unsorted_index++;
		curr = curr->next;
	}
}

t_stack	*find_target_b(int a_value, t_stack *b)
{
	t_stack	*target;
	t_stack	*b_p;
	long	comparison;

	target = NULL;
	b_p = b;
	comparison = -2147483649;
	while (b_p)
	{
		if (b_p->value < a_value && b_p->value > comparison)
		{
			comparison = b_p->value;
			target = b_p;
		}
		b_p = b_p->next;
	}
	if (!target)
		target = find_max(b);
	return (target);
}

int	count_node_cost(t_stack *a_current, t_stack *b, int size_a, int size_b)
{
	int		cost_a;
	int		cost_b;
	t_stack	*target_b;

	target_b = find_target_b(a_current->value, b);
	if (a_current->unsorted_index < (size_a + 1) / 2)
		cost_a = a_current->unsorted_index + 1;
	else
		cost_a = 1 + size_a - a_current->unsorted_index;
	if (target_b->unsorted_index < (size_b + 1) / 2)
		cost_b = target_b->unsorted_index;
	else
		cost_b = size_b - target_b->unsorted_index;
	return (cost_a + cost_b);
}

t_stack	*find_the_cheapest(t_stack *a, t_stack *b)
{
	int		size_a;
	int		size_b;
	int		cost;
	t_stack	*evaluating;

	size_a = ft_stacksize(a);
	size_b = ft_stacksize(b);
	assign_unsorted_index(a);
	assign_unsorted_index(b);
	cost = count_node_cost(a, b, size_a, size_b);
	evaluating = a;
	while (a)
	{
		if (count_node_cost(a, b, size_a, size_b) < cost)
		{
			cost = count_node_cost(a, b, size_a, size_b);
			evaluating = a;
		}
		a = a->next;
	}
	return (evaluating);
}

t_stack	*find_target_a(int b_value, t_stack *a)
{
	t_stack	*move;
	long	comparison;
	t_stack	*target;

	comparison = 2147483649;
	move = a;
	target = NULL;
	while (move)
	{
		if (move->value < comparison && move->value > b_value)
		{
			comparison = move->value;
			target = move;
		}
		move = move->next;
	}
	if (!target)
		target = find_min(a);
	return (target);
}
