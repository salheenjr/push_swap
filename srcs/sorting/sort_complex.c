/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_complex.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wchan-ha <wchan-ha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/22 09:18:08 by saalagor          #+#    #+#             */
/*   Updated: 2026/08/22 10:59:38 by wchan-ha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_complex(t_stack **a, t_stack **b, t_bench *bench)
{
	t_stack	*min_node;

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
