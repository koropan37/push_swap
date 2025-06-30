/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   02_parse.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skimura <skimura@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/24 17:33:02 by skimura           #+#    #+#             */
/*   Updated: 2025/06/29 19:21:16 by skimura          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/push_swap.h"

void		validate_block(char **block, int *values);
long		ft_atol_ps(const char *s);
int			ft_is_int(const char *s);
int			ft_duplicate(int *arr, int size);

int	*ft_parse(int argc, char **argv, int *size)
{
	char	**block;
	int		*values;

	block = parse_args(argc, argv);
	*size = count_block(block);
	values = malloc(sizeof(int) * (*size));
	if (!values)
		ft_printerror();
	validate_block(block, values);
	if (ft_duplicate(values, *size))
	{
		free(values);
		ft_printerror_and_free(block);
	}
	free_split(block);
	return (values);
}

void	validate_block(char **block, int *values)
{
	long	num;
	int		i;

	i = 0;
	while (block[i])
	{
		if (!ft_is_int(block[i]))
		{
			free(values);
			ft_printerror_and_free(block);
		}
		num = ft_atol_ps(block[i]);
		if (num < INT_MIN || num > INT_MAX)
		{
			free(values);
			ft_printerror_and_free(block);
		}
		values[i] = (int)num;
		i++;
	}
}

int	ft_is_int(const char *s)
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

int	ft_duplicate(int *arr, int size)
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
