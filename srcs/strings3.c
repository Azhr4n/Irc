/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strings3.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pivanovi <pivanovi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/19 16:21:39 by pivanovi          #+#    #+#             */
/*   Updated: 2015/11/19 16:21:39 by pivanovi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

#include "tools.h"

char		*ft_strncpy(char *dest, char *src, int n)
{
	int		i;

	i = 0;
	while (src[i] && i < n - 1)
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = 0;
	return (dest);
}

char		*ft_strcat(char *dest, char *src)
{
	int		i;

	i = ft_strlen(dest);
	while (*src)
	{
		dest[i] = *src;
		src++;
		i++;
	}
	dest[i] = 0;
	return (dest);
}

char		*ft_strdup(char *src)
{
	char	*ret;
	int		len;

	len = ft_strlen(src);
	ret = (char *)malloc(sizeof(char) * (len + 1));
	ret[len] = 0;
	len = 0;
	while (src[len])
	{
		ret[len] = src[len];
		len++;
	}
	return (ret);
}

void		ft_strcpynon(char *dest, char *src)
{
	int		i;

	i = 0;
	while (src[i] && src[i] != '\n')
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = 0;
}

void		free_tab_2d(char **tab)
{
	int		i;

	i = 0;
	while (tab[i])
	{
		free(tab[i]);
		i++;
	}
	free(tab);
}
