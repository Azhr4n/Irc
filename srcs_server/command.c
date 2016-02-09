/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pivanovi <pivanovi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/23 16:43:04 by pivanovi          #+#    #+#             */
/*   Updated: 2015/11/23 16:43:04 by pivanovi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

#include "bircd.h"
#include "tools.h"

void	get_user_nick_norme(t_env *e, int cs, char **tab)
{
	ft_strcpy(e->fds[cs].nick, tab[1]);
	ft_strcpy(e->fds[cs].buf_write, "/nick valid");
	free_tab_2d(tab);
}

void	get_user_nick(t_env *e, int cs)
{
	int		i;
	char	**tab;

	tab = ft_split(e->fds[cs].command_buf);
	if (ft_table_len(tab) > 2)
	{
		ft_strcpy(e->fds[cs].buf_write, "Command invalid");
		return ;
	}
	i = 0;
	while (i < e->maxfd)
	{
		if ((e->fds[i].type == FD_CLIENT) && (i != cs))
		{
			if (!ft_strcmp(e->fds[i].nick, tab[1]))
			{
				ft_strcpy(e->fds[cs].buf_write, "/nick taken");
				free_tab_2d(tab);
				return ;
			}
		}
		i++;
	}
	get_user_nick_norme(e, cs, tab);
}

void	command_who(t_env *e, int cs)
{
	char	**tab;
	int		i;

	tab = ft_split(e->fds[cs].command_buf);
	ft_bzero(e->fds[cs].buf_write, BUF_SIZE);
	ft_strcat(e->fds[cs].buf_write, "Users : ");
	i = 0;
	while (i < e->maxfd)
	{
		if (e->fds[i].type == FD_CLIENT && (i != cs))
		{
			if (is_in_list(e->fds[i].room, e->fds[cs].current_room->data))
			{
				if (ft_strlen(e->fds[cs].buf_write)
					+ ft_strlen(e->fds[i].nick) + 2 < BUF_SIZE)
				{
					if (ft_strcmp(e->fds[cs].buf_write, "Users : "))
						ft_strcat(e->fds[cs].buf_write, ", ");
					ft_strcat(e->fds[cs].buf_write, e->fds[i].nick);
				}
			}
		}
		i++;
	}
	free_tab_2d(tab);
}

void	command_chan(t_env *e, int cs)
{
	char	**tab;
	t_list	*tmp;

	tab = ft_split(e->fds[cs].command_buf);
	tmp = e->fds[cs].room;
	while (tmp)
	{
		if (!ft_strcmp(tmp->data, tab[1]))
		{
			e->fds[cs].current_room = tmp;
			return ;
		}
		tmp = tmp->next;
	}
}
