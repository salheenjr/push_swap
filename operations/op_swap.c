/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_swap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saalagor <saalagor@student.42kl.edu.m      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/14 17:26:45 by saalagor          #+#    #+#             */
/*   Updated: 2026/08/14 17:41:16 by saalagor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void    swap(t_stack **stack)
{
        t_stack *first;
        t_stack *second;

        if (!stack || !*stack || !(*stack)->next)
                return ;
        first = *stack;
        second = first->next;
        first->next = second->next;
        if (second->next)
                second->next->prev = first;
        second->prev = NULL;
        second->next = first;
        first->prev = second;
        *stack = second;
}

void    sa(t_stack **a)
{
        swap(a);
	ft_printf("sa\n");
}

void    sb(t_stack **b)
{
        swap(b);
	ft_printf("sb\n");
}

void    ss(t_stack **a, t_stack **b)
{
        swap(a);
	swap(b);
	ft_printf("ss\n");
}
