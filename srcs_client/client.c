/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pivanovi <pivanovi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/10/22 17:20:42 by pivanovi          #+#    #+#             */
/*   Updated: 2014/10/22 17:20:42 by pivanovi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "defines_and_cie.h"
#include "tools.h"
#include "client.h"

void		main_loop(t_client *client)
{
	choose_nick(client);
	while (!client->exit)
	{
		init_fd(client);
		client->r = select(client->sock + 1, &client->fd_read,
			&client->fd_write, NULL, NULL);
		check_fd(client);
	}
	close(client->sock);
}

void		unlogged_loop(t_client *client)
{
	int		ret;

	ft_strcpy(client->prompt, client->tmp_nick);
	ft_strcat(client->prompt, "> ");
	while (!client->is_connected && !client->exit)
	{
		ft_print(client->prompt, 1);
		ret = read(0, client->buff, BUFFSIZE);
		client->buff[ret] = 0;
		client_command(client);
	}
	main_loop(client);
}

int			main(int ac, char **av)
{
	t_client	client;

	set_client(&client);
	if (ac == 3)
	{
		ft_strcpy(client.buff, "/connect ");
		ft_strcat(client.buff, av[1]);
		ft_strcat(client.buff, " ");
		ft_strcat(client.buff, av[2]);
		command_connect(&client);
		if (client.sock != -1)
			main_loop(&client);
	}
	while (!client.exit)
		unlogged_loop(&client);
	return (0);
}
