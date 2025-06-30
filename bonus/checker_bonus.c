/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skimura <skimura@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/30 19:14:39 by skimura           #+#    #+#             */
/*   Updated: 2025/06/30 19:14:40 by skimura          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/checker_bonus.h"

void			init_checker_stacks(int argc, char **argv, t_stack **a,
					t_stack **b);
static t_stack	*build_stack(int *arr, int size);
int				read_and_execute(t_stack *a, t_stack *b);
static int		exec_cmd(char *cmd, t_stack *a, t_stack *b);

int	main(int argc, char **argv)
{
	t_stack	*a;
	t_stack	*b;

	if (argc < 2)
		return (0);
	init_checker_stacks(argc, argv, &a, &b);
	if (!read_and_execute(a, b))
	{
		free_stack(a);
		free_stack(b);
		get_next_line(-1);
		ft_printerror();
	}
	if (is_sorted(a) && b->size == 0)
		ft_printf("OK\n");
	else
		ft_printf("KO\n");
	free_stack(a);
	free_stack(b);
	get_next_line(-1);
	return (0);
}

void	init_checker_stacks(int argc, char **argv, t_stack **a, t_stack **b)
{
	int	*values;
	int	size;

	values = ft_parse(argc, argv, &size);
	*a = build_stack(values, size);
	*b = build_stack(NULL, 0);
	free(values);
	if (!*a || !*b)
	{
		if (*a)
			free_stack(*a);
		if (*b)
			free_stack(*b);
		ft_printerror();
		exit(1);
	}
}

static t_stack	*build_stack(int *arr, int size)
{
	t_node	*dummy;
	t_stack	*stack;

	dummy = create_dlist_from_array(arr, size);
	if (!dummy)
		return (NULL);
	stack = malloc(sizeof(t_stack));
	if (!stack)
	{
		free_list(dummy);
		return (NULL);
	}
	set_stack_data(stack, dummy);
	return (stack);
}

int	read_and_execute(t_stack *a, t_stack *b)
{
	char	*line;
	size_t	len;

	line = get_next_line(0);
	while (line)
	{
		len = ft_strlen(line);
		if (len > 0 && line[len - 1] == '\n')
			line[len - 1] = '\0';
		if (!exec_cmd(line, a, b))
		{
			free(line);
			return (0);
		}
		free(line);
		line = get_next_line(0);
	}
	return (1);
}

int	exec_cmd(char *cmd, t_stack *a, t_stack *b)
{
	if (ft_strcmp(cmd, "sa") == 0)
		checker_sa(a);
	else if (ft_strcmp(cmd, "sb") == 0)
		checker_sb(b);
	else if (ft_strcmp(cmd, "ss") == 0)
		checker_ss(a, b);
	else if (ft_strcmp(cmd, "pa") == 0)
		checker_pa(a, b);
	else if (ft_strcmp(cmd, "pb") == 0)
		checker_pb(a, b);
	else if (ft_strcmp(cmd, "ra") == 0)
		checker_ra(a);
	else if (ft_strcmp(cmd, "rb") == 0)
		checker_rb(b);
	else if (ft_strcmp(cmd, "rr") == 0)
		checker_rr(a, b);
	else if (ft_strcmp(cmd, "rra") == 0)
		checker_rra(a);
	else if (ft_strcmp(cmd, "rrb") == 0)
		checker_rrb(b);
	else if (ft_strcmp(cmd, "rrr") == 0)
		checker_rrr(a, b);
	else
		return (0);
	return (1);
}
