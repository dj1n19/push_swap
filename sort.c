/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgenie <bgenie@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/30 00:02:23 by bgenie            #+#    #+#             */
/*   Updated: 2022/09/30 00:04:11 by bgenie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stacks	*sort_tiny_stack(t_stacks *stacks)
{
	if (sort_check(stacks->stack_a, stacks->size_a))
		return (stacks);
	if ((int)*stacks->stack_a > (int)*(stacks->stack_a + 1)
		&& (int)*stacks->stack_a < (int)*(stacks->stack_a + 2))
		return (swap_a(stacks));
	if ((int)*stacks->stack_a > (int)*(stacks->stack_a + 1)
		&& (int)*(stacks->stack_a + 1) > (int)*(stacks->stack_a + 2))
	{
		stacks = swap_a(stacks);
		return (rev_rotate_a(stacks));
	}
	if ((int)*stacks->stack_a > (int)*(stacks->stack_a + 1)
		&& (int)*(stacks->stack_a + 1) < (int)*(stacks->stack_a + 2))
		return (rotate_a(stacks));
	if ((int)*stacks->stack_a < (int)*(stacks->stack_a + 1)
		&& (int)*stacks->stack_a < (int)*(stacks->stack_a + 2))
	{
		stacks = swap_a(stacks);
		return (rotate_a(stacks));
	}
	if ((int)*stacks->stack_a < (int)*(stacks->stack_a + 1)
		&& (int)*stacks->stack_a > (int)*(stacks->stack_a + 2))
		return (rev_rotate_a(stacks));
	return (stacks);
}

static t_stacks	*subsort_small_stack(t_stacks *stacks, int min, int max)
{
	int	i;

	i = 0;
	while (stacks->size_a > 3)
	{
		if ((int)(*stacks->stack_a) == min || (int)(*stacks->stack_a) == max)
			stacks = push_b(stacks);
		else
			stacks = rotate_a(stacks);
	}
	if ((int)*stacks->stack_b > (int)*(stacks->stack_b + 1))
		stacks = swap_b(stacks);
	if (!sort_check(stacks->stack_a, stacks->size_a))
		stacks = sort_tiny_stack(stacks);
	stacks = push_a(stacks);
	if ((int)*stacks->stack_a > (int)*(stacks->stack_a + 1)
		|| (int)*stacks->stack_b > (int)*stacks->stack_a)
	{
		stacks = push_a(stacks);
		stacks = rotate_a(stacks);
	}
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
	if (sort_check(stacks->stack_a, stacks->size_a))
		return (stacks);
	while (i < stacks->size_a)
	{
		if ((int)(stacks->stack_a[i]) > max)
			max = (int)stacks->stack_a[i];
		if ((int)(stacks->stack_a[i]) < min)
			min = (int)stacks->stack_a[i];
		++i;
	}
	stacks = subsort_small_stack(stacks, min, max);
	return (stacks);
}
