/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   radix.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgenie <bgenie@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/30 14:42:00 by bgenie            #+#    #+#             */
/*   Updated: 2022/07/18 20:30:45 by bgenie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	sort_check(int *stack, int size)
{
	while (--size)
	{
		if ((unsigned int) *stack > (unsigned int) *(stack + 1))
			return (0);
		stack++;
	}
	return (1);
}

static t_stacks	*subsort(t_stacks *stacks, int shift)
{
	int	i;

	i = stacks->size_a;
	while (i--)
	{
		if ((((unsigned int) *stacks->stack_a >> shift) & 1) == 0)
		{
			stacks = push_b(stacks);
		}
		else
			stacks = rotate_a(stacks);
	}
	return (stacks);
}

t_stacks	*sort(t_stacks *stacks)
{
	int	i;
	int	j;

	i = 0;
	while (!sort_check(stacks->stack_a, stacks->size_a))
	{
		stacks = subsort(stacks, i);
		j = stacks->size_b;
		while (j--)
			stacks = push_a(stacks);
		++i;
	}
	stacks = rev_rotate_a(stacks);
	if (*stacks->stack_a < 0)
	{
		stacks = rotate_a(stacks);
		while (*stacks->stack_a >= 0)
			stacks = rotate_a(stacks);
	}
	else
		stacks = rotate_a(stacks);
	return (stacks);
}
