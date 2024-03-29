/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgenie <bgenie@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/18 20:37:20 by bgenie            #+#    #+#             */
/*   Updated: 2022/09/28 17:04:08 by bgenie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include <stdlib.h>
# include <limits.h>
# include "libft/libft.h"

typedef struct s_stacks
{
	long	*stack_a;
	long	*stack_b;
	int		size_a;
	int		size_b;
}	t_stacks;

t_stacks	*rotate_a(t_stacks *stacks);
t_stacks	*rotate_b(t_stacks *stacks);
t_stacks	*rev_rotate_a(t_stacks *stacks);
t_stacks	*rev_rotate_b(t_stacks *stacks);
t_stacks	*swap_a(t_stacks *stacks);
t_stacks	*swap_b(t_stacks *stacks);
t_stacks	*push_a(t_stacks *stacks);
t_stacks	*push_b(t_stacks *stacks);
t_stacks	*sort(t_stacks *stacks);
t_stacks	*sort_small_stack(t_stacks *stacks);
t_stacks	*sort_tiny_stack(t_stacks *stacks);
t_stacks	*parse_args(char **args, int argc, t_stacks *stacks);
void		ft_error(t_stacks *stacks);
void		print_stacks(t_stacks *stacks);
int			check_double(long *stack, int size);
int			sort_check(long *stack, int size);

#endif
