/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saalagor <saalagor@student.42kl.edu.m      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/18 15:50:59 by saalagor          #+#    #+#             */
/*   Updated: 2026/08/19 12:11:31 by saalagor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static bool	match_flag(char *arg, t_bench *bench)
{
	if (ft_strncmp(arg, "--simple", 9) == 0)
		bench->strategy = STRAT_SIMPLE;
	else if (ft_strncmp(arg, "--medium", 9) == 0)
		bench->strategy = STRAT_MEDIUM;
	else if (ft_strncmp(arg, "--complex", 10) == 0)
		bench->strategy = STRAT_COMPLEX;
	else if (ft_strncmp(arg, "--adaptive", 11) == 0)
		bench->strategy = STRAT_ADAPTIVE;
	else if (ft_strncmp(arg, "--bench", 8) == 0)
		bench->bench_mode = true;
	else
		return (false);
	return (true);
}

static int	parse_flags(int argc, char **argv, t_bench *bench)
{
	int	i;

	i = 1;
	bench->bench_mode = false;
	bench->strategy = STRAT_ADAPTIVE;
	while (i < argc && argv[i][0] == '-' && argv[i][1] == '-')
	{
		if (!match_flag(argv[i], bench))
		{
			write(2, "Error\n", 6);
			return (-1);
		}
		i++;
	}
	return (i);
}

static void	execute_sort(t_stack **a, t_stack **b, t_bench *bench)
{
	int	size;

	size = ft_stacksize(*a);
	if (size <= 5)
	{
		bench->strat_name = "Small Sort";
		if (size == 2)
			sa(a, bench);
		else if (size == 3)
			sort_3(a, bench);
		else
			sort_5(a, b, bench);
		return ;
	}
	if (bench->strategy == STRAT_SIMPLE)
		(1 && (bench->strat_name = "Simple"), sort_simple(a, b, bench));
	else if (bench->strategy == STRAT_MEDIUM)
		(1 && (bench->strat_name = "Medium"), sort_medium(a, b, bench));
	else if (bench->strategy == STRAT_COMPLEX)
		(1 && (bench->strat_name = "Complex"), sort_complex(a, b, bench));
	else
		sort_adaptive(a, b, bench);
}

int	main(int argc, char **argv)
{
	t_stack	*a;
	t_stack	*b;
	t_bench	bench;
	int		num_start;

	if (argc < 2)
		return (0);
	ft_memset(&bench, 0, sizeof(t_bench));
	num_start = parse_flags(argc, argv, &bench);
	if (num_start == -1)
		return (1);
	if (num_start >= argc)
		return (0);
	a = NULL;
	b = NULL;
	init_stack_a(&a, argv + num_start);
	bench.disorder = get_disorder(a);
	if (!is_sorted(a))
		execute_sort(&a, &b, &bench);
	if (bench.bench_mode)
		print_bench(&bench);
	ft_free_stack(&a);
	ft_free_stack(&b);
	return (0);
}
