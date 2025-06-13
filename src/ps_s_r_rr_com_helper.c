/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_utils_r_s.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skimura <skimura@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/11 18:07:03 by skimura           #+#    #+#             */
/*   Updated: 2025/06/13 15:38:25 by skimura          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap_top_two(t_stack *stack)
{
	t_node	*first;
	t_node	*second;
	int		tmp;

	if (!stack || stack->size < 2)
		return ;
	first = stack->top;
	second = first->next;
	tmp = first->value;
	first->value = second->value;
	second->value = tmp;
}

void	rotate(t_stack *stack)
{
	if (!stack || stack->size < 2)
		return ;
	stack->top = stack->top->next;
}

void	reverse_rotate(t_stack *stack)
{
	if (!stack || stack->size < 2)
		return ;
	stack->top = stack->top->prev;
}
