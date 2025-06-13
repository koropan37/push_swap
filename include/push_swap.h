/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skimura <skimura@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/02 15:46:53 by skimura           #+#    #+#             */
/*   Updated: 2025/06/13 18:04:27 by skimura          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft.h"
# include <stdlib.h>
# include <unistd.h>

typedef struct s_node
{
	int				value;
	int				original_value;
	struct s_node	*prev;
	struct s_node	*next;
}					t_node;

typedef struct s_stack
{
	t_node			*top;
	int				size;
}					t_stack;

typedef struct s_sort_info
{
	char			*base_ptr;
	size_t			size;
	int				(*cmp)(const void *, const void *);
}					t_sort_info;

// qsort
void				ft_swap(void *a, void *b, size_t size);
void				my_qsort(void *base, size_t n, size_t size,
						int (*cmp)(const void *, const void *));
// list_create
t_node				*new_node(int value);
t_node				*create_dummy_node(void);
t_node				*create_dlist_from_array(int *arr, int size);
// list_compress
int					binary_search(int *arr, int size, int target);
int					cmp_int(const void *a, const void *b);
void				compress_coordinates(t_node *head);
// list_helper
void				restore_original_values(t_node *head);
void				free_list(t_node *head);
void				print_list(t_node *dummy);
int					list_size(t_node *dummy);
// p_helper
void				push(t_stack *from, t_stack *to);
t_node				*remove_top_node(t_stack *stack);
void				insert_top_node(t_stack *stack, t_node *node);
// s_r_rr_helper
void				swap_top_two(t_stack *stack);
void				rotate(t_stack *stack);
void				reverse_rotate(t_stack *stack);

#endif
