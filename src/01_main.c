/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   01_main.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skimura <skimura@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/22 22:17:48 by skimura           #+#    #+#             */
/*   Updated: 2025/06/27 19:43:33 by skimura          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/push_swap.h"

void	ft_printerror(void)
{
	write(2, "error\n", 6);
	exit(1);
}

int	main(int ac, char **av)
{
	int	*arr;
	int	size;

	size = 0;
	if (ac < 2)
		return (0);
	arr = ft_parse(ac - 1, av + 1, &size);
	if (!arr)
		ft_printerror();
	solve_push_swap(arr, size);
	free(arr);
	return (0);
}
