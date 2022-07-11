/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgenie <bgenie@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/27 17:14:23 by bgenie            #+#    #+#             */
/*   Updated: 2022/06/30 15:21:08 by bgenie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include "stack.h"
# include "libft/libft.h"

void	ft_error(void);
t_stack	*swap(t_stack *stack);
t_stack	*radix(t_stack *stack_a);
t_stack	*rotate(t_stack *stack);

#endif
