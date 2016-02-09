/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pivanovi <pivanovi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/17 16:21:53 by pivanovi          #+#    #+#             */
/*   Updated: 2015/11/17 16:21:53 by pivanovi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tools.h"

int		ft_atoi(char *str)
{
	int	ret;
	int neg;

	neg = 0;
	while (*str && (*str == ' ' || *str == '\t'))
		str++;
	if (*str == '+')
		str++;
	else if (*str == '-')
	{
		neg = 1;
		str++;
	}
	ret = 0;
	while (*str && *str <= '9' && *str >= '0')
	{
		ret *= 10;
		ret += *str - '0';
		str++;
	}
	if (neg)
		return (-ret);
	return (ret);
}
