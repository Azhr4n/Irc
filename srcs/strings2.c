/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strings2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pivanovi <pivanovi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/17 17:36:21 by pivanovi          #+#    #+#             */
/*   Updated: 2015/11/17 17:36:22 by pivanovi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

#include "tools.h"

char		*ft_strcpy(char *dest, char *src)
{
	char	*tmp;

	tmp = dest;
	while (*src)
	{
		*dest = *src;
		dest++;
		src++;
	}
	*dest = 0;
	return (tmp);
}

static int	words_number(char *str)
{
	int		i;
	int		flag;

	i = 0;
	flag = 0;
	while (*str)
	{
		if (!flag && *str != ' ' && *str != '\t')
		{
			flag = 1;
			i++;
		}
		str++;
		if (*str == ' ' || *str == '\t')
			flag = 0;
	}
	return (i);
}

static int	word_length(char *str)
{
	int		i;

	i = 0;
	while (str[i] && str[i] != ' ' && str[i] != '\t')
		i++;
	return (i);
}

char		**ft_split(char *str)
{
	char	**tab;
	int		i;
	int		j;

	while (*str == ' ' || *str == '\t')
		str++;
	tab = (char **)malloc(sizeof(char *) * (words_number(str) + 1));
	i = 0;
	while (*str)
	{
		tab[i] = (char *)malloc(sizeof(char) * (word_length(str) + 1));
		j = 0;
		while (*str && *str != ' ' && *str != '\t')
		{
			tab[i][j] = *str;
			str++;
			j++;
		}
		tab[i][j] = 0;
		while (*str && (*str == ' ' || *str == '\t'))
			str++;
		i++;
	}
	tab[i] = 0;
	return (tab);
}

int			ft_table_len(char **tab)
{
	int		i;

	i = 0;
	while (tab[i])
		i++;
	return (i);
}
