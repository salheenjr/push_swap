/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_swap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saalagor <saalagor@student.42kl.edu.m      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/14 17:26:45 by saalagor          #+#    #+#             */
/*   Updated: 2026/08/18 18:35:28 by saalagor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../push_swap.h"

static void	swap(t_stack **stack)
{
	t_stack	*first;
	t_stack	*second;

	if (!stack || !*stack || !(*stack)->next)
		return ;
	first = *stack;
	second = first->next;
	first->next = second->next;
	if (second->next)
		second->next->prev = first;
	second->prev = NULL;
	second->next = first;
	first->prev = second;
	*stack = second;
}

void	sa(t_stack **a, t_bench *bench)
{
	if (!a || !*a || !(*a)->next)
		return ;
	swap(a);
	write(1, "sa\n", 3);
	if (bench)
	{
		bench->sa_count++;
		bench->total_ops++;
	}
}

void	sb(t_stack **b, t_bench *bench)
{
	if (!b || !*b || !(*b)->next)
		return ;
	swap(b);
	write(1, "sb\n", 3);
	if (bench)
	{
		bench->sb_count++;
		bench->total_ops++;
	}
}

void	ss(t_stack **a, t_stack **b, t_bench *bench)
{
	if ((!a || !*a || !(*a)->next) && (!b || !*b || !(*b)->next))
		return ;
	swap(a);
	swap(b);
	write(1, "ss\n", 3);
	if (bench)
	{
		bench->ss_count++;
		bench->total_ops++;
	}
}
