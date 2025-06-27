/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_p.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skimura <skimura@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/11 18:08:40 by skimura           #+#    #+#             */
/*   Updated: 2025/06/27 17:26:41 by skimura          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/push_swap.h"

void	pa(t_stack *a, t_stack *b)
{
	if (!a || !b)
		return ;
	ft_push(b, a);
	ft_printf("pa\n");
}

void	pb(t_stack *a, t_stack *b)
{
	if (!a || !b)
		return ;
	ft_push(a, b);
	ft_printf("pb\n");
}
