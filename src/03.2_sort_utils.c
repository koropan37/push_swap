/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   03.2_sort_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skimura <skimura@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/25 19:49:27 by skimura           #+#    #+#             */
/*   Updated: 2025/06/28 16:16:44 by skimura          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/push_swap.h"

int		find_min_idx_in_a(t_stack *a);
void	rotate_a_top_to_min(t_stack *a);

void	move_min_to_b(t_stack *a, t_stack *b)
{
	rotate_a_top_to_min(a);
	if (is_sorted(a))
		return ;
	pb(a, b);
}

void	rotate_a_top_to_min(t_stack *a)
{
	int	min_idx;
	int	n;

	min_idx = find_min_idx_in_a(a);
	if (min_idx <= a->size / 2)
	{
		while (min_idx-- > 0)
			ra(a);
	}
	else
	{
		n = a->size - min_idx;
		while (n-- > 0)
			rra(a);
	}
}

void	insert_node_to_sorted_a(t_stack *a, t_stack *b)
{
	t_node	*node;
	int		target_idx;

	node = b->top->next;
	target_idx = get_target_idx_in_a(a, node->value);
	if (target_idx <= a->size / 2)
	{
		while (target_idx-- > 0)
			ra(a);
	}
	else
	{
		target_idx = a->size - target_idx;
		while (target_idx-- > 0)
			rra(a);
	}
	pa(a, b);
}

int	find_min_idx_in_a(t_stack *a)
{
	t_node	*cur;
	int		min_value;
	int		idx;
	int		min_idx;

	cur = a->top->next;
	min_value = cur->value;
	idx = 0;
	min_idx = 0;
	while (cur != a->top)
	{
		if (cur->value < min_value)
		{
			min_value = cur->value;
			min_idx = idx;
		}
		cur = cur->next;
		idx++;
	}
	return (min_idx);
}
