/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   radix.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgenie <bgenie@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/30 14:42:00 by bgenie            #+#    #+#             */
/*   Updated: 2022/07/26 16:00:47 by bgenie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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

t_stacks	*sort_tiny_stack(t_stacks *stacks)
{
	if (*stacks->stack_a > *(stacks->stack_a + 1)
		&& *stacks->stack_a < *(stacks->stack_a + 2))
		return (swap_a(stacks));
	if (*stacks->stack_a > *(stacks->stack_a + 1)
		&& *(stacks->stack_a + 1) > *(stacks->stack_a + 2))
	{
		stacks = swap_a(stacks);
		return (rev_rotate_a(stacks));
	}
	if (*stacks->stack_a > *(stacks->stack_a + 1)
		&& *(stacks->stack_a + 1) < *(stacks->stack_a + 2))
		return (rotate_a(stacks));
	if (*stacks->stack_a < *(stacks->stack_a + 1)
		&& *stacks->stack_a < *(stacks->stack_a + 2))
	{
		stacks = swap_a(stacks);
		return (rotate_a(stacks));
	}
	if (*stacks->stack_a < *(stacks->stack_a + 1)
		&& *stacks->stack_a > *(stacks->stack_a + 2))
		return (rev_rotate_a(stacks));
	return (stacks);
}

static t_stacks	*subsort_small_stack(t_stacks *stacks, int min, int max)
{
	int	i;

	i = 0;
	while (stacks->size_b != 2)
	{
		if (*stacks->stack_a == min || *stacks->stack_a == max)
			stacks = push_b(stacks);
		else
			stacks = rotate_a(stacks);
	}
	if (*stacks->stack_b > *(stacks->stack_b + 1))
		stacks = swap_b(stacks);
	if (!sort_check(stacks->stack_a, stacks->size_a))
		stacks = sort_tiny_stack(stacks);
	stacks = push_a(stacks);
	stacks = push_a(stacks);
	stacks = rotate_a(stacks);
	return (stacks);
}

t_stacks	*sort_small_stack(t_stacks *stacks)
{
	int	i;
	int	min;
	int	max;

	i = 0;
	min = INT_MAX;
	max = INT_MIN;
	while (i < stacks->size_a)
	{
		if (stacks->stack_a[i] > max)
			max = stacks->stack_a[i];
		if (stacks->stack_a[i] < min)
			min = stacks->stack_a[i];
		++i;
	}
	stacks = subsort_small_stack(stacks, min, max);
	return (stacks);
}

t_stacks	*sort(t_stacks *stacks)
{
	int	i;
	int	j;

	i = 0;
	if (sort_check(stacks->stack_a, stacks->size_a))
		return (stacks);
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
