/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   07.1_cost_calculate.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skimura <skimura@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/27 17:17:16 by skimura           #+#    #+#             */
/*   Updated: 2025/06/27 17:18:31 by skimura          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/push_swap.h"

void	calculate_cost(t_stack *a, t_stack *b)
{
	t_node	*cur;
	int		idx_b;
	int		target_idx;

	cur = b->top->next;
	idx_b = 0;
	while (cur != b->top)
	{
		if (idx_b <= b->size / 2)
			cur->cost_b = idx_b;
		else
			cur->cost_b = idx_b - b->size;
		target_idx = get_target_idx_in_a(a, cur->value);
		if (target_idx <= a->size / 2)
			cur->cost_a = target_idx;
		else
			cur->cost_a = target_idx - a->size;
		if ((cur->cost_a >= 0 && cur->cost_b >= 0) || (cur->cost_a < 0
				&& cur->cost_b < 0))
			cur->total = cmp_max(ft_abs(cur->cost_a), ft_abs(cur->cost_b));
		else
			cur->total = ft_abs(cur->cost_a) + ft_abs(cur->cost_b);
		cur = cur->next;
		idx_b++;
	}
}

int	cmp_max(int a, int b)
{
	if (a > b)
		return (a);
	else
		return (b);
}
