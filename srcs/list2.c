/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pivanovi <pivanovi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/01 17:12:49 by pivanovi          #+#    #+#             */
/*   Updated: 2015/12/01 17:12:51 by pivanovi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

#include "tools.h"

int			is_in_list(t_list *list, char *data)
{
	if (list == NULL)
		return (0);
	while (list)
	{
		if (list->data && data)
		{
			if (!ft_strcmp(data, list->data))
				return (1);
		}
		list = list->next;
	}
	return (0);
}

t_list		*list_last_elem(t_list *list)
{
	while (list->next)
		list = list->next;
	return (list);
}

int			size_of_list(t_list *list)
{
	int		i;

	i = 0;
	while (list)
	{
		i++;
		list = list->next;
	}
	return (i);
}
