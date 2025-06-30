/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   02.2_parse_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skimura <skimura@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/24 22:12:18 by skimura           #+#    #+#             */
/*   Updated: 2025/06/29 17:26:02 by skimura          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/push_swap.h"

int		count_block(char **block);
void	free_split(char **block);
void	ft_printerror_and_free(char **block);
void	free_all_and_error(char **result, char **copy, int n);

void	ft_printerror(void)
{
	write(2, "error\n", 6);
	exit(1);
}

int	count_block(char **block)
{
	int	count;

	count = 0;
	while (block[count])
		count++;
	return (count);
}

void	free_split(char **block)
{
	int	i;

	if (!block)
		return ;
	i = 0;
	while (block[i])
		free(block[i++]);
	free(block);
}

void	ft_printerror_and_free(char **block)
{
	if (block)
		free_split(block);
	ft_printerror();
}

void	free_all_and_error(char **result, char **copy, int n)
{
	int	i;

	i = 0;
	while (i < n)
	{
		if (result[i])
			free(result[i]);
		i++;
	}
	free(result);
	ft_printerror_and_free(copy);
}
