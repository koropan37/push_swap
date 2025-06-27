/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   04_list.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skimura <skimura@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/13 16:52:03 by skimura           #+#    #+#             */
/*   Updated: 2025/06/27 19:49:22 by skimura          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/push_swap.h"

void	set_stack_data(t_stack *stack, t_node *dummy);
int		list_size(t_node *dummy);
void	free_list(t_node *dummy);
void	free_stack(t_stack *stack);

t_stack	*build_compressed_stack(int *arr, int size)
{
	t_node	*dummy;
	t_stack	*stack;

	if (size <= 0 || !arr)
		return (NULL);
	dummy = create_dlist_from_array(arr, size);
	if (!dummy)
		return (NULL);
	compress_ranking(dummy);
	stack = malloc(sizeof(t_stack));
	if (!stack)
	{
		free_list(dummy);
		return (NULL);
	}
	set_stack_data(stack, dummy);
	return (stack);
}

void	set_stack_data(t_stack *stack, t_node *dummy)
{
	stack->top = dummy;
	stack->size = list_size(dummy);
}

int	list_size(t_node *dummy)
{
	int		count;
	t_node	*cur;

	if (!dummy)
		return (0);
	count = 0;
	cur = dummy->next;
	while (cur != dummy)
	{
		count++;
		cur = cur->next;
	}
	return (count);
}

void	free_list(t_node *dummy)
{
	t_node	*cur;
	t_node	*next;

	if (!dummy)
		return ;
	cur = dummy->next;
	while (cur != dummy)
	{
		next = cur->next;
		free(cur);
		cur = next;
	}
	free(dummy);
}

void	free_stack(t_stack *stack)
{
	if (!stack)
		return ;
	free_list(stack->top);
	free(stack);
}
