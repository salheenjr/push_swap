/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_adaptive.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saalagor <saalagor@student.42kl.edu.m      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/17 14:21:44 by saalagor          #+#    #+#             */
/*   Updated: 2026/08/17 17:46:17 by saalagor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../push_swap.h"

double	get_disorder(t_stack *a)
{
	t_stack	*i;
	t_stack	*j;
	double	inversions;
	double	total_pairs;
	int		n;

	n = ft_stacksize(a);
	if (n <= 1)
		return (0.0);
	inversions = 0.0;
	i = a;
	while (i)
	{
		j = i->next;
		while (j)
		{
			if (i->value > j->value)
				inversions += 1.0;
			j = j->next;
		}
		i = i->next;
	}
	total_pairs = ((double)n * ((double)n - 1.0)) / 2.0;
	return (inversions / total_pairs);
}

void	sort_adaptive(t_stack **a, t_stack **b)
{
	double	disorder;

	if (!a || !*a || is_sorted(*a))
		return ;
	disorder = get_disorder(*a);
	if (disorder < 0.2)
		sort_simple(a, b);
	else if (disorder < 0.5)
		sort_medium(a, b);
	else
		sort_complex(a, b);
}
