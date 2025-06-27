/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   04.3_ft_qsort.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skimura <skimura@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/13 15:35:48 by skimura           #+#    #+#             */
/*   Updated: 2025/06/27 19:35:15 by skimura          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/push_swap.h"

void		ft_swap(int *a, int *b);
static int	partition(int *arr, int low, int high);

void	ft_qsort(int *arr, int low, int high)
{
	int	pivot_index;

	if (low < high)
	{
		pivot_index = partition(arr, low, high);
		ft_qsort(arr, low, pivot_index - 1);
		ft_qsort(arr, pivot_index + 1, high);
	}
}

void	ft_swap(int *a, int *b)
{
	int	tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}

static int	partition(int *arr, int low, int high)
{
	int	pivot;
	int	i;
	int	j;

	pivot = arr[low];
	i = low + 1;
	j = high;
	while (i <= j)
	{
		while (i <= high && arr[i] < pivot)
			i++;
		while (j >= low && arr[j] > pivot)
			j--;
		if (i < j)
			ft_swap(&arr[i++], &arr[j--]);
		else
			break ;
	}
	ft_swap(&arr[low], &arr[j]);
	return (j);
}
