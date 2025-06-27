/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_s.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skimura <skimura@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/11 18:31:31 by skimura           #+#    #+#             */
/*   Updated: 2025/06/27 11:09:51 by skimura          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/push_swap.h"

void	sa(t_stack *a)
{
	if (!a)
		return ;
	swap_top_two(a);
	ft_printf("sa\n");
}

void	sb(t_stack *b)
{
	if (!b)
		return ;
	swap_top_two(b);
	ft_printf("sb\n");
}

void	ss(t_stack *a, t_stack *b)
{
	if (!a || !b)
		return ;
	swap_top_two(a);
	swap_top_two(b);
	ft_printf("ss\n");
}
