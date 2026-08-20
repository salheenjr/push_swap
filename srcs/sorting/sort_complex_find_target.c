/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_complex_find_target.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wchan-ha <wchan-ha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/20 13:22:49 by wchan-ha          #+#    #+#             */
/*   Updated: 2026/08/20 13:24:08 by wchan-ha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*find_target_b(int a_value, t_stack *b)
{
	t_stack	*target;
	t_stack	*b_p;
	long	comparison;

	target = NULL;
	b_p = b;
	comparison = -2147483649;
	while (b_p)
	{
		if (b_p->value < a_value && b_p->value > comparison)
		{
			comparison = b_p->value;
			target = b_p;
		}
		b_p = b_p->next;
	}
	if (!target)
		target = find_max(b);
	return (target);
}

t_stack	*find_target_a(int b_value, t_stack *a)
{
	t_stack	*move;
	long	comparison;
	t_stack	*target;

	comparison = 2147483649;
	move = a;
	target = NULL;
	while (move)
	{
		if (move->value < comparison && move->value > b_value)
		{
			comparison = move->value;
			target = move;
		}
		move = move->next;
	}
	if (!target)
		target = find_min(a);
	return (target);
}
