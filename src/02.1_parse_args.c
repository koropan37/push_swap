/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   02.1_parse_args.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skimura <skimura@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/24 20:26:13 by skimura           #+#    #+#             */
/*   Updated: 2025/06/27 21:06:56 by skimura          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/push_swap.h"

static int	count_total_block(int ac, char **av);
static int	count_block_in_arg(const char *arg);
static char	**alloc_block(int total);
static void	copy_block(int ac, char **av, char **result);

char	**parse_args(int ac, char **av)
{
	int		total;
	char	**result;

	total = count_total_block(ac, av);
	result = alloc_block(total);
	copy_block(ac, av, result);
	return (result);
}

static int	count_total_block(int ac, char **av)
{
	int	total;
	int	i;

	total = 0;
	i = 0;
	while (i < ac)
	{
		total += count_block_in_arg(av[i]);
		i++;
	}
	return (total);
}

static int	count_block_in_arg(const char *arg)
{
	char	**block;
	int		count;
	int		i;

	count = 0;
	i = 0;
	if (arg[0] == '\0')
		ft_printerror();
	block = ft_split(arg, ' ');
	if (!block)
		ft_printerror();
	while (block[i])
	{
		if (block[i][0] == '\0')
			ft_printerror();
		count++;
		i++;
	}
	free_split(block);
	return (count);
}

static char	**alloc_block(int total)
{
	char	**result;

	result = malloc(sizeof(char *) * (total + 1));
	if (!result)
		ft_printerror();
	result[total] = NULL;
	return (result);
}

static void	copy_block(int ac, char **av, char **result)
{
	char	**copy;
	int		n;
	int		i;
	int		j;

	n = 0;
	i = 0;
	while (i < ac)
	{
		copy = ft_split(av[i], ' ');
		if (!copy)
			ft_printerror();
		j = 0;
		while (copy[j])
		{
			if (copy[j][0] == '\0')
				ft_printerror();
			result[n++] = ft_strdup(copy[j]);
			if (!result[n - 1])
				ft_printerror();
			j++;
		}
		free_split(copy);
		i++;
	}
}
