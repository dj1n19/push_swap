/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgenie <bgenie@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/18 20:37:20 by bgenie            #+#    #+#             */
/*   Updated: 2022/07/18 20:43:17 by bgenie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include <stdlib.h>
# include <limits.h>
# include "libft/libft.h"

typedef struct s_stacks
{
	int	*stack_a;
	int	*stack_b;
	int	size_a;
	int	size_b;
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
void		ft_error(void);
void		print_stacks(t_stacks *stacks);

#endif
