/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bench_print.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saalagor <saalagor@student.42kl.edu.m      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/18 19:24:28 by saalagor          #+#    #+#             */
/*   Updated: 2026/08/19 12:49:06 by saalagor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../push_swap.h"

static void	ft_putpct_fd(double disorder, int fd)
{
	int	int_part;
	int	dec_part;

	int_part = (int)(disorder * 100.0);
	dec_part = (int)((disorder * 100.0 - int_part) * 100.0 + 0.5);
	if (dec_part >= 100)
	{
		int_part++;
		dec_part -= 100;
	}
	ft_putnbr_fd(int_part, fd);
	ft_putstr_fd(".", fd);
	if (dec_part < 10)
		ft_putstr_fd("0", fd);
	ft_putnbr_fd(dec_part, fd);
	ft_putstr_fd("%\n", fd);
}

static void	print_ops(t_bench *b)
{
	ft_putstr_fd("[bench] sa:  ", 2);
	ft_putnbr_fd(b->sa_count, 2);
	ft_putstr_fd("  sb:  ", 2);
	ft_putnbr_fd(b->sb_count, 2);
	ft_putstr_fd("  ss:  ", 2);
	ft_putnbr_fd(b->ss_count, 2);
	ft_putstr_fd("  pa:  ", 2);
	ft_putnbr_fd(b->pa_count, 2);
	ft_putstr_fd("  pb:  ", 2);
	ft_putnbr_fd(b->pb_count, 2);
	ft_putstr_fd("\n[bench] ra:  ", 2);
	ft_putnbr_fd(b->ra_count, 2);
	ft_putstr_fd("  rb:  ", 2);
	ft_putnbr_fd(b->rb_count, 2);
	ft_putstr_fd("  rr:  ", 2);
	ft_putnbr_fd(b->rr_count, 2);
	ft_putstr_fd("  rra:  ", 2);
	ft_putnbr_fd(b->rra_count, 2);
	ft_putstr_fd("  rrb:  ", 2);
	ft_putnbr_fd(b->rrb_count, 2);
	ft_putstr_fd("  rrr:  ", 2);
	ft_putnbr_fd(b->rrr_count, 2);
	ft_putstr_fd("\n", 2);
}

void	print_bench(t_bench *bench)
{
	if (!bench)
		return ;
	ft_putstr_fd("[bench] disorder:  ", 2);
	ft_putpct_fd(bench->disorder, 2);
	ft_putstr_fd("[bench] strategy:  ", 2);
	if (bench->strat_name)
		ft_putstr_fd((char *)bench->strat_name, 2);
	else
		ft_putstr_fd((char *)"Adaptive / O(n\\sqrt{n})", 2);
	ft_putstr_fd("\n[bench] total_ops: ", 2);
	ft_putnbr_fd(bench->total_ops, 2);
	ft_putstr_fd("\n", 2);
	print_ops(bench);
}
