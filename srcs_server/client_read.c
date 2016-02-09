/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client_read.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pivanovi <pivanovi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/01 17:18:43 by pivanovi          #+#    #+#             */
/*   Updated: 2015/12/01 17:18:44 by pivanovi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>
#include <sys/socket.h>

#include "bircd.h"
#include "tools.h"

void		send_to_chan(t_env *e, int cs)
{
	int		i;
	char	msg[BUF_SIZE + 1];

	if (e->fds[cs].current_room)
	{
		ft_bzero(msg, BUF_SIZE + 1);
		ft_strcpy(msg, "[");
		ft_strcat(msg, e->fds[cs].current_room->data);
		ft_strcat(msg, "] ");
		ft_strcat(msg, e->fds[cs].nick);
		ft_strcat(msg, " : ");
		ft_strcat(msg, e->fds[cs].command_buf);
		i = 0;
		while (i < e->maxfd)
		{
			if (e->fds[i].type == FD_CLIENT && (i != cs))
			{
				if (is_in_list(e->fds[i].room, e->fds[cs].current_room->data))
					ft_strcpy(e->fds[i].buf_write, msg);
			}
			i++;
		}
	}
}

void		whisper_fill(t_env *e, int cs, int i)
{
	ft_bzero(e->fds[i].buf_write, BUF_SIZE);
	ft_strcat(e->fds[i].buf_write, "From ");
	ft_strcat(e->fds[i].buf_write, e->fds[cs].nick);
	ft_strcat(e->fds[i].buf_write, " : ");
}

void		whisper(t_env *e, int cs)
{
	int		i;
	int		j;
	char	**tab;

	tab = ft_split(e->fds[cs].command_buf);
	i = 0;
	while (i < e->maxfd)
	{
		if (e->fds[i].type == FD_CLIENT && (i != cs))
		{
			if (!ft_strcmp(e->fds[i].nick, tab[1]))
			{
				whisper_fill(e, cs, i);
				j = 2;
				while (tab[j])
				{
					if (j > 2)
						ft_strcat(e->fds[i].buf_write, " ");
					ft_strcat(e->fds[i].buf_write, tab[j++]);
				}
			}
		}
		i++;
	}
	free_tab_2d(tab);
}

static void	client_read2(t_env *e, int cs, int *i)
{
	if (e->fds[cs].command_buf[*i] == '\n')
	{
		e->fds[cs].command_buf[*i] = 0;
		if (ft_strlen(e->fds[cs].command_buf) > 0)
		{
			if (!ft_strncmp("/nick", e->fds[cs].command_buf, 5))
				get_user_nick(e, cs);
			else if (!ft_strncmp(e->fds[cs].command_buf, "/join", 5))
				command_join(e, cs);
			else if (!ft_strncmp(e->fds[cs].command_buf, "/leave", 6))
				command_leave(e, cs);
			else if (!ft_strncmp(e->fds[cs].command_buf, "/who", 4))
				command_who(e, cs);
			else if (!ft_strncmp(e->fds[cs].command_buf, "/chan", 5))
				command_chan(e, cs);
			else if (!ft_strncmp(e->fds[cs].command_buf, "/send", 5))
				whisper(e, cs);
			else
				send_to_chan(e, cs);
			ft_bzero(e->fds[cs].command_buf, BUF_SIZE + 1);
		}
	}
	(*i)++;
}

void		client_read(t_env *e, int cs)
{
	int		i;

	if ((recv(cs, e->fds[cs].buf_read, BUF_SIZE, 0) <= 0))
	{
		close(cs);
		clean_fd(&e->fds[cs]);
		printf("client #%d gone away\n", cs);
	}
	else
	{
		if (ft_strlen(e->fds[cs].command_buf)
			+ ft_strlen(e->fds[cs].buf_read) <= BUF_SIZE)
			ft_strcat(e->fds[cs].command_buf, e->fds[cs].buf_read);
		else
		{
			ft_bzero(e->fds[cs].command_buf, BUF_SIZE + 1);
			ft_strcat(e->fds[cs].command_buf, e->fds[cs].buf_read);
		}
		i = 0;
		while (e->fds[cs].command_buf[i])
			client_read2(e, cs, &i);
		ft_bzero(e->fds[cs].buf_read, BUF_SIZE);
	}
}
