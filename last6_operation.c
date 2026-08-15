/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   last6_operation.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wchan-ha <wchan-ha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/14 08:57:25 by wchan-ha          #+#    #+#             */
/*   Updated: 2026/08/15 08:36:11 by wchan-ha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"

void	ra(t_stack	**a)
{
	t_stack	*last;
	t_stack	*first;

	if (!a || !*a || (*a)->next)
		return ;
	last = *a;
	first = *a;
	*a = (*a)->next;
	*a->prev = NULL;
	while (last->next)
		last = last->next;
	last->next = first;
	first->prev = last;
	first->next = NULL;
}

void	rb(t_stack	**b)
{
	t_stack	*first;
	t_stack	*last;

	if (!b || !*b || (*b)->next)
		return ;
	last = *b;
	first = *b;
	*b = (*b)->next;
	*b->previous = NULL;
	while (last->next)
		last = last->next;
	last->next = first;
	first->prev = last;
	first->next = NULL;
}

void	rr(t_stack **a, t_stack **b)
{
	ra(a);
	rb(b);
}

void	rra(t_stack	**a)
{
	t_stack	*last;
	t_stack	*second_last;

	if (!a || !*a || !(*a)->next)
		return ;
	last = *a;
	second_last = *a;
	while (second_last->next->next)
		second_last = second_last->next;
	last = second_last->next;
	*a->prev = last;
	last->pre = NULL;
	last->next = *a;
	second_last->next = NULL;
}

void	rrb(t_stack	**b)
{
	t_stack	*last;
	t_stack	*second_last;

	if (!b || !*b || !(*b)->next)
		return ;
	last = *b;
	second_last = *b;
	while (second_last->next->next)
		second_last = second_last->next;
	last = second_last->next;
	second_last->next = NULL;
	(*a)->prev = last;
	last->prev = NULL;
	last->next = *a;;

void	rrr(t_stack **a, t_stack **b)
{
	rra(a);
	rrb(b);
}
