/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   03_solve.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skimura <skimura@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/02 15:46:30 by skimura           #+#    #+#             */
/*   Updated: 2025/06/28 15:40:25 by skimura          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/push_swap.h"

int			is_sorted(t_stack *a);
static void	do_push_swap(t_stack *a);
void		sort_stack(t_stack *a, t_stack *b);

void	solve_push_swap(int *arr, int size)
{
	t_stack	*a;

	a = build_compressed_stack(arr, size);
	if (!a)
		ft_printerror();
	if (is_sorted(a))
	{
		free_stack(a);
		return ;
	}
	do_push_swap(a);
	free_stack(a);
}

int	is_sorted(t_stack *a)
{
	t_node	*cur;

	if (a->size <= 1)
		return (1);
	cur = a->top->next;
	while (cur->next != a->top)
	{
		if (cur->value > cur->next->value)
			return (0);
		cur = cur->next;
	}
	return (1);
}

void	do_push_swap(t_stack *a)
{
	t_stack	*b;

	b = malloc(sizeof(t_stack));
	if (!b)
		ft_printerror();
	b->top = create_dummy_node();
	if (!b->top)
	{
		free(b);
		ft_printerror();
	}
	b->size = 0;
	sort_stack(a, b);
	free_list(b->top);
	free(b);
}

void	sort_stack(t_stack *a, t_stack *b)
{
	int	*lis;
	int	lis_len;

	if (a->size == 2)
	{
		if (a->top->next->value > a->top->next->next->value)
			sa(a);
	}
	else if (a->size == 3)
		sort_three(a);
	else if (a->size == 4)
		sort_four(a, b);
	else if (a->size == 5)
		sort_five(a, b);
	else
	{
		lis = find_lis(a, &lis_len);
		if (!lis)
			ft_printerror();
		push_not_lis_to_b(a, b, lis, lis_len);
		free(lis);
		greedy_sort(a, b);
	}
}
