/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   04.2_compress_list.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skimura <skimura@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/13 16:49:10 by skimura           #+#    #+#             */
/*   Updated: 2025/06/27 21:09:50 by skimura          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/push_swap.h"

static int	*extract_values(t_node *dummy, int size);
static void	compress_values(t_node *dummy, int *array, int size);
int			binary_search(int *arr, int size, int target);

void	compress_ranking(t_node *dummy)
{
	int	size;
	int	*array;

	if (!dummy)
		return ;
	size = list_size(dummy);
	array = extract_values(dummy, size);
	if (!array)
		return ;
	compress_values(dummy, array, size);
	free(array);
}

static int	*extract_values(t_node *dummy, int size)
{
	int		*array;
	int		i;
	t_node	*cur;

	i = 0;
	array = malloc(sizeof(int) * size);
	if (!array)
		return (NULL);
	cur = dummy->next;
	while (cur != dummy)
	{
		array[i++] = cur->value;
		cur = cur->next;
	}
	return (array);
}

static void	compress_values(t_node *dummy, int *array, int size)
{
	int		*sorted;
	t_node	*cur;
	int		i;

	i = 0;
	sorted = malloc(sizeof(int) * size);
	if (!sorted)
		return ;
	while (i < size)
	{
		sorted[i] = array[i];
		i++;
	}
	ft_qsort(sorted, 0, size - 1);
	cur = dummy->next;
	while (cur != dummy)
	{
		cur->value = binary_search(sorted, size, cur->value);
		cur = cur->next;
	}
	free(sorted);
}

int	binary_search(int *arr, int size, int target)
{
	int	left;
	int	right;
	int	mid;

	left = 0;
	right = size - 1;
	while (left <= right)
	{
		mid = (left + right) / 2;
		if (arr[mid] == target)
			return (mid);
		else if (arr[mid] < target)
			left = mid + 1;
		else
			right = mid - 1;
	}
	return (-1);
}
