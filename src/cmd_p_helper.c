/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_p_helper.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skimura <skimura@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/10 17:38:48 by skimura           #+#    #+#             */
/*   Updated: 2025/06/27 17:26:32 by skimura          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/push_swap.h"

static t_node	*remove_top_node(t_stack *stack);
static void		insert_top_node(t_stack *stack, t_node *node);

void	ft_push(t_stack *from, t_stack *to)
{
	t_node	*node;

	node = remove_top_node(from);
	if (node)
		insert_top_node(to, node);
}

static t_node	*remove_top_node(t_stack *stack)
{
	t_node	*node;

	if (!stack || stack->size == 0)
		return (NULL);
	node = stack->top->next;
	node->prev->next = node->next;
	node->next->prev = node->prev;
	node->next = NULL;
	node->prev = NULL;
	stack->size--;
	return (node);
}

static void	insert_top_node(t_stack *stack, t_node *node)
{
	t_node	*first;

	if (!stack || !node)
		return ;
	first = stack->top->next;
	node->next = first;
	node->prev = stack->top;
	first->prev = node;
	stack->top->next = node;
	stack->size++;
}
