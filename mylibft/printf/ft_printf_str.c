/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_str.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skimura <skimura@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/16 16:25:32 by skimura           #+#    #+#             */
/*   Updated: 2025/06/27 15:42:56 by skimura          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_put_c(char c)
{
	ssize_t	bytes;

	bytes = write(1, &c, 1);
	if (bytes == -1)
		return (-1);
	return ((int)bytes);
}

int	ft_put_s(char *s)
{
	ssize_t	bytes;

	if (!s)
		bytes = write(1, "(null)", 6);
	else
		bytes = write(1, s, ft_strlen(s));
	if (bytes == -1)
		return (-1);
	return ((int)bytes);
}

size_t	ft_strlen(const char *s)
{
	size_t	len;

	if (!s)
		return (0);
	len = 0;
	while (s[len])
		len++;
	return (len);
}
