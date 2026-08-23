/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wchan-ha <wchan-ha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/22 09:17:13 by saalagor          #+#    #+#             */
/*   Updated: 2026/08/22 15:44:29 by saalagor         ###   ########.fr       */
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

/* --- Strategy Enum --- */
typedef enum e_strategy
{
	STRAT_ADAPTIVE,
	STRAT_SIMPLE,
	STRAT_MEDIUM,
	STRAT_COMPLEX
}	t_strategy;

/* --- Benchmark & Config Structure --- */
typedef struct s_bench
{
	bool		bench_mode;
	bool		not_write;
	t_strategy	strategy;
	const char	*strat_name;
	double		disorder;
	int			sa_count;
	int			sb_count;
	int			ss_count;
	int			pa_count;
	int			pb_count;
	int			ra_count;
	int			rb_count;
	int			rr_count;
	int			rra_count;
	int			rrb_count;
	int			rrr_count;
	int			total_ops;
}	t_bench;

/* --- Data Structures --- */
typedef struct s_stack
{
	int				value;
	int				index;
	int				pos;
	struct s_stack	*next;
	struct s_stack	*prev;
}	t_stack;

/* --- Parsing & Memory Utilities --- */
int		parse_args(int argc, char **argv, t_stack **a, t_bench *bench);
void	init_stack_a(t_stack **a, char **argv);
void	ft_free_stack(t_stack **stack);
void	ft_free_str_array(char **arr);
int		ft_stacksize(t_stack *stack);
t_stack	*ft_stacknew(int value);
t_stack	*ft_stacklast(t_stack *stack);
void	ft_stackadd_back(t_stack **stack, t_stack *new_node);
bool	is_number(char *str);
long	ft_atol(const char *str);
bool	has_duplicate(t_stack *a, int value);

/* --- Operations (with bench context) --- */
void	sa(t_stack **a, t_bench *bench);
void	sb(t_stack **b, t_bench *bench);
void	ss(t_stack **a, t_stack **b, t_bench *bench);
void	pa(t_stack **a, t_stack **b, t_bench *bench);
void	pb(t_stack **a, t_stack **b, t_bench *bench);
void	ra(t_stack **a, t_bench *bench);
void	rb(t_stack **b, t_bench *bench);
void	rr(t_stack **a, t_stack **b, t_bench *bench);
void	rra(t_stack **a, t_bench *bench);
void	rrb(t_stack **b, t_bench *bench);
void	rrr(t_stack **a, t_stack **b, t_bench *bench);

/* --- Sorting Utilities --- */
bool	is_sorted(t_stack *stack);
t_stack	*find_min(t_stack *stack);
t_stack	*find_max(t_stack *stack);
int		get_pos(t_stack *stack, t_stack *target);
void	assign_index(t_stack *a);
double	get_disorder(t_stack *a);

/* --- Turk Algorithm Utilities & Target Lookups (sort_complex_utils.c) --- */
void	update_pos(t_stack *stack);
t_stack	*get_target_b(t_stack *a_node, t_stack *b);
t_stack	*get_target_a(t_stack *b_node, t_stack *a);
t_stack	*get_cheapest_node(t_stack *a, t_stack *b);
void	rotate_to_top(t_stack **s, t_stack *target, char name, t_bench *bench);

/* --- Sorting Strategies --- */
void	sort_2(t_stack **a, t_bench *bench);
void	sort_3(t_stack **a, t_bench *bench);
void	sort_5(t_stack **a, t_stack **b, t_bench *bench);
void	sort_simple(t_stack **a, t_stack **b, t_bench *bench);
void	sort_medium(t_stack **a, t_stack **b, t_bench *bench);
void	sort_complex(t_stack **a, t_stack **b, t_bench *bench);
void	sort_adaptive(t_stack **a, t_stack **b, t_bench *bench);

/* --- Benchmark Printer --- */
void	print_bench(t_bench *bench);

#endif
