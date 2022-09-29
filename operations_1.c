/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_1.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgenie <bgenie@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/18 20:15:16 by bgenie            #+#    #+#             */
/*   Updated: 2022/09/28 16:15:47 by bgenie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stacks	*swap_a(t_stacks *stacks)
{
	long	tmp;

	if (!stacks || stacks->size_a < 2)
		return (stacks);
	tmp = stacks->stack_a[0];
	stacks->stack_a[0] = stacks->stack_a[1];
	stacks->stack_a[1] = tmp;
	ft_printf("sa\n");
	return (stacks);
}

t_stacks	*swap_b(t_stacks *stacks)
{
	long	tmp;

	if (!stacks || stacks->size_b < 2)
		return (stacks);
	tmp = stacks->stack_b[0];
	stacks->stack_b[0] = stacks->stack_b[1];
	stacks->stack_b[1] = tmp;
	ft_printf("sb\n");
	return (stacks);
}

t_stacks	*push_a(t_stacks *stacks)
{
	int	i;

	if (stacks->size_b < 1)
		return (stacks);
	i = stacks->size_a;
	while (i > 0)
	{
		stacks->stack_a[i] = stacks->stack_a[i - 1];
		--i;
	}
	stacks->stack_a[0] = stacks->stack_b[0];
	++stacks->size_a;
	i = 0;
	--stacks->size_b;
	while (i < stacks->size_b)
	{
		stacks->stack_b[i] = stacks->stack_b[i + 1];
		++i;
	}
	ft_printf("pa\n");
	return (stacks);
}

t_stacks	*push_b(t_stacks *stacks)
{
	int	i;

	if (stacks->size_a < 1)
		return (stacks);
	i = stacks->size_b;
	while (i > 0)
	{
		stacks->stack_b[i] = stacks->stack_b[i - 1];
		--i;
	}
	stacks->stack_b[0] = stacks->stack_a[0];
	++stacks->size_b;
	i = 0;
	--stacks->size_a;
	while (i < stacks->size_a)
	{
		stacks->stack_a[i] = stacks->stack_a[i + 1];
		++i;
	}
	ft_printf("pb\n");
	return (stacks);
}
