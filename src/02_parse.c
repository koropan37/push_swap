/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   02_parse.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skimura <skimura@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/24 17:33:02 by skimura           #+#    #+#             */
/*   Updated: 2025/06/27 19:34:51 by skimura          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/push_swap.h"

static void	validate_block(char **block, int *values);
static long	ft_atol_ps(const char *s);
static int	ft_is_int(const char *s);
static int	ft_duplicate(int *arr, int size);

int	*ft_parse(int ac, char *av[], int *size)
{
	char	**block;
	int		*values;

	block = parse_args(ac, av);
	*size = count_block(block);
	values = malloc(sizeof(int) * (*size));
	if (!values)
		ft_printerror();
	validate_block(block, values);
	if (ft_duplicate(values, *size))
		ft_printerror();
	free_split(block);
	return (values);
}

static void	validate_block(char **block, int *values)
{
	long	num;
	int		i;

	i = 0;
	while (block[i])
	{
		if (!ft_is_int(block[i]))
			ft_printerror();
		num = ft_atol_ps(block[i]);
		if (num < INT_MIN || num > INT_MAX)
			ft_printerror();
		values[i] = (int)num;
		i++;
	}
}

long	ft_atol_ps(const char *s)
{
	long	res;
	int		sign;

	res = 0;
	sign = 1;
	if (*s == '+' || *s == '-')
	{
		if (*s == '-')
			sign = -1;
		s++;
	}
	while (ft_isdigit(*s))
	{
		res = res * 10 + (*s - '0');
		s++;
	}
	return (res * sign);
}

static int	ft_is_int(const char *s)
{
	if (*s == '-' || *s == '+')
		s++;
	if (*s == '\0')
		return (0);
	while (*s)
	{
		if (!ft_isdigit(*s))
			return (0);
		s++;
	}
	return (1);
}

static int	ft_duplicate(int *arr, int size)
{
	int	i;
	int	j;

	i = 0;
	while (i < size)
	{
		j = i + 1;
		while (j < size)
		{
			if (arr[i] == arr[j])
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}
