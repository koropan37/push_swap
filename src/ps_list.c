/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_list.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skimura <skimura@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/09 15:37:56 by skimura           #+#    #+#             */
/*   Updated: 2025/06/13 17:25:26 by skimura          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(void)
{
	int		values[] = {95, 7, 82, 30, 21, 22, 35, 69, 10, 77, 75, 74, 1, -10};
	int		size;
	t_node	*dummy;

	size = sizeof(values) / sizeof(int);
	dummy = create_dlist_from_array(values, size);
	print_list(dummy);
	compress_coordinates(dummy);
	print_list(dummy);
	restore_original_values(dummy);
	print_list(dummy);
	free_list(dummy);
	return (0);
}
