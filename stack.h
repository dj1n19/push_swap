/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgenie <bgenie@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/27 17:17:16 by bgenie            #+#    #+#             */
/*   Updated: 2022/06/29 16:58:12 by bgenie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STACK_H
# define STACK_H
# include <stdlib.h>
# include "libft/libft.h"

typedef struct s_stack
{
	int				val;
	struct s_stack	*next;
}	t_stack;

t_stack	*new_stack(int val);
t_stack	*push_stack(t_stack *stack, int val);
int		pop_stack(t_stack *stack);
void	destroy_stack(t_stack *stack);
void	print_stack(t_stack *stack, char *name);

#endif
