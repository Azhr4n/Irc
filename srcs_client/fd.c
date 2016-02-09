/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pivanovi <pivanovi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/01 17:01:03 by pivanovi          #+#    #+#             */
/*   Updated: 2015/12/01 17:01:05 by pivanovi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "defines_and_cie.h"
#include "tools.h"
#include "client.h"

void		init_fd(t_client *client)
{
	FD_ZERO(&client->fd_read);
	FD_ZERO(&client->fd_write);
	FD_SET(0, &client->fd_read);
	FD_SET(client->sock, &client->fd_read);
	if (ft_strlen(client->buff_write) > 0)
		FD_SET(client->sock, &client->fd_write);
}

static void	stdout_read(t_client *client, int ret)
{
	if (client->r > 0 && FD_ISSET(0, &client->fd_read) && client->valid_nick)
	{
		ret = read(0, client->buff, BUFFSIZE);
		client->buff[ret] = 0;
		client->r--;
		command_panel(client);
		bzero(client->buff, BUFFSIZE + 1);
		if (!client->ping)
			ft_print(client->prompt, 1);
	}
}

static void	socket_read(t_client *client, int ret)
{
	if (client->r > 0 && FD_ISSET(client->sock, &client->fd_read))
	{
		ret = read(client->sock, client->buff_read, BUFFSIZE);
		client->buff_read[ret] = 0;
		client->r--;
		if (!ft_strcmp(client->buff_read, "/nick valid"))
		{
			client->ping = 0;
			client->valid_nick = 1;
			ft_bzero(client->nick, 10);
			ft_strcpy(client->nick, client->tmp_nick);
			set_prompt(client);
		}
		else if (!ft_strcmp(client->buff_read, "/nick taken"))
		{
			printf("This nickname is already taken.\n");
			client->ping = 0;
		}
		else
			printf("%s\n", client->buff_read);
		ft_bzero(client->buff_read, BUFFSIZE + 1);
		if (client->valid_nick)
			ft_print(client->prompt, 1);
	}
}

void		check_fd(t_client *client)
{
	int		ret;

	ret = 0;
	stdout_read(client, ret);
	socket_read(client, ret);
	if (client->r > 0 && FD_ISSET(client->sock, &client->fd_write))
	{
		write(client->sock, client->buff_write, ft_strlen(client->buff_write));
		ft_bzero(client->buff_write, BUFFSIZE + 1);
		client->r--;
	}
	if (!client->valid_nick && !client->ping)
		choose_nick(client);
}
