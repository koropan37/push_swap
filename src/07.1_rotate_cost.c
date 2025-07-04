/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   07_cost.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skimura <skimura@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/21 16:31:34 by skimura           #+#    #+#             */
/*   Updated: 2025/06/27 19:35:58 by skimura          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/push_swap.h"

static void	rotate_both(t_stack *a, t_stack *b, t_node *target);
static void	rotate_a_only(t_stack *a, t_node *target);
static void	rotate_b_only(t_stack *b, t_node *target);

void	rotate_and_push(t_stack *a, t_stack *b, t_node *target)
{
	rotate_both(a, b, target);
	rotate_a_only(a, target);
	rotate_b_only(b, target);
	pa(a, b);
}

static void	rotate_both(t_stack *a, t_stack *b, t_node *target)
{
	while (target->cost_a > 0 && target->cost_b > 0)
	{
		rr(a, b);
		target->cost_a--;
		target->cost_b--;
	}
	while (target->cost_a < 0 && target->cost_b < 0)
	{
		rrr(a, b);
		target->cost_a++;
		target->cost_b++;
	}
}

static void	rotate_a_only(t_stack *a, t_node *target)
{
	while (target->cost_a > 0)
	{
		ra(a);
		target->cost_a--;
	}
	while (target->cost_a < 0)
	{
		rra(a);
		target->cost_a++;
	}
}

static void	rotate_b_only(t_stack *b, t_node *target)
{
	while (target->cost_b > 0)
	{
		rb(b);
		target->cost_b--;
	}
	while (target->cost_b < 0)
	{
		rrb(b);
		target->cost_b++;
	}
}
