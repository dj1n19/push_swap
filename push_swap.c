/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgenie <bgenie@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/27 17:14:13 by bgenie            #+#    #+#             */
/*   Updated: 2022/06/30 18:00:55 by bgenie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	check_nbr(char *nbr)
{
	if (!nbr)
		return (0);
	if (*nbr == '-')
		++nbr;
	if (!*nbr)
		return (0);
	while (*nbr)
	{
		if (!ft_isdigit(*nbr))
			return (0);
		++nbr;
	}
	return (1);
}

static t_stack	*parse_args(char **args)
{
	t_stack	*stack_a;
	int		i;

	stack_a = NULL;
	i = 0;
	while (*args)
	{
		if (!check_nbr(*args))
			return (NULL);
		stack_a = push_stack(stack_a, ft_atoi(*args));
		++args;
	}
	return (stack_a);
}

void	ft_error(void)
{
	ft_printf("\e[31m");
	write(2, "ERROR\n", 6);
	ft_printf("\e[0m");
	exit(EXIT_FAILURE);
}

int	main(int argc, char **argv)
{
	t_stack	*stack_a;

	if (argc < 2)
		ft_error();
	stack_a = parse_args(++argv);
	if (!stack_a)
		ft_error();
	stack_a = radix(stack_a);
	//ft_printf(">%d\n", stack_a->next->val);
	print_stack(stack_a, "a");
	return (0);
}
