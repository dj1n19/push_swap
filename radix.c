/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   radix.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgenie <bgenie@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/30 14:42:00 by bgenie            #+#    #+#             */
/*   Updated: 2022/09/30 00:03:47 by bgenie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static t_stacks	*subsort(t_stacks *stacks, int shift)
{
	int	i;

	i = stacks->size_a;
	while (i--)
	{
		if ((((int)(*stacks->stack_a >> shift)) & 1) == 0)
		{
			stacks = push_b(stacks);
		}
		else
			stacks = rotate_a(stacks);
	}
	return (stacks);
}

t_stacks	*presort(t_stacks *stacks)
{
	int	i;
	int	j;
	int	min_i;
	int	min;

	min_i = 0;
	i = 1;
	while (i < stacks->size_a + 1)
	{
		min = INT_MAX;
		j = 0;
		while (j < stacks->size_a)
		{
			if ((int)stacks->stack_a[j] < min
				&& (int)(stacks->stack_a[j] >> 32) == 0)
			{
				min = (int)stacks->stack_a[j];
				min_i = j;
			}
			++j;
		}
		stacks->stack_a[min_i] |= (long)i << 32;
		++i;
	}
	return (stacks);
}

t_stacks	*sort(t_stacks *stacks)
{
	int	i;
	int	j;

	i = 0;
	if (sort_check(stacks->stack_a, stacks->size_a))
		return (stacks);
	stacks = presort(stacks);
	while (!sort_check(stacks->stack_a, stacks->size_a))
	{
		stacks = subsort(stacks, i + 32);
		j = stacks->size_b;
		while (j--)
			stacks = push_a(stacks);
		++i;
	}
	return (stacks);
}
