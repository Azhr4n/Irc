/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_client.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pivanovi <pivanovi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/01 16:58:45 by pivanovi          #+#    #+#             */
/*   Updated: 2015/12/01 16:58:45 by pivanovi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "defines_and_cie.h"
#include "tools.h"
#include "client.h"

int			create_client(char *addr, int port)
{
	t_protoent		*proto;
	int				sock;
	t_sockaddr_in	sin;

	proto = getprotobyname("tcp");
	if (!proto)
	{
		ft_print("Error with getprotobyname.\n", 2);
		exit(-1);
	}
	sock = socket(PF_INET, SOCK_STREAM, proto->p_proto);
	sin.sin_family = AF_INET;
	sin.sin_port = htons(port);
	sin.sin_addr.s_addr = inet_addr(addr);
	if (connect(sock, (const t_sockaddr *)&sin, sizeof(sin)) == -1)
	{
		ft_print("Connect failed.\n", 2);
		return (-1);
	}
	return (sock);
}

static void	cpy_nick(char *dest, char *src)
{
	int		i;

	i = 0;
	while (*src)
	{
		if (*src != ' ' && *src != '\t')
		{
			dest[i] = *src;
			i++;
		}
		src++;
	}
}

void		choose_nick(t_client *client)
{
	int		ret;
	int		done;

	done = 0;
	while (!done)
	{
		ft_print("Nickname : ", 1);
		ret = read(0, client->buff, BUFFSIZE);
		client->buff[ret - 1] = 0;
		ret--;
		if (ret < 10 && ret > 0 && client->buff[0] != '/'
			&& client->buff[0] != '\t' && client->buff[0] != ' ')
		{
			cpy_nick(client->tmp_nick, client->buff);
			ft_bzero(client->buff_write, BUFFSIZE + 1);
			ft_strcat(client->buff_write, "/nick ");
			ft_strcat(client->buff_write, client->tmp_nick);
			ft_strcat(client->buff_write, "\n");
			client->ping = 1;
			done = 1;
		}
		else
			ft_print("Invalid nickname (9char max, 1 min.).\n", 1);
	}
}

void		set_client(t_client *client)
{
	client->sock = -1;
	client->is_connected = 0;
	client->valid_nick = 0;
	client->ping = 0;
	client->exit = 0;
	ft_bzero(client->buff, BUFFSIZE + 1);
	ft_bzero(client->buff_read, BUFFSIZE + 1);
	ft_bzero(client->buff_write, BUFFSIZE + 1);
	ft_bzero(client->nick, 10);
	ft_bzero(client->tmp_nick, 10);
}

void		set_prompt(t_client *client)
{
	ft_strcpy(client->prompt, client->nick);
	ft_strcat(client->prompt, "> ");
}
