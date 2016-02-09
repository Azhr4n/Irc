/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strings.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pivanovi <pivanovi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/17 16:37:05 by pivanovi          #+#    #+#             */
/*   Updated: 2015/11/17 16:37:06 by pivanovi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

#include "tools.h"

int		ft_strlen(char *str)
{
	int		i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

int		ft_strcmp(char *s1, char *s2)
{
	while (*s1 == *s2 && *s1 && *s2)
	{
		s1++;
		s2++;
	}
	return (*s1 - *s2);
}

int		ft_strncmp(char *s1, char *s2, int size)
{
	int		i;

	i = 0;
	while (*s1 == *s2 && *s1 && *s2 && i < size - 1)
	{
		s1++;
		s2++;
		i++;
	}
	return (*s1 - *s2);
}

void	ft_print(char *str, int fd)
{
	write(fd, str, ft_strlen(str));
}

void	ft_bzero(char *str, int size)
{
	int		i;

	i = 0;
	while (i < size)
	{
		str[i] = 0;
		i++;
	}
}
