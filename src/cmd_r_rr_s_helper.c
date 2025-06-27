/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_r_rr_s_helper.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skimura <skimura@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/11 18:07:03 by skimura           #+#    #+#             */
/*   Updated: 2025/06/27 19:35:26 by skimura          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/push_swap.h"

void	rotate(t_stack *stack)
{
	t_node	*first;

	if (!stack || stack->size < 2)
		return ;
	first = stack->top->next;
	first->prev->next = first->next;
	first->next->prev = first->prev;
	first->prev = stack->top->prev;
	first->next = stack->top;
	stack->top->prev->next = first;
	stack->top->prev = first;
}

void	reverse_rotate(t_stack *stack)
{
	t_node	*last;

	if (!stack || stack->size < 2)
		return ;
	last = stack->top->prev;
	last->prev->next = stack->top;
	stack->top->prev = last->prev;
	last->next = stack->top->next;
	last->prev = stack->top;
	stack->top->next->prev = last;
	stack->top->next = last;
}

void	swap_top_two(t_stack *stack)
{
	t_node	*first;
	t_node	*second;
	int		tmp;

	if (!stack || stack->size < 2)
		return ;
	first = stack->top->next;
	second = first->next;
	tmp = first->value;
	first->value = second->value;
	second->value = tmp;
}
