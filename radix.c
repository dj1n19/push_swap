/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   radix.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgenie <bgenie@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/30 14:42:00 by bgenie            #+#    #+#             */
/*   Updated: 2022/07/01 15:00:04 by bgenie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	is_sort(t_stack *stack)
{
	t_stack	*next;

	while (stack->next)
	{
		next = stack->next;
		while (next)
		{
			if (stack->val > next->val)
				return (0);
			next = next->next;
		}
		stack = stack->next;
	}
	return (1);
}

t_stack	*radix(t_stack *stack_a)
{
	while (is_sort(stack_a) == 0)
	{
		//print_stack(stack_a, "begin loop");
		//ft_printf("cmp %d - %d\n", stack_a->val, stack_a->next->val);
		if ((stack_a->val % 10) > (stack_a->next->val % 10))
			stack_a = swap(stack_a);
		//stack_a = stack_a->next;
		stack_a = rotate(stack_a);
		print_stack(stack_a, "end loop");
	}
	return (stack_a);
}
