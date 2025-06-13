/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_list_helper.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skimura <skimura@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/13 16:52:03 by skimura           #+#    #+#             */
/*   Updated: 2025/06/13 21:46:16 by skimura          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	unsigned char		*d;
	unsigned const char	*s;
	size_t				i;

	if ((!dest || !src) && n != 0)
		return (NULL);
	d = (unsigned char *)dest;
	s = (unsigned const char *)src;
	i = 0;
	while (i < n)
	{
		d[i] = s[i];
		i++;
	}
	return (dest);
}

int	list_size(t_node *dummy)
{
	int		count;
	t_node	*cur;

	if (!dummy)
		return (0);
	count = 0;
	cur = dummy->next;
	while (cur != dummy)
	{
		count++;
		cur = cur->next;
	}
	return (count);
}

void	restore_original_values(t_node *dummy)
{
	t_node	*cur;

	if (!dummy)
		return ;
	cur = dummy->next;
	while (cur != dummy)
	{
		cur->value = cur->original_value;
		cur = cur->next;
	}
}

void	free_list(t_node *dummy)
{
	t_node	*cur;
	t_node	*next;

	if (!dummy)
		return ;
	cur = dummy->next;
	while (cur != dummy)
	{
		next = cur->next;
		free(cur);
		cur = next;
	}
	free(dummy);
}

void	print_list(t_node *dummy)
{
	t_node	*cur;

	if (!dummy || dummy->next == dummy)
	{
		printf("(empty list)\n");
		return ;
	}
	cur = dummy->next;
	while (cur != dummy)
	{
		printf("%d, ", cur->value);
		cur = cur->next;
	}
	printf("\n");
}
