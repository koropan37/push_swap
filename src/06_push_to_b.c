/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   06_push_to_b.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skimura <skimura@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/21 16:36:27 by skimura           #+#    #+#             */
/*   Updated: 2025/06/27 19:47:25 by skimura          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/push_swap.h"

int		is_in_lis(int value, int *lis, int lis_len);
int		has_non_lis_element(t_stack *a, int *lis, int lis_len);

void	push_not_lis_to_b(t_stack *a, t_stack *b, int *lis, int lis_len)
{
	while (has_non_lis_element(a, lis, lis_len))
	{
		if (is_in_lis(a->top->next->value, lis, lis_len))
		{
			ra(a);
		}
		else
		{
			pb(a, b);
		}
	}
}

int	has_non_lis_element(t_stack *a, int *lis, int lis_len)
{
	t_node	*cur;

	if (a->size == 0)
		return (0);
	cur = a->top->next;
	while (cur != a->top)
	{
		if (!is_in_lis(cur->value, lis, lis_len))
			return (1);
		cur = cur->next;
	}
	return (0);
}

int	is_in_lis(int value, int *lis, int lis_len)
{
	int	i;

	i = 0;
	while (i < lis_len)
	{
		if (lis[i] == value)
			return (1);
		i++;
	}
	return (0);
}
