/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   last6_operation.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wchan-ha <wchan-ha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/14 08:57:25 by wchan-ha          #+#    #+#             */
/*   Updated: 2026/08/14 10:37:28 by saalagor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"

void	ra(a_list	**a)
{
	a_list	*first;
	a_list	*last;

	if (!a || !*a || (*a)->next)
		return ;
	last = *a;
	first = *a;
	*a = (*a)->next;
	while (last->next)
		last = last->next;
	last->next = first;
	first->next = NULL;
}

void	rb(a_list	**b)
{
	b_list	*first;
	b_list	*last;

	if (!b || !*b || (*b)->next)
		return ;
	last = *b;
	first = *b;
	*b = (*b)->next;
	while (last->next)
		last = last->next;
	last->next = first;
	first->next = NULL;
}

void	rr(a_list **a, a_list **b)
{
	ra(a);
	rb(b);
}

void	rra(ab_list	**a)
{
	ab_list	last;

	if (!a || !*a || !(*a)->next)
		return ;
	last = *a;
	while (last->next->next)
	{
		last = last->next;
	}
	*a = last->next;
	last->next = NULL;
}

void	rrb(ab_list	**b)
{
	ab_list	last;

	if (!b || !*b || !(*b)->next)
		return ;
	last = *b;
	while (last->next->next)
	{
		last = last->next;
	}
	*b = last->next;
	last->next = NULL;
}

void	rrr(ab_list **a, ab_list **b)
{
	rra(a);
	rrb(b);
}





