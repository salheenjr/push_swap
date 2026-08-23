/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_complex.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wchan-ha <wchan-ha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/22 09:18:08 by saalagor          #+#    #+#             */
/*   Updated: 2026/08/22 15:32:16 by saalagor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	rotate_both(t_stack **a, t_stack **b,
			t_stack *cheapest, t_bench *bench)
{
	t_stack	*target_b;
	int		size_a;
	int		size_b;

	target_b = get_target_b(cheapest, *b);
	size_a = ft_stacksize(*a);
	size_b = ft_stacksize(*b);
	if (cheapest->pos <= size_a / 2 && target_b->pos <= size_b / 2)
	{
		while (*a != cheapest && *b != target_b)
			rr(a, b, bench);
	}
	else if (cheapest->pos > size_a / 2 && target_b->pos > size_b / 2)
	{
		while (*a != cheapest && *b != target_b)
			rrr(a, b, bench);
	}
}

void	rotate_to_top(t_stack **s, t_stack *target, char name, t_bench *bench)
{
	int	size;

	size = ft_stacksize(*s);
	update_pos(*s);
	while (*s != target)
	{
		if (target->pos <= size / 2)
		{
			if (name == 'a')
				ra(s, bench);
			else
				rb(s, bench);
		}
		else
		{
			if (name == 'a')
				rra(s, bench);
			else
				rrb(s, bench);
		}
	}
}

static void	push_cheapest_to_b(t_stack **a, t_stack **b, t_bench *bench)
{
	t_stack	*cheapest;

	cheapest = get_cheapest_node(*a, *b);
	rotate_both(a, b, cheapest, bench);
	rotate_to_top(a, cheapest, 'a', bench);
	rotate_to_top(b, get_target_b(cheapest, *b), 'b', bench);
	pb(a, b, bench);
}

static void	push_back_to_a(t_stack **a, t_stack **b, t_bench *bench)
{
	t_stack	*target_a;

	while (*b)
	{
		update_pos(*a);
		update_pos(*b);
		target_a = get_target_a(*b, *a);
		rotate_to_top(a, target_a, 'a', bench);
		pa(a, b, bench);
	}
}

void	sort_complex(t_stack **a, t_stack **b, t_bench *bench)
{
	int	size;

	if (!a || !*a || !(*a)->next)
		return ;
	size = ft_stacksize(*a);
	if (size-- > 3)
		pb(a, b, bench);
	if (size-- > 3)
		pb(a, b, bench);
	while (size > 3)
	{
		push_cheapest_to_b(a, b, bench);
		size--;
	}
	sort_3(a, bench);
	push_back_to_a(a, b, bench);
	rotate_to_top(a, find_min(*a), 'a', bench);
}
