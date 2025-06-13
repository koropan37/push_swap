/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_sa_sb_ss.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skimura <skimura@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/11 18:31:31 by skimura           #+#    #+#             */
/*   Updated: 2025/06/13 16:10:14 by skimura          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sa(t_stack *a)
{
	swap_top_two(a);
}

void	sb(t_stack *b)
{
	swap_top_two(b);
}

void	ss(t_stack *a, t_stack *b)
{
	swap_top_two(a);
	swap_top_two(b);
}
