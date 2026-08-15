/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saalagor <saalagor@student.42kl.edu.m      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/14 11:41:12 by saalagor          #+#    #+#             */
/*   Updated: 2026/08/14 15:50:22 by saalagor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

/* --- Libraries --- */
#include "libft/libft.h"

/* --- Macro Definitions --- */
# define INT_MAX 2147483647
# define INT_MIN -2147483648
# define TRUE 1
# define FALSE 0

/* --- Data Structures --- */
typedef struct s_stack
{
	int	value;
	int	index;
	struct s_stack *next;
	struct s_stack *prev;
}	t_stack;

/* --- Operation Prototypes --- */

// Swap
void	sa(t_stack **a);
void	sb(t_stack **b);
void	ss(t_stack **a, t_stack **b);

// Push
void	pa(t_stack **a, t_stack **b);
void	pb(t_stack **b, t_stack **a);

// Rotate
void	ra(t_stack **a);
void	rb(t_stack **b);
void	rr(t_stack **a, t_stack **b);

// Reverse Rotate
void	rra(t_stack **a);
void	rrb(t_stack **b);
void	rrr(t_stack **a, t_stack **b);

#endif
