/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_r.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skimura <skimura@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/11 18:19:02 by skimura           #+#    #+#             */
/*   Updated: 2025/06/27 17:26:49 by skimura          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/push_swap.h"

void	ra(t_stack *a)
{
	if (!a)
		return ;
	rotate(a);
	ft_printf("ra\n");
}

void	rb(t_stack *b)
{
	if (!b)
		return ;
	rotate(b);
	ft_printf("rb\n");
}

void	rr(t_stack *a, t_stack *b)
{
	if (!a || !b)
		return ;
	rotate(a);
	rotate(b);
	ft_printf("rr\n");
}
