/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_complex_utils_calculate_cost.c                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wchan-ha <wchan-ha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/20 09:56:45 by wchan-ha          #+#    #+#             */
/*   Updated: 2026/08/20 13:25:55 by wchan-ha         ###   ########.fr       */
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

static int	get_max_cost(int a, int b)
{
	if (a > b)
		return (a);
	return (b);
}

int	count_node_cost(t_stack *a_current, t_stack *b, int size_a, int size_b)
{
	int		cost_a;
	int		cost_b;
	t_stack	*target_b;

	target_b = find_target_b(a_current->value, b);
	if (a_current->unsorted_index < (size_a + 1) / 2)
		cost_a = a_current->unsorted_index;
	else
		cost_a = size_a - a_current->unsorted_index;
	if (target_b->unsorted_index < (size_b + 1) / 2)
		cost_b = target_b->unsorted_index;
	else
		cost_b = size_b - target_b->unsorted_index;
	if (a_current->unsorted_index < (size_a + 1) / 2
		&& target_b->unsorted_index < (size_b + 1) / 2)
		return (get_max_cost(cost_a, cost_b));
	if (a_current->unsorted_index >= (size_a + 1) / 2
		&& target_b->unsorted_index >= (size_b + 1) / 2)
		return (get_max_cost(cost_a, cost_b));
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
