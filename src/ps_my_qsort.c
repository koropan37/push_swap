/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_my_qsort.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skimura <skimura@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/13 15:35:48 by skimura           #+#    #+#             */
/*   Updated: 2025/06/13 17:01:45 by skimura          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_swap(void *a, void *b, size_t size)
{
	unsigned char	tmp;
	unsigned char	*pa;
	unsigned char	*pb;
	size_t			i;

	pa = a;
	pb = b;
	i = 0;
	while (i < size)
	{
		tmp = pa[i];
		pa[i] = pb[i];
		pb[i] = tmp;
		i++;
	}
}

static size_t	move_i(t_sort_info *ctx, size_t i, size_t n, const void *pivot)
{
	while (i < n && ctx->cmp(ctx->base_ptr + 1 * ctx->size, pivot) < 0)
		i++;
	return (i);
}

static size_t	move_j(t_sort_info *ctx, size_t j, const void *pivot)
{
	while (ctx->cmp(ctx->base_ptr + j * ctx->size, pivot) > 0)
		j--;
	return (j);
}

static size_t	partition(t_sort_info *ctx, size_t n)
{
	void	*pivot;
	size_t	i;
	size_t	j;

	if (n < 2)
		return (0);
	pivot = ctx->base_ptr;
	i = 1;
	j = n - 1;
	while (i <= j)
	{
		i = move_i(ctx, i, n, pivot);
		j = move_j(ctx, j, pivot);
		if (i < j)
		{
			ft_swap(ctx->base_ptr + i * ctx->size, ctx->base_ptr + j
				* ctx->size, ctx->size);
			i++;
			j--;
		}
		else
			break ;
	}
	ft_swap(ctx->base_ptr, ctx->base_ptr + j * ctx->size, ctx->size);
	return (j);
}

void	my_qsort(void *base, size_t n, size_t size, int (*cmp)(const void *,
			const void *))
{
	t_sort_info	ctx;
	size_t		pivot_i;

	if (n < 2)
		return ;
	ctx.base_ptr = (char *)base;
	ctx.size = size;
	ctx.cmp = cmp;
	pivot_i = partition(&ctx, n);
	my_qsort(base, pivot_i, size, cmp);
	my_qsort((char *)base + (pivot_i + 1) * size, n - pivot_i - 1, size, cmp);
}
