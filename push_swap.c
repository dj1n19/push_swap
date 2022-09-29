/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgenie <bgenie@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/27 17:14:13 by bgenie            #+#    #+#             */
/*   Updated: 2022/09/29 23:58:54 by bgenie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	ft_free(t_stacks *stacks)
{
	if (stacks)
	{
		if (stacks->stack_a)
			free(stacks->stack_a);
		if (stacks->stack_a)
			free(stacks->stack_b);
		free(stacks);
	}
}

void	ft_error(t_stacks *stacks)
{
	ft_printf("\e[31m");
	write(2, "ERROR\n", 6);
	ft_printf("\e[0m");
	ft_free(stacks);
	exit(EXIT_FAILURE);
}

void	print_stacks(t_stacks *stacks)
{
	int	i;

	i = 0;
	if (!stacks || !stacks->stack_a || !stacks->stack_b)
		return ;
	ft_printf("a\tb\n");
	ft_printf("-\t-\n");
	while (i < stacks->size_a || i < stacks->size_b)
	{
		if (i < stacks->size_a)
			ft_printf("%d\t", (int)(stacks->stack_a[i]));
		else
			ft_printf(" \t");
		if (i < stacks->size_b)
			ft_printf("%d\n", (int)(stacks->stack_b[i]));
		else
			ft_printf("\n");
		++i;
	}
	ft_printf("~\t~\n");
}

int	main(int argc, char **argv)
{
	t_stacks	*stacks;

	stacks = NULL;
	if (argc < 2)
		return (0);
	if (argc == 2)
		stacks = parse_args(ft_split(argv[1], ' '), ft_strlen(argv[1]), stacks);
	else
		stacks = parse_args(++argv, argc - 1, stacks);
	if (!stacks)
		ft_error(stacks);
	if (!check_double(stacks->stack_a, stacks->size_a))
		ft_error(stacks);
	if (stacks->size_a == 2 && !sort_check(stacks->stack_a, stacks->size_a))
		stacks = swap_a(stacks);
	if (stacks->size_a == 2)
		return (0);
	if (stacks->size_a == 3)
		stacks = sort_tiny_stack(stacks);
	else if (stacks->size_a > 5)
		stacks = sort(stacks);
	else
		stacks = sort_small_stack(stacks);
	ft_free(stacks);
	return (0);
}
