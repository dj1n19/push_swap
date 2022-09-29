/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgenie <bgenie@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/04 14:44:30 by bgenie            #+#    #+#             */
/*   Updated: 2022/09/26 21:15:12 by bgenie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_isspace(char c)
{
	if (c == ' ')
		return (1);
	if (c == '\f' || c == '\n' || c == '\r' || c == '\t' || c == '\v')
		return (1);
	return (0);
}

static const char	*ft_getsign(const char *s, int *is_neg)
{
	if (*s == '+' || *s == '-')
	{
		if (*s == '-')
			*is_neg = 1;
		s++;
	}
	return (s);
}

int	ft_atoi(const char *str, int *res)
{
	long long	nbr;
	int			is_neg;

	nbr = 0;
	is_neg = 0;
	if (!*str)
		return (0);
	while (ft_isspace(*str))
		str++;
	str = ft_getsign(str, &is_neg);
	while (*str && *str >= 48 && *str <= 57)
	{
		nbr += *str++ - 48;
		if (*str >= 48 && *str <= 57)
			nbr *= 10;
	}
	if ((is_neg == 1 && -(nbr) < INT_MIN) || (is_neg == 0 && nbr > INT_MAX))
		return (0);
	if (is_neg == 1)
		*res = (-nbr);
	else
		*res = nbr;
	return (1);
}
