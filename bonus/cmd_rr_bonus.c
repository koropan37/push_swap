/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_rr_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skimura <skimura@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/30 17:58:41 by skimura           #+#    #+#             */
/*   Updated: 2025/06/30 18:00:08 by skimura          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/checker_bonus.h"

void	checker_rra(t_stack *a)
{
	if (!a)
		return ;
	reverse_rotate(a);
}

void	checker_rrb(t_stack *b)
{
	if (!b)
		return ;
	reverse_rotate(b);
}

void	checker_rrr(t_stack *a, t_stack *b)
{
	if (!a || !b)
		return ;
	reverse_rotate(a);
	reverse_rotate(b);
}
