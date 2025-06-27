/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skimura <skimura@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/04 19:26:11 by skimura           #+#    #+#             */
/*   Updated: 2025/06/27 11:37:13 by skimura          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include "libft.h"

int	ft_check_nl(const char *s)
{
	if (!s)
		return (0);
	while (*s)
	{
		if (*s == '\n')
			return (1);
		s++;
	}
	return (0);
}

char	*ft_strjoin_free(char *old, const char *buffer)
{
	char	*new;
	size_t	i;
	size_t	j;

	if (!buffer)
		return (free(old), NULL);
	if (!old)
		return (ft_strdup(buffer));
	new = malloc(ft_strlen(old) + ft_strlen(buffer) + 1);
	if (!new)
		return (free(old), NULL);
	i = -1;
	while (old[++i])
		new[i] = old[i];
	j = 0;
	while (buffer[j])
		new[i++] = buffer[j++];
	new[i] = '\0';
	free(old);
	return (new);
}
