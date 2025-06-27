/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   03.1_sort_under_five.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skimura <skimura@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/25 17:28:39 by skimura           #+#    #+#             */
/*   Updated: 2025/06/27 19:47:32 by skimura          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/push_swap.h"

void	sort_four(t_stack *a, t_stack *b);
void	sort_five(t_stack *a, t_stack *b);

void	sort_three(t_stack *a)
{
	int	x;
	int	y;
	int	z;

	x = a->top->next->value;
	y = a->top->next->next->value;
	z = a->top->prev->value;
	if (x > y && y < z && x < z)
		sa(a);
	else if (x > y && y < z && x > z)
		ra(a);
	else if (x < y && y > z && x > z)
		rra(a);
	else if (x < y && y > z && x < z)
	{
		sa(a);
		ra(a);
	}
	else if (x > y && y > z)
	{
		sa(a);
		rra(a);
	}
}

void	sort_four(t_stack *a, t_stack *b)
{
	move_min_to_b(a, b);
	sort_three(a);
	insert_node_to_sorted_a(a, b);
}

void	sort_five(t_stack *a, t_stack *b)
{
	move_min_to_b(a, b);
	sort_four(a, b);
	insert_node_to_sorted_a(a, b);
}
