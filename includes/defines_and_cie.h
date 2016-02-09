/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   defines_and_cie.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pivanovi <pivanovi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/10/22 17:29:10 by pivanovi          #+#    #+#             */
/*   Updated: 2014/10/22 17:29:11 by pivanovi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DEFINES_AND_CIE_H
# define DEFINES_AND_CIE_H

# define BUFFSIZE 4096

# include <sys/select.h>

typedef struct stat			t_stat;
typedef struct rusage		t_rusage;

typedef struct protoent		t_protoent;
typedef struct sockaddr		t_sockaddr;
typedef struct sockaddr_in	t_sockaddr_in;

typedef struct	s_client
{
	int			exit;
	int			sock;
	int			is_connected;
	int			r;
	fd_set		fd_read;
	fd_set		fd_write;
	char		buff[BUFFSIZE + 1];
	char		buff_read[BUFFSIZE + 1];
	char		buff_write[BUFFSIZE + 1];
	char		nick[10];
	char		tmp_nick[10];
	char		prompt[12];
	int			valid_nick;
	int			ping;
}				t_client;

#endif
