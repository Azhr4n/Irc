/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pivanovi <pivanovi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/19 18:00:04 by pivanovi          #+#    #+#             */
/*   Updated: 2015/11/19 18:00:05 by pivanovi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>

#include "tools.h"

t_list		*create_elem(char *data)
{
	t_list	*elem;

	elem = (t_list*)malloc(sizeof(t_list));
	elem->next = NULL;
	elem->data = data;
	return (elem);
}

void		free_elem(t_list *elem)
{
	free(elem->data);
	free(elem);
}

void		list_push_back(t_list **list, char *data)
{
	t_list		*start;

	if ((*list))
	{
		start = (*list);
		while ((*list)->next)
			(*list) = (*list)->next;
		(*list)->next = create_elem(data);
		(*list) = start;
	}
	else
		*list = create_elem(data);
}

void		list_remove(t_list **list, char *data)
{
	t_list	*start;
	t_list	*previous;

	start = *list;
	if (!ft_strcmp(start->data, data))
	{
		free_elem(start);
		*list = (*list)->next;
	}
	else
	{
		while ((*list))
		{
			if (!ft_strcmp((*list)->data, data))
			{
				previous->next = (*list)->next;
				free_elem(*list);
				*list = start;
				return ;
			}
			previous = *list;
			*list = (*list)->next;
		}
	}
}
