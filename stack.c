/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgenie <bgenie@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/27 17:19:10 by bgenie            #+#    #+#             */
/*   Updated: 2022/06/29 16:58:05 by bgenie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stack.h"

t_stack	*new_stack(int val)
{
	t_stack	*stack;

	stack = (t_stack *) malloc(sizeof(t_stack));
	if (!stack)
		return (NULL);
	stack->val = val;
	stack->next = NULL;
	return (stack);
}

t_stack	*push_stack(t_stack *stack, int val)
{
	t_stack	*node;

	node = new_stack(val);
	if (!node)
		exit(EXIT_FAILURE); // TODO ERROR
	node->val = val;
	node->next = stack;
	return (node);
}

int	pop_stack(t_stack *stack)
{
	int		val;
	t_stack	*tmp;

	if (!stack)
		exit(EXIT_FAILURE); // TODO ERROR
	val = stack->val;
	tmp = stack;
	stack = stack->next;
	free(tmp);
	return (val);
}

void	destroy_stack(t_stack *stack)
{
	t_stack	*tmp;

	if (stack)
	{
		while (stack)
		{
			tmp = stack;
			stack = stack->next;
			free(stack);
		}
	}
}

void	print_stack(t_stack *stack, char *name)
{
	if (name)
		ft_printf("%s\n--\n", name);
	while (stack)
	{
		ft_printf("%d\n", stack->val);
		stack = stack->next;
	}
}
