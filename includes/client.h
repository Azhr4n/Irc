/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pivanovi <pivanovi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/18 13:49:21 by pivanovi          #+#    #+#             */
/*   Updated: 2015/11/18 13:49:22 by pivanovi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLIENT_H
# define CLIENT_H

# include <netdb.h>
# include <stdlib.h>
# include <unistd.h>
# include <sys/uio.h>
# include <sys/types.h>
# include <arpa/inet.h>
# include <sys/socket.h>
# include <netinet/in.h>
# include <stdio.h>
# include <string.h>

/*
***Command.c
*/
void		command_connect(t_client *client);
void		command_nick(t_client *client);
void		command_chan(t_client *client);
void		client_command(t_client *client);
void		command_panel(t_client *client);

/*
***set_client.c
*/
int			create_client(char *addr, int port);
void		choose_nick(t_client *client);
void		set_client(t_client *client);
void		set_prompt(t_client *client);

/*
***fd.c
*/
void		init_fd(t_client *client);
void		check_fd(t_client *client);

#endif
