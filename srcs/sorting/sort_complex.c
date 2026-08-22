/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_complex.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saalagor <saalagor@student.42kl.edu.m      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/22 09:18:08 by saalagor          #+#    #+#             */
/*   Updated: 2026/08/22 09:20:51 by saalagor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_complex(t_stack **a, t_stack **b, t_bench *bench)
{
	t_stack	*min_node;
	int		a_size;

	if (!a || !*a || !(*a)->next)
		return ;
	*b = NULL;
	pb(a, b, bench);
	pb(a, b, bench);
	sort_and_push_to_b(a, b, bench);
	sort_and_push_to_a(a, b, bench);
	min_node = find_min(*a);
	assign_unsorted_index(*a);
	rotate_a_until_target_top(a, min_node, bench);
}
