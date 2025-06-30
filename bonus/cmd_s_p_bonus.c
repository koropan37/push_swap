/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_s_p_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skimura <skimura@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/30 18:10:00 by skimura           #+#    #+#             */
/*   Updated: 2025/06/30 19:14:19 by skimura          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/checker_bonus.h"

void	checker_sa(t_stack *a)
{
	if (!a)
		return ;
	swap_top_two(a);
}

void	checker_sb(t_stack *b)
{
	if (!b)
		return ;
	swap_top_two(b);
}

void	checker_ss(t_stack *a, t_stack *b)
{
	if (!a || !b)
		return ;
	swap_top_two(a);
	swap_top_two(b);
}

void	checker_pa(t_stack *a, t_stack *b)
{
	if (!a || !b)
		return ;
	ft_push(b, a);
}

void	checker_pb(t_stack *a, t_stack *b)
{
	if (!a || !b)
		return ;
	ft_push(a, b);
}
