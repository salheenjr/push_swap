/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_complex_utils_push.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wchan-ha <wchan-ha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/20 13:53:56 by wchan-ha          #+#    #+#             */
/*   Updated: 2026/08/20 14:09:37 by wchan-ha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_and_push_to_b(t_stack **a, t_stack **b, t_bench *bench)
{
	t_stack	*target_a;
	t_stack	*target_b;
	int		size_a;
	int		size_b;

	while (ft_stacksize(*a) > 3)
	{
		size_a = ft_stacksize(*a);
		size_b = ft_stacksize(*b);
		assign_unsorted_index(*a);
		assign_unsorted_index(*b);
		target_a = find_the_cheapest(*a, *b);
		target_b = find_target_b(target_a->value, *b);
		rotate_a_and_b_to_top(a, b, target_a, bench);
		pb(a, b, bench);
	}
	sort_3(a, bench);
}

void	sort_and_push_to_a(t_stack **a, t_stack **b, t_bench *bench)
{
	t_stack	*target_a;
	int		size_a;

	while (ft_stacksize(*b) > 0)
	{
		size_a = ft_stacksize(*a);
		assign_unsorted_index(*a);
		target_a = find_target_a((*b)->value, *a);
		rotate_a_until_target_top(a, target_a, bench);
		pa(a, b, bench);
	}
}
