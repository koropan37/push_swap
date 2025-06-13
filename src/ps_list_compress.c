/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_list_compress.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skimura <skimura@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/13 16:49:10 by skimura           #+#    #+#             */
/*   Updated: 2025/06/13 16:51:01 by skimura          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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

int	cmp_int(const void *a, const void *b)
{
	return (*(const int *)a - *(const int *)b);
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

	sorted = malloc(sizeof(int) * size);
	if (!sorted)
		return ;
	ft_memcpy(sorted, array, sizeof(int) * size);
	my_qsort(sorted, size, sizeof(int), cmp_int);
	cur = dummy->next;
	while (cur != dummy)
	{
		cur->value = binary_search(sorted, size, cur->value);
		cur = cur->next;
	}
	free(sorted);
}

void	compress_coordinates(t_node *dummy)
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
