/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_list_create.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skimura <skimura@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/13 16:13:31 by skimura           #+#    #+#             */
/*   Updated: 2025/06/13 17:27:18 by skimura          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_node	*new_node(int value)
{
	t_node	*node;

	node = malloc(sizeof(t_node));
	if (!node)
		return (NULL);
	node->value = value;
	node->original_value = value;
	node->prev = NULL;
	node->next = NULL;
	return (node);
}

t_node	*create_dummy_node(void)
{
	t_node	*dummy;

	dummy = malloc(sizeof(t_node));
	if (!dummy)
		return (NULL);
	dummy->next = dummy;
	dummy->prev = dummy;
	return (dummy);
}

static int	new_node_to_dlist(t_node *dummy, t_node **current, int value)
{
	t_node	*new;

	new = new_node(value);
	if (!new)
		return (0);
	new->next = dummy;
	new->prev = *current;
	dummy->prev = new;
	(*current)->next = new;
	*current = new;
	return (1);
}

static int	array_to_dlist(t_node *dummy, int *arr, int size)
{
	t_node	*current;
	int		i;

	current = dummy;
	i = 0;
	while (i < size)
	{
		if (!new_node_to_dlist(dummy, &current, arr[i]))
			return (0);
		i++;
	}
	return (1);
}

t_node	*create_dlist_from_array(int *arr, int size)
{
	t_node	*dummy;

	if (size <= 0)
		return (NULL);
	dummy = create_dummy_node();
	if (!dummy)
		return (NULL);
	if (!array_to_dlist(dummy, arr, size))
	{
		free_list(dummy);
		return (NULL);
	}
	return (dummy);
}
