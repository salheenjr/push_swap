/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saalagor <saalagor@student.42kl.edu.m      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/14 11:41:12 by saalagor          #+#    #+#             */
/*   Updated: 2026/08/18 13:58:08 by saalagor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

/* --- Standard Libraries --- */
# include <limits.h>
# include <stdbool.h>
# include <stdlib.h>
# include <unistd.h>

/* --- Custom Library --- */
# include "libft/libft.h"

/* --- Data Structures --- */
typedef struct s_stack
{
	int				value;
	int				index;
	struct s_stack	*next;
	struct s_stack	*prev;
}	t_stack;

/* --- Stack & Parsing Utilities --- */
void	init_stack_a(t_stack **a, char **argv);
void	ft_free_stack(t_stack **stack);
int		ft_stacksize(t_stack *stack);
t_stack	*ft_stacknew(int value);
void	ft_stackadd_back(t_stack **stack, t_stack *new_node);
bool	is_number(char *str);
long	ft_atol(const char *str);
bool	has_duplicate(t_stack *a, int value);

/* --- Operations --- */
void	sa(t_stack **a);
void	sb(t_stack **b);
void	ss(t_stack **a, t_stack **b);
void	pa(t_stack **a, t_stack **b);
void	pb(t_stack **a, t_stack **b);
void	ra(t_stack **a);
void	rb(t_stack **b);
void	rr(t_stack **a, t_stack **b);
void	rra(t_stack **a);
void	rrb(t_stack **b);
void	rrr(t_stack **a, t_stack **b);

/* --- Sorting Utilities --- */
bool	is_sorted(t_stack *stack);
t_stack	*find_min(t_stack *stack);
t_stack	*find_max(t_stack *stack);
int		get_pos(t_stack *stack, t_stack *target);
void	assign_index(t_stack *a);

/* --- Sorting Strategies --- */
void	sort_3(t_stack **a);
void	sort_5(t_stack **a, t_stack **b);
void	sort_simple(t_stack **a, t_stack **b);
void	sort_medium(t_stack **a, t_stack **b);
void	sort_complex(t_stack **a, t_stack **b);
void	sort_adaptive(t_stack **a, t_stack **b);
double	get_disorder(t_stack *a);

#endif
