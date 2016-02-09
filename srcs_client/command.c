/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pivanovi <pivanovi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/01 16:51:05 by pivanovi          #+#    #+#             */
/*   Updated: 2015/12/01 16:51:05 by pivanovi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "defines_and_cie.h"
#include "client.h"
#include "tools.h"

void		command_connect(t_client *client)
{
	char	**opt;
	int		size;

	opt = ft_split(client->buff);
	size = ft_table_len(opt);
	if (size < 3)
		ft_print("You need to specify the addr and the port.\n", 1);
	else if (size > 3)
		ft_print("Connect takes only 2 arguments,	\
			the address and the port.\n", 1);
	else
	{
		if (client->is_connected)
			close(client->sock);
		client->sock = create_client(opt[1], ft_atoi(opt[2]));
		if (client->sock != -1)
			client->is_connected = 1;
	}
}

void		command_nick(t_client *client)
{
	char	**opt;
	int		size;
	int		len;

	opt = ft_split(client->buff);
	size = ft_table_len(opt);
	if (size > 2)
		ft_print("Too much args.\n", 1);
	else if (size < 2)
		ft_print("You need to specify your nickname.\n", 1);
	else
	{
		len = ft_strlen(opt[1]);
		if (len == 1 && opt[1][0] == '\n')
			printf("You have to specify a nick.\n");
		else if (len > 9)
			ft_print("Your nickname must be comprised between\
	1 and 9 char.\n", 1);
		else if (len > 0)
		{
			ft_strcpynon(client->tmp_nick, opt[1]);
			client->ping = 1;
			ft_strcpy(client->buff_write, client->buff);
		}
	}
}

void		command_chan(t_client *client)
{
	char	**opt;
	int		size;

	opt = ft_split(client->buff);
	size = ft_table_len(opt);
	if (size < 2)
		ft_print("You need to specify the room.\n", 1);
	else if (size > 2)
		ft_print("Too much args.\n", 1);
	else
		ft_strcpy(client->buff_write, client->buff);
}

void		client_command(t_client *client)
{
	if (!ft_strncmp(client->buff, "Exit", 4)
		|| !ft_strncmp(client->buff, "exit", 4))
		client->exit = 1;
	else if (!ft_strncmp(client->buff, "/connect", 8))
		command_connect(client);
}

void		command_panel(t_client *client)
{
	char	tmp[BUFFSIZE + 1];
	char	**opt;

	ft_strcpynon(tmp, client->buff);
	opt = ft_split(tmp);
	if (!opt[0])
		return ;
	if (!ft_strcmp(opt[0], "Exit") || !ft_strcmp(opt[0], "exit"))
		client->exit = 1;
	else if (!ft_strcmp(opt[0], "/connect"))
		command_connect(client);
	else if (!ft_strcmp(opt[0], "/nick"))
		command_nick(client);
	else if (!ft_strcmp(opt[0], "/who"))
		ft_strcpy(client->buff_write, "/who\n");
	else if (!ft_strcmp(opt[0], "/join") || !ft_strcmp(opt[0], "/leave")
		|| !ft_strcmp(opt[0], "/chan"))
		command_chan(client);
	else if (!ft_strcmp(opt[0], "/send"))
		ft_strcpy(client->buff_write, client->buff);
	else if (ft_strncmp(opt[0], "/", 1))
		ft_strcpy(client->buff_write, client->buff);
	else
		printf("Incorrect command.\n");
	free_tab_2d(opt);
}
