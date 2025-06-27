/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   05_lis.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skimura <skimura@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/20 16:36:48 by skimura           #+#    #+#             */
/*   Updated: 2025/06/27 18:30:16 by skimura          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/push_swap.h"

static int	extract_indexes(t_stack *a, t_lis *info);
static void	init_tables(t_lis *info);
static void	update_lis(t_lis *info);
static int	*rebuild_lis(int *idx, int *prev, int max_end, int max_len);

int	*find_lis(t_stack *a, int *lis_len)
{
	t_lis	info;
	int		*lis;

	if (!a || !lis_len || a->size <= 0)
		return (NULL);
	info.size = a->size;
	info.idx = NULL;
	info.dp = malloc(sizeof(int) * info.size);
	info.prev = malloc(sizeof(int) * info.size);
	if (!info.dp || !info.prev || !extract_indexes(a, &info))
	{
		free(info.dp);
		free(info.prev);
		free(info.idx);
		return (NULL);
	}
	init_tables(&info);
	update_lis(&info);
	lis = rebuild_lis(info.idx, info.prev, info.max_end, info.max_len);
	*lis_len = info.max_len;
	free(info.dp);
	free(info.prev);
	free(info.idx);
	return (lis);
}

static int	extract_indexes(t_stack *a, t_lis *info)
{
	t_node	*cur;
	int		i;

	info->idx = malloc(sizeof(int) * info->size);
	if (!info->idx)
		return (0);
	cur = a->top->next;
	i = 0;
	while (i < info->size && cur != a->top)
	{
		info->idx[i++] = cur->value;
		cur = cur->next;
	}
	if (i != info->size)
	{
		return (0);
	}
	return (1);
}

static void	init_tables(t_lis *info)
{
	int	i;

	i = 0;
	while (i < info->size)
	{
		info->dp[i] = 1;
		info->prev[i] = -1;
		i++;
	}
}

static void	update_lis(t_lis *info)
{
	int	i;
	int	j;

	i = 0;
	info->max_len = 1;
	info->max_end = 0;
	while (i < info->size)
	{
		j = 0;
		while (j < i)
		{
			if (info->idx[j] < info->idx[i] && info->dp[j] + 1 > info->dp[i])
			{
				info->dp[i] = info->dp[j] + 1;
				info->prev[i] = j;
			}
			j++;
		}
		if (info->dp[i] > info->max_len)
		{
			info->max_len = info->dp[i];
			info->max_end = i;
		}
		i++;
	}
}

static int	*rebuild_lis(int *idx, int *prev, int max_end, int max_len)
{
	int	*lis;
	int	i;

	i = max_len - 1;
	lis = malloc(sizeof(int) * max_len);
	if (!lis)
		return (NULL);
	while (i >= 0)
	{
		lis[i] = idx[max_end];
		max_end = prev[max_end];
		i--;
	}
	return (lis);
}

// void	print_lis(int *lis, int len)
// {
// 	printf("LIS (length %d): ", len);
// 	for (int i = 0; i < len; i++)
// 		printf("%d ", lis[i]);
// 	printf("\n");
// }

// int	main(void)
// {
// 	int		values[] = {2, 45, 19, 32, 48, 14, 3, 23, 29, 27, 38, 36, 13, 9, 25,
// 				20, 49, 10, 4, 47, 28, 6, 40, 7, 26, 31, 22, 42, 16, 12, 35, 44,
// 				24, 1, 41, 0, 5, 33, 30, 11, 8, 50, 21, 18, 37, 39, 43, 34, 15,
// 				17};
// 	int		n;
// 	t_node	*dummy;
// 	t_node	*cur;
// 	t_stack	stack;
// 	int		lis_len;
// 	int		*lis;

// 	n = sizeof(values) / sizeof(values[0]);
// 	dummy = create_dummy_node();
// 	cur = dummy;
// 	if (!dummy)
// 		return (1);
// 	for (int i = 0; i < n; i++)
// 	{
// 		if (!new_node_to_dlist(dummy, &cur, values[i]))
// 		{
// 			printf("Failed to build list.\n");
// 			free_list(dummy);
// 			return (1);
// 		}
// 	}
// 	compress_ranking(dummy);
// 	set_stack_data(&stack, dummy);
// 	lis = find_lis(&stack, &lis_len);
// 	if (!lis)
// 	{
// 		printf("Failed to find LIS.\n");
// 		free_list(dummy);
// 		return (1);
// 	}
// 	print_lis(lis, lis_len);
// 	free(lis);
// 	free_list(dummy);
// 	return (0);
// }
