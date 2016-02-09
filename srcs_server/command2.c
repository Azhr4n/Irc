/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pivanovi <pivanovi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/01 17:31:47 by pivanovi          #+#    #+#             */
/*   Updated: 2015/12/01 17:31:47 by pivanovi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>

#include "bircd.h"
#include "tools.h"

static char	*mep(t_env *e, int cs, char *s, char *str)
{
	char	text[BUF_SIZE + 1];

	ft_bzero(text, BUF_SIZE + 1);
	ft_strcpy(text, e->fds[cs].nick);
	ft_strcat(text, str);
	ft_strcat(text, s);
	ft_strcat(text, ".");
	return (ft_strdup(text));
}

void		command_join(t_env *e, int cs)
{
	char	**tab;
	char	*text;
	int		i;

	tab = ft_split(e->fds[cs].command_buf);
	if (!is_in_list(e->fds[cs].room, tab[1]))
	{
		list_push_back(&e->fds[cs].room, ft_strdup(tab[1]));
		e->fds[cs].current_room = list_last_elem(e->fds[cs].room);
		printf("#%d joined the room : %s.\n", cs, tab[1]);
		text = mep(e, cs, tab[1], " has joined ");
		i = 0;
		while (i < e->maxfd)
		{
			if (e->fds[i].type == FD_CLIENT && (i != cs))
			{
				if (is_in_list(e->fds[i].room, tab[1]))
					ft_strcpy(e->fds[i].buf_write, text);
			}
			i++;
		}
		free(text);
	}
	free_tab_2d(tab);
}

static void	print_leave(t_env *e, int cs, char *text, char **tab)
{
	int		i;

	i = 0;
	while (i < e->maxfd)
	{
		if (e->fds[i].type == FD_CLIENT && (i != cs))
		{
			if (is_in_list(e->fds[i].room, tab[1]))
				ft_strcpy(e->fds[i].buf_write, text);
		}
		i++;
	}
}

void		command_leave(t_env *e, int cs)
{
	char	**tab;
	char	*text;
	int		size;
	int		i;

	tab = ft_split(e->fds[cs].command_buf);
	if (is_in_list(e->fds[cs].room, tab[1]))
	{
		text = mep(e, cs, tab[1], " has left ");
		size = size_of_list(e->fds[cs].room);
		list_remove(&e->fds[cs].room, tab[1]);
		printf("#%d left the room : %s.\n", cs, tab[1]);
		if (size == 1)
		{
			e->fds[cs].room = NULL;
			e->fds[cs].current_room = NULL;
		}
		else
			e->fds[cs].current_room = e->fds[cs].room;
		i = 0;
		print_leave(e, cs, text, tab);
		free(text);
	}
	free_tab_2d(tab);
}
