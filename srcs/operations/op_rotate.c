/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_rotate.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wchan-ha <wchan-ha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/14 17:29:33 by saalagor          #+#    #+#             */
/*   Updated: 2026/08/22 07:43:26 by wchan-ha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../push_swap.h"

static void	rotate(t_stack **stack)
{
	t_stack	*first;
	t_stack	*last;

	if (!stack || !*stack || !(*stack)->next)
		return ;
	first = *stack;
	last = ft_stacklast(*stack);
	*stack = first->next;
	(*stack)->prev = NULL;
	first->next = NULL;
	first->prev = last;
	last->next = first;
}

void	ra(t_stack **a, t_bench *bench)
{
	if (!a || !*a || !(*a)->next)
		return ;
	rotate(a);
	if (!bench->not_write)
		write(1, "ra\n", 3);
	if (bench)
	{
		bench->ra_count++;
		bench->total_ops++;
	}
}

void	rb(t_stack **b, t_bench *bench)
{
	if (!b || !*b || !(*b)->next)
		return ;
	rotate(b);
	if (!bench->not_write)
		write(1, "rb\n", 3);
	if (bench)
	{
		bench->rb_count++;
		bench->total_ops++;
	}
}

void	rr(t_stack **a, t_stack **b, t_bench *bench)
{
	if ((!a || !*a || !(*a)->next) && (!b || !*b || !(*b)->next))
		return ;
	rotate(a);
	rotate(b);
	if (!bench->not_write)
		write(1, "rr\n", 3);
	if (bench)
	{
		bench->rr_count++;
		bench->total_ops++;
	}
}
