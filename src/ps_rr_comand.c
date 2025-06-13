/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_rra_rrb_rrr.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skimura <skimura@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/11 18:25:37 by skimura           #+#    #+#             */
/*   Updated: 2025/06/13 15:38:34 by skimura          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rra(t_stack *a)
{
	reverse_rotate(a);
}

void	rrb(t_stack *b)
{
	reverse_rotate(b);
}

void	rrr(t_stack *a, t_stack *b)
{
	reverse_rotate(a);
	reverse_rotate(b);
}
