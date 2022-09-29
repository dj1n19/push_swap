/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgenie <bgenie@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/20 17:03:43 by bgenie            #+#    #+#             */
/*   Updated: 2022/09/30 00:00:40 by bgenie           ###   ########.fr       */
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

int	check_double(long *stack, int size)
{
	int	i;
	int	j;

	i = 0;
	while (i < size - 1)
	{
		j = i + 1;
		while (j < size)
		{
			if (stack[i] == stack[j])
				return (0);
			++j;
		}
		++i;
	}
	return (1);
}

t_stacks	*parse_args(char **args, int argc, t_stacks *stacks)
{
	int	i;
	int	n;

	stacks = (t_stacks *) malloc(sizeof(t_stacks));
	if (!stacks)
		return (NULL);
	stacks->stack_a = (long *) malloc(sizeof(long) * argc);
	stacks->stack_b = (long *) malloc(sizeof(long) * argc);
	if (!stacks->stack_a || !stacks->stack_b)
		return (NULL);
	ft_bzero(stacks->stack_a, sizeof(long) * argc);
	i = 0;
	n = 0;
	stacks->size_a = 0;
	stacks->size_b = 0;
	while (*args)
	{
		if (!check_nbr(*args) || !ft_atoi(*args++, &n))
			return (NULL);
		stacks->stack_a[i++] |= n;
		if (n < 0)
			stacks->stack_a[i - 1] ^= 0xffffffff00000000;
		++stacks->size_a;
	}
	return (stacks);
}

int	sort_check(long *stack, int size)
{
	if (size <= 0)
		return (0);
	while (--size)
	{
		if ((int)*stack > (int)*(stack + 1))
			return (0);
		stack++;
	}
	return (1);
}
