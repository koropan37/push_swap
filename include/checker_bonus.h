/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_bonus.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skimura <skimura@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/29 15:56:57 by skimura           #+#    #+#             */
/*   Updated: 2025/06/30 18:02:37 by skimura          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_BONUS_H
# define CHECKER_BONUS_H

# include "include/push_swap.h"

void	checker_sa(t_stack *a);
void	checker_sb(t_stack *b);
void	checker_ss(t_stack *a, t_stack *b);
void	checker_pa(t_stack *a, t_stack *b);
void	checker_pb(t_stack *a, t_stack *b);
void	checker_ra(t_stack *a);
void	checker_rb(t_stack *b);
void	checker_rr(t_stack *a, t_stack *b);
void	checker_rra(t_stack *a);
void	checker_rrb(t_stack *b);
void	checker_rrr(t_stack *a, t_stack *b);

void	init_checker_stacks(int argc, char **argv, t_stack **a, t_stack **b);
int		read_and_execute(t_stack *a, t_stack *b);
#endif
