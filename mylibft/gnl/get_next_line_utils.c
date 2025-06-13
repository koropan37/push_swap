/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skimura <skimura@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/04 19:26:11 by skimura           #+#    #+#             */
/*   Updated: 2025/06/01 21:50:43 by skimura          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

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

char	*ft_strdup(const char *s)
{
	char	*new;
	size_t	i;
	size_t	len;

	if (!s)
		return (NULL);
	len = ft_strlen(s);
	new = malloc(len + 1);
	if (!new)
		return (NULL);
	i = 0;
	while (i < len)
	{
		new[i] = s[i];
		i++;
	}
	new[i] = '\0';
	return (new);
}

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


char	*ft_substr(char const *s, size_t start, size_t len)
{
	size_t	sub_len;
	char	*substr;
	size_t	i;

	if (!s)
		return (NULL);
	sub_len = ft_strlen(s);
	if (start >= sub_len)
		return (ft_strdup(""));
	if (len > sub_len - start)
		len = sub_len - start;
	substr = (char *)malloc(sizeof(char) * (len + 1));
	if (!substr)
		return (NULL);
	i = 0;
	while (i < len)
	{
		substr[i] = s[i + start];
		i++;
	}
	substr[i] = '\0';
	return (substr);
}
