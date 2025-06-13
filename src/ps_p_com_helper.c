/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_p_com_helper.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skimura <skimura@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/10 17:38:48 by skimura           #+#    #+#             */
/*   Updated: 2025/06/13 20:39:31 by skimura          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_push(t_stack *from, t_stack *to)
{
	t_node	*node;

	node = remove_top_node(from);
	if (node)
		insert_top_node(to, node);
}

t_node	*remove_top_node(t_stack *stack)
{
	t_node	*node;

	node = stack->top;
	if (!stack || stack->size == 0)
		return (NULL);
	if (stack->size == 1)
		stack->top = NULL;
	else
	{
		node->prev->next = node->next;
		node->next->prev = node->prev;
		stack->top = node->next;
	}
	stack->size--;
}

void	insert_top_node(t_stack *stack, t_node *node)
{
	t_node	*old_top;
	t_node	*last;

	if (stack->size == 0)
	{
		node->next = node;
		node->prev = node;
		stack->top = node;
	}
	else
	{
		old_top = stack->top;
		last = old_top->prev;
		node->next = old_top;
		node->prev = last;
		last->next = node;
		old_top->prev = node;
		stack->top = node;
	}
	stack->size++;
}
