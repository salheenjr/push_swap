/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   last6_operation.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wchan-ha <wchan-ha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/14 08:57:25 by wchan-ha          #+#    #+#             */
/*   Updated: 2026/08/14 10:15:13 by wchan-ha         ###   ########.fr       */
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
	ab_list	last_before;
	int	len;
	int	i;

	if (!a || !*a || !(*a)->next)
		return ;
	last = *a;
	len = 0;
	while (last->next)
	{
		last = last->next;
		len++;
	}
	i = 0;
	while (last_before->next && i < len - 1)
	{
		last_before = last_before->next;
		i++;
	}
	*a = last;
	last_before->next = NULL;
}

void	rrb(ab_list	**b)
{
	ab_list	last;
	ab_list	last_before;
	int	len;
	int	i;

	if (!b || !*b || !(*b)->next)
		return ;
	last = *b;
	len = 0;
	while (last->next)
	{
		last = last->next;
		len++;
	}
	i = 0;
	while (last_before->next && i < len - 1)
	{
		last_before = last_before->next;
		i++;
	}
	*b = last;
	last_before->next = NULL;
}

void	rrr(ab_list **a, ab_list **b)
{
	rra(a);
	rrb(b);
}





