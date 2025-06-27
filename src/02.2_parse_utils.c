/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   02.2_parse_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skimura <skimura@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/24 22:12:18 by skimura           #+#    #+#             */
/*   Updated: 2025/06/27 11:08:07 by skimura          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/push_swap.h"

void	free_split(char **block)
{
	int	i;

	i = 0;
	while (block[i])
		free(block[i++]);
	free(block);
}

int	count_block(char **block)
{
	int	count;

	count = 0;
	while (block[count])
		count++;
	return (count);
}
