/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client_write.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pivanovi <pivanovi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/01 17:24:53 by pivanovi          #+#    #+#             */
/*   Updated: 2015/12/01 17:24:54 by pivanovi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sys/socket.h>
#include <unistd.h>

#include "bircd.h"
#include "tools.h"

#include <stdio.h>

void	client_write(t_env *e, int cs)
{
	puts(e->fds[cs].buf_write);
	write(cs, e->fds[cs].buf_write, ft_strlen(e->fds[cs].buf_write));
	ft_bzero(e->fds[cs].buf_write, BUF_SIZE);
}
