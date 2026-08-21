/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_push.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wchan-ha <wchan-ha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/14 17:27:54 by saalagor          #+#    #+#             */
/*   Updated: 2026/08/22 07:38:49 by wchan-ha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../push_swap.h"

static void	push(t_stack **dest, t_stack **src)
{
	t_stack	*node_to_move;

	if (!src || !*src)
		return ;
	node_to_move = *src;
	*src = (*src)->next;
	if (*src)
		(*src)->prev = NULL;
	node_to_move->next = *dest;
	if (*dest)
		(*dest)->prev = node_to_move;
	node_to_move->prev = NULL;
	*dest = node_to_move;
}

void	pa(t_stack **a, t_stack **b, t_bench *bench)
{
	if (!b || !*b)
		return ;
	push(a, b);
	if (!bench->not_write)
		write(1, "pa\n", 3);
	if (bench)
	{
		bench->pa_count++;
		bench->total_ops++;
	}
}

void	pb(t_stack **a, t_stack **b, t_bench *bench)
{
	if (!a || !*a)
		return ;
	push(b, a);
	if (!bench->not_write)
		write(1, "pb\n", 3);
	if (bench)
	{
		bench->pb_count++;
		bench->total_ops++;
	}
}
