/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_complex_utils_cal.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wchan-ha <wchan-ha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/20 09:59:03 by wchan-ha          #+#    #+#             */
/*   Updated: 2026/08/20 10:00:00 by wchan-ha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rotate_a_until_target_top(t_stack **a, t_stack *target_a,
		int size_a, t_bench *bench)
{
	int	steps;

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

void	rotate_b_until_target_top(t_stack **b, t_stack *target_b,
		int size_b, t_bench *bench)
{
	int	steps;

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

void	sort_and_push_to_b(t_stack **a, t_stack **b, t_bench *bench)
{
	t_stack	*target_a;
	t_stack	*target_b;
	int		a_size;
	int		b_size;

	while (ft_stacksize(*a) > 3)
	{
		a_size = ft_stacksize(*a);
		b_size = ft_stacksize(*b);
		target_a = find_the_cheapest(*a, *b);
		target_b = find_target_b(target_a->value, *b);
		rotate_a_until_target_top(a, target_a, a_size, bench);
		rotate_b_until_target_top(b, target_b, b_size, bench);
		pb(a, b, bench);
	}
	sort_3(a, bench);
}

void	sort_and_push_to_a(t_stack **a, t_stack **b, t_bench *bench)
{
	t_stack	*target_a;
	int		a_size;

	while (ft_stacksize(*b) > 0)
	{
		a_size = ft_stacksize(*a);
		assign_unsorted_index(*a);
		target_a = find_target_a((*b)->value, *a);
		rotate_a_until_target_top(a, target_a, a_size, bench);
		pa(a, b, bench);
	}
}
