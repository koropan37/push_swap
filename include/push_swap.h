/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skimura <skimura@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/13 18:07:18 by skimura           #+#    #+#             */
/*   Updated: 2025/06/27 20:23:47 by skimura          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "mylibft/include/libft.h"
# include <limits.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct s_node
{
	int				value;
	struct s_node	*prev;
	struct s_node	*next;
	int				cost_a;
	int				cost_b;
	int				total;
}					t_node;

typedef struct s_stack
{
	t_node			*top;
	int				size;
}					t_stack;

typedef struct s_lis
{
	int				size;
	int				*idx;
	int				*dp;
	int				*prev;
	int				max_len;
	int				max_end;
}					t_lis;

// command
void				sa(t_stack *a);
void				sb(t_stack *b);
void				ss(t_stack *a, t_stack *b);
void				ra(t_stack *a);
void				rb(t_stack *b);
void				rr(t_stack *a, t_stack *b);
void				rra(t_stack *a);
void				rrb(t_stack *b);
void				rrr(t_stack *a, t_stack *b);
void				pa(t_stack *a, t_stack *b);
void				pb(t_stack *a, t_stack *b);
// p_helper
void				ft_push(t_stack *from, t_stack *to);
// s_r_rr_helper
void				swap_top_two(t_stack *stack);
void				rotate(t_stack *stack);
void				reverse_rotate(t_stack *stack);

// error
void				ft_printerror(void);
// parse
int					*ft_parse(int ac, char *av[], int *size);
char				**parse_args(int ac, char **av);
int					count_block(char **block);
void				free_split(char **block);
// solve
void				solve_push_swap(int *arr, int size);
int					is_sorted(t_stack *a);
void				sort_stack(t_stack *a, t_stack *b);
void				sort_three(t_stack *a);
void				sort_four(t_stack *a, t_stack *b);
void				sort_five(t_stack *a, t_stack *b);
// sort utils
int					find_min_idx_in_a(t_stack *a);
void				rotate_a_top_to_min(t_stack *a);
void				move_min_to_b(t_stack *a, t_stack *b);
void				insert_node_to_sorted_a(t_stack *a, t_stack *b);
// list
void				free_list(t_node *head);
void				free_stack(t_stack *stack);
int					list_size(t_node *dummy);
void				set_stack_data(t_stack *stack, t_node *dummy);
t_stack				*build_compressed_stack(int *arr, int size);
// create_list
t_node				*new_node(int value);
t_node				*create_dummy_node(void);
int					new_node_to_dlist(t_node *dummy, t_node **current,
						int value);
int					array_to_dlist(t_node *dummy, int *arr, int size);
t_node				*create_dlist_from_array(int *arr, int size);
// compress_list
int					binary_search(int *arr, int size, int target);
int					cmp_int(const void *a, const void *b);
void				compress_ranking(t_node *head);
// qsort
void				ft_swap(int *a, int *b);
void				ft_qsort(int *arr, int low, int high);
// lis
int					*find_lis(t_stack *a, int *lis_len);
// push b
void				push_not_lis_to_b(t_stack *a, t_stack *b, int *lis,
						int lis_len);
int					is_in_lis(int value, int *lis, int lis_len);
int					has_non_lis_element(t_stack *a, int *lis, int lis_len);

// cost
void				calculate_cost(t_stack *a, t_stack *b);
int					cmp_max(int a, int b);
void				rotate_and_push(t_stack *a, t_stack *b, t_node *target);
int					get_target_idx_in_a(t_stack *a, int value);
void				greedy_sort(t_stack *a, t_stack *b);

#endif
