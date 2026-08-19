/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_adaptive.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saalagor <saalagor@student.42kl.edu.m      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/17 14:21:44 by saalagor          #+#    #+#             */
/*   Updated: 2026/08/18 19:17:54 by saalagor         ###   ########.fr       */
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

void	sort_adaptive(t_stack **a, t_stack **b, t_bench *bench)
{
	double	disorder;

	if (!a || !*a || is_sorted(*a))
		return ;
	disorder = get_disorder(*a);
	if (bench)
		bench->disorder = disorder;
	if (disorder < 0.2)
	{
		if (bench)
			bench->strat_name = "Adaptive (Simple)";
		sort_simple(a, b, bench);
	}
	else if (disorder < 0.5)
	{
		if (bench)
			bench->strat_name = "Adaptive (Medium)";
		sort_medium(a, b, bench);
	}
	else
	{
		if (bench)
			bench->strat_name = "Adaptive (Complex)";
		sort_complex(a, b, bench);
	}
}
