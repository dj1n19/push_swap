/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgenie <bgenie@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/28 14:37:04 by bgenie            #+#    #+#             */
/*   Updated: 2022/07/18 20:16:42 by bgenie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stacks	*rotate_a(t_stacks *stacks)
{
	int	tmp;
	int	i;
	int	*save;

	i = stacks->size_a;
	if (!stacks || stacks->size_a < 2)
		return (stacks);
	save = stacks->stack_a;
	tmp = *stacks->stack_a;
	while (--i)
	{
		*stacks->stack_a = *(stacks->stack_a + 1);
		++stacks->stack_a;
	}
	*stacks->stack_a = tmp;
	stacks->stack_a = save;
	ft_printf("ra\n");
	return (stacks);
}

t_stacks	*rotate_b(t_stacks *stacks)
{
	int	tmp;
	int	i;
	int	*save;

	i = stacks->size_b;
	if (!stacks || stacks->size_b < 2)
		return (stacks);
	save = stacks->stack_b;
	tmp = *stacks->stack_b;
	while (--i)
	{
		*stacks->stack_b = *(stacks->stack_b + 1);
		++stacks->stack_b;
	}
	*stacks->stack_b = tmp;
	stacks->stack_b = save;
	ft_printf("rb\n");
	return (stacks);
}

t_stacks	*rev_rotate_a(t_stacks *stacks)
{
	int	tmp;
	int	*save;
	int	i;

	i = stacks->size_a;
	if (!stacks || stacks->size_a < 2)
		return (stacks);
	save = stacks->stack_a;
	stacks->stack_a += stacks->size_a - 1;
	tmp = *stacks->stack_a;
	while (--i)
	{
		*stacks->stack_a = *(stacks->stack_a - 1);
		--stacks->stack_a;
	}
	*save = tmp;
	stacks->stack_a = save;
	ft_printf("rra\n");
	return (stacks);
}

t_stacks	*rev_rotate_b(t_stacks *stacks)
{
	int	tmp;
	int	*save;
	int	i;

	i = stacks->size_b;
	if (!stacks || stacks->size_b < 2)
		return (stacks);
	save = stacks->stack_b;
	stacks->stack_b += stacks->size_b - 1;
	tmp = *stacks->stack_b;
	while (--i)
	{
		*stacks->stack_b = *(stacks->stack_b - 1);
		--stacks->stack_b;
	}
	*save = tmp;
	stacks->stack_b = save;
	ft_printf("rrb\n");
	return (stacks);
}
