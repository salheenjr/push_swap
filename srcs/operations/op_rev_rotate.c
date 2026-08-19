/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_rev_rotate.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saalagor <saalagor@student.42kl.edu.m      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/15 12:43:57 by saalagor          #+#    #+#             */
/*   Updated: 2026/08/18 18:46:37 by saalagor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../push_swap.h"

static void	rev_rotate(t_stack **stack)
{
	t_stack	*last;
	t_stack	*second_last;

	if (!stack || !*stack || !(*stack)->next)
		return ;
	last = ft_stacklast(*stack);
	second_last = last->prev;
	second_last->next = NULL;
	last->prev = NULL;
	last->next = *stack;
	(*stack)->prev = last;
	*stack = last;
}

void	rra(t_stack **a, t_bench *bench)
{
	if (!a || !*a || !(*a)->next)
		return ;
	rev_rotate(a);
	write(1, "rra\n", 4);
	if (bench)
	{
		bench->rra_count++;
		bench->total_ops++;
	}
}

void	rrb(t_stack **b, t_bench *bench)
{
	if (!b || !*b || !(*b)->next)
		return ;
	rev_rotate(b);
	write(1, "rrb\n", 4);
	if (bench)
	{
		bench->rrb_count++;
		bench->total_ops++;
	}
}

void	rrr(t_stack **a, t_stack **b, t_bench *bench)
{
	if ((!a || !*a || !(*a)->next) && (!b || !*b || !(*b)->next))
		return ;
	rev_rotate(a);
	rev_rotate(b);
	write(1, "rrr\n", 4);
	if (bench)
	{
		bench->rrr_count++;
		bench->total_ops++;
	}
}
