/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   02.1_parse_args.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skimura <skimura@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/24 20:26:13 by skimura           #+#    #+#             */
/*   Updated: 2025/06/30 19:11:30 by skimura          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/push_swap.h"

int		count_total_block(int argc, char **argv);
int		count_block_in_arg(const char *arg);
void	copy_block(int argc, char **argv, char **result);
int		copy_split_arg(char *arg, char **result, int n);

char	**parse_args(int argc, char **argv)
{
	int		total;
	char	**result;

	total = count_total_block(argc, argv);
	result = malloc(sizeof(char *) * (total + 1));
	if (!result)
		ft_printerror();
	result[total] = NULL;
	copy_block(argc, argv, result);
	return (result);
}

int	count_total_block(int argc, char **argv)
{
	int	total;
	int	i;

	total = 0;
	i = 1;
	while (i < argc)
	{
		total += count_block_in_arg(argv[i]);
		i++;
	}
	return (total);
}

int	count_block_in_arg(const char *arg)
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
		ft_printerror_and_free(block);
	if (!block[0])
	{
		free_split(block);
		ft_printerror();
	}
	while (block[i])
	{
		if (block[i][0] == '\0')
			ft_printerror_and_free(block);
		count++;
		i++;
	}
	free_split(block);
	return (count);
}

void	copy_block(int argc, char **argv, char **result)
{
	int	i;
	int	n;

	n = 0;
	i = 1;
	while (i < argc)
	{
		n = copy_split_arg(argv[i], result, n);
		i++;
	}
}

int	copy_split_arg(char *arg, char **result, int n)
{
	char	**copy;
	int		j;

	copy = ft_split(arg, ' ');
	if (!copy)
		free_all_and_error(result, copy, n);
	if (!copy[0])
		free_all_and_error(result, copy, n);
	j = 0;
	while (copy[j])
	{
		if (copy[j][0] == '\0')
			free_all_and_error(result, copy, n);
		result[n] = ft_strdup(copy[j]);
		if (!result[n])
			free_all_and_error(result, copy, n);
		n++;
		j++;
	}
	free_split(copy);
	return (n);
}
