/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_complex_utils_sortings.c                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wchan-ha <wchan-ha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/20 09:59:03 by wchan-ha          #+#    #+#             */
/*   Updated: 2026/08/20 14:25:39 by wchan-ha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rotate_a_until_target_top(t_stack **a,
	t_stack *target_a, t_bench *bench)
{
	int	steps;
	int	size_a;

	size_a = ft_stacksize(*a);
	if (target_a->unsorted_index < (size_a + 1) / 2)
	{
		steps = target_a->unsorted_index;
		while (steps > 0)
		{
			ra(a, bench);
			steps--;
		}
	}
	else
	{
		steps = size_a - target_a->unsorted_index;
		while (steps > 0)
		{
			rra(a, bench);
			steps--;
		}
	}
}

void	rotate_b_until_target_top(t_stack **b,
	t_stack *target_b, t_bench *bench)
{
	int	steps;
	int	size_b;

	size_b = ft_stacksize(*b);
	if (target_b->unsorted_index < (size_b + 1) / 2)
	{
		steps = target_b->unsorted_index;
		while (steps > 0)
		{
			rb(b, bench);
			steps--;
		}
	}
	else
	{
		steps = size_b - target_b->unsorted_index;
		while (steps > 0)
		{
			rrb(b, bench);
			steps--;
		}
	}
}

static void	rr_all_target_to_top(t_stack **a, t_stack **b,
	t_stack *target_a, t_bench *bench)
{
	t_stack	*target_b;
	int		steps_a;
	int		steps_b;

	target_b = find_target_b(target_a->value, *b);
	steps_a = target_a->unsorted_index;
	steps_b = target_b->unsorted_index;
	while (steps_a > 0 && steps_b > 0)
	{
		rr(a, b, bench);
		steps_a--;
		steps_b--;
	}
	while (steps_a > 0)
	{
		ra(a, bench);
		steps_a--;
	}
	while (steps_b > 0)
	{
		rb(b, bench);
		steps_b--;
	}
}

static void	rrr_all_target_to_top(t_stack **a, t_stack **b,
	t_stack *target_a, t_bench *bench)
{
	t_stack	*target_b;
	int		steps_a;
	int		steps_b;

	target_b = find_target_b(target_a->value, *b);
	steps_a = ft_stacksize(*a) - target_a->unsorted_index;
	steps_b = ft_stacksize(*b) - target_b->unsorted_index;
	while (steps_a > 0 && steps_b > 0)
	{
		rrr(a, b, bench);
		steps_a--;
		steps_b--;
	}
	while (steps_a > 0)
	{
		rra(a, bench);
		steps_a--;
	}
	while (steps_b > 0)
	{
		rrb(b, bench);
		steps_b--;
	}
}

void	rotate_a_and_b_to_top(t_stack **a, t_stack **b,
	t_stack *target_a, t_bench *bench)
{
	t_stack	*target_b;
	int		size_a;
	int		size_b;

	target_b = find_target_b(target_a->value, *b);
	size_a = ft_stacksize(*a);
	size_b = ft_stacksize(*b);
	if (target_a->unsorted_index < (size_a + 1) / 2
		&& target_b->unsorted_index < (size_b + 1) / 2)
		rr_all_target_to_top(a, b, target_a, bench);
	else if (target_a->unsorted_index >= (size_a + 1) / 2
		&& target_b->unsorted_index >= (size_b + 1) / 2)
		rrr_all_target_to_top(a, b, target_a, bench);
	else
	{
		rotate_a_until_target_top(a, target_a, bench);
		rotate_b_until_target_top(b, target_b, bench);
	}
}
