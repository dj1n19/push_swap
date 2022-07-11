/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_push.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgenie <bgenie@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/28 14:37:04 by bgenie            #+#    #+#             */
/*   Updated: 2022/07/01 14:56:44 by bgenie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*swap(t_stack *stack)
{
	t_stack	*first;
	t_stack *second;
	t_stack *head;
	t_stack *head_next;
	t_stack *sec;
	t_stack *sec_next;

	if (!stack || !stack->next)
		return (stack);
	head = stack;
	head_next = stack->next;
	sec = stack->next;
	sec_next = stack->next->next;
	first = sec;
	second = head;
	first->next = second;
	second->next = sec_next;
	//print_stack(first, "swap");
	return (first);
}

t_stack	*rotate(t_stack *stack)
{
	t_stack	*tmp;
	t_stack *head;

	if (!stack || !stack->next)
		return (stack);
	tmp = stack;
	head = stack->next;
	while (stack->next)
		stack = stack->next;
	stack->next = tmp;
	tmp->next = NULL;
	//print_stack(head, "rotate");
	return (head);
}
