/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgenie <bgenie@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/27 17:14:13 by bgenie            #+#    #+#             */
/*   Updated: 2022/07/18 20:33:16 by bgenie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	check_nbr(char *nbr)
{
	if (!nbr)
		return (0);
	if (*nbr == '-')
		++nbr;
	if (!*nbr)
		return (0);
	while (*nbr)
	{
		if (!ft_isdigit(*nbr))
			return (0);
		++nbr;
	}
	return (1);
}

static t_stacks	*parse_args(char **args, int argc, t_stacks *stacks)
{
	int	i;

	stacks = (t_stacks *) malloc(sizeof(t_stacks));
	if (!stacks)
		return (NULL);
	stacks->stack_a = (int *) malloc(sizeof(int) * argc);
	stacks->stack_b = (int *) malloc(sizeof(int) * argc);
	if (!stacks->stack_a || !stacks->stack_b)
	{
		if (stacks->stack_a)
			free(stacks->stack_a);
		return (NULL);
	}
	i = 0;
	stacks->size_a = 0;
	stacks->size_b = 0;
	while (*args)
	{
		if (!check_nbr(*args))
			return (NULL);
		stacks->stack_a[i] = ft_atoi(*args++);
		++stacks->size_a;
		++i;
	}
	return (stacks);
}

void	ft_error(void)
{
	ft_printf("\e[31m");
	write(2, "ERROR\n", 6);
	ft_printf("\e[0m");
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
			ft_printf("%d\t", stacks->stack_a[i]);
		else
			ft_printf(" \t");
		if (i < stacks->size_b)
			ft_printf("%d\n", stacks->stack_b[i]);
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
		ft_error();
	stacks = parse_args(++argv, argc - 1, stacks);
	if (!stacks)
		ft_error();
	stacks = sort(stacks);
	return (0);
}
