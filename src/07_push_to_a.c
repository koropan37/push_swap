/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   06.1_push_to_a.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skimura <skimura@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/22 16:41:58 by skimura           #+#    #+#             */
/*   Updated: 2025/06/27 17:24:21 by skimura          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/push_swap.h"
#include "push_swap.h"

int		get_target_idx_in_a(t_stack *a, int value);
t_node	*find_min_cost_node(t_stack *a);

void	greedy_sort(t_stack *a, t_stack *b)
{
	t_node	*best;
	int		min_idx;

	while (b->size > 0)
	{
		calculate_cost(a, b);
		best = find_min_cost_node(b);
		rotate_and_push(a, b, best);
	}
	min_idx = find_min_idx_in_a(a);
	if (min_idx <= a->size / 2)
		while (min_idx--)
			ra(a);
	else
		while (min_idx++ < a->size)
			rra(a);
}

int	get_target_idx_in_a(t_stack *a, int value)
{
	t_node	*cur;
	t_node	*best;
	int		best_idx;
	int		idx;

	if (a->size == 0)
		return (0);
	cur = a->top->next;
	best = NULL;
	best_idx = 0;
	idx = 0;
	while (cur != a->top)
	{
		if (value < cur->value && (!best || cur->value < best->value))
		{
			best = cur;
			best_idx = idx;
		}
		cur = cur->next;
		idx++;
	}
	if (!best)
		return (find_min_idx_in_a(a));
	return (best_idx);
}

t_node	*find_min_cost_node(t_stack *a)
{
	t_node	*cur;
	t_node	*min;

	if (a->size == 0)
		return (NULL);
	cur = a->top->next;
	min = cur;
	cur = cur->next;
	while (cur != a->top)
	{
		if (cur->total < min->total || cur->total == min->total)
			min = cur;
		cur = cur->next;
	}
	return (min);
}
