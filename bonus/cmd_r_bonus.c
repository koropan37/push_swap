/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_r_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skimura <skimura@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/30 17:57:49 by skimura           #+#    #+#             */
/*   Updated: 2025/06/30 19:13:49 by skimura          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/checker_bonus.h"

void	checker_ra(t_stack *a)
{
	if (!a)
		return ;
	rotate(a);
}

void	checker_rb(t_stack *b)
{
	if (!b)
		return ;
	rotate(b);
}

void	checker_rr(t_stack *a, t_stack *b)
{
	if (!a || !b)
		return ;
	rotate(a);
	rotate(b);
}
