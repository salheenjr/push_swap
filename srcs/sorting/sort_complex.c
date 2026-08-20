/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_complex.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wchan-ha <wchan-ha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/18 14:43:56 by wchan-ha          #+#    #+#             */
/*   Updated: 2026/08/20 14:12:49 by wchan-ha         ###   ########.fr       */
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
	a_size = ft_stacksize(*a);
	rotate_a_until_target_top(a, min_node, bench);
}
