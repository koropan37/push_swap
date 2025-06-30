/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   04.1_create_list.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skimura <skimura@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/13 16:13:31 by skimura           #+#    #+#             */
/*   Updated: 2025/06/29 19:18:52 by skimura          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/push_swap.h"

t_node	*new_node(int value);
t_node	*create_dummy_node(void);
int		new_node_to_dlist(t_node *dummy, t_node **current, int value);
int		array_to_dlist(t_node *dummy, int *arr, int size);

t_node	*create_dlist_from_array(int *arr, int size)
{
	t_node	*dummy;

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

int	array_to_dlist(t_node *dummy, int *arr, int size)
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

t_node	*new_node(int value)
{
	t_node	*node;

	node = malloc(sizeof(t_node));
	if (!node)
		return (NULL);
	node->value = value;
	node->prev = NULL;
	node->next = NULL;
	return (node);
}

int	new_node_to_dlist(t_node *dummy, t_node **current, int value)
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

// void	free_list(t_node *dummy)
// {
// 	t_node	*cur;
// 	t_node	*next;

// 	if (!dummy)
// 		return ;
// 	cur = dummy->next;
// 	while (cur != dummy)
// 	{
// 		next = cur->next;
// 		free(cur);
// 		cur = next;
// 	}
// 	free(dummy);
// }

// void	print_list(t_node *dummy)
// {
// 	t_node	*cur;

// 	if (!dummy || dummy->next == dummy)
// 	{
// 		printf("(empty list)\n");
// 		return ;
// 	}
// 	cur = dummy->next;
// 	while (cur != dummy)
// 	{
// 		printf("%d, ", cur->value);
// 		cur = cur->next;
// 	}
// 	printf("\n");
// }

// int	main(void)
// {
// 	int		values[] = {95, 7, 82, 30, 21, 22, 35, 69, 10, 77, 75, 74, 1, -10};
// 	int		size;
// 	t_node	*dummy;

// 	size = sizeof(values) / sizeof(int);
// 	dummy = create_dlist_from_array(values, size);
// 	print_list(dummy);
// 	compress_ranking(dummy);
// 	print_list(dummy);
// 	free_list(dummy);
// 	return (0);
// }
