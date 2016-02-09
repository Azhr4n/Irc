/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bircd.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pivanovi <pivanovi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/01 17:47:43 by pivanovi          #+#    #+#             */
/*   Updated: 2015/12/01 17:47:44 by pivanovi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BIRCD_H
# define BIRCD_H

# include <sys/select.h>

# include "tools.h"

# define FD_FREE	0
# define FD_SERV	1
# define FD_CLIENT	2

# define BUF_SIZE	4096

# define XV(err,res,str)	(x_void(err,res,str,__FILE__))
# define X(err,res,str)		(x_int(err,res,str,__FILE__))
# define MAX(a,b)			((a > b) ? a : b)

# define USAGE				"Usage: %s port\n"

typedef struct		s_fd
{
	int				type;
	void			(*fct_read)();
	void			(*fct_write)();
	char			buf_read[BUF_SIZE + 1];
	char			buf_write[BUF_SIZE + 1];
	char			command_buf[BUF_SIZE + 1];
	t_list			*room;
	t_list			*current_room;
	char			nick[10];
}					t_fd;

typedef struct		s_env
{
	t_fd			*fds;
	int				port;
	int				maxfd;
	int				max;
	int				r;
	fd_set			fd_read;
	fd_set			fd_write;
}					t_env;

void				init_env(t_env *e);
void				get_opt(t_env *e, int ac, char **av);
void				main_loop(t_env *e);
void				srv_create(t_env *e, int port);
void				srv_accept(t_env *e, int s);
void				client_read(t_env *e, int cs);
void				client_write(t_env *e, int cs);
void				clean_fd(t_fd *fd);
int					x_int(int err, int res, char *str, char *file);
void				*x_void(void *err, void *res, char *str, char *file);
void				init_fd(t_env *e);
void				do_select(t_env *e);
void				check_fd(t_env *e);

/*
***command.c
*/
void				get_user_nick(t_env *e, int cs);
void				command_who(t_env *e, int cs);
void				command_chan(t_env *e, int cs);
void				send_to_chan(t_env *e, int cs);

/*
***command2.c
*/
void				command_join(t_env *e, int cs);
void				command_leave(t_env *e, int cs);

#endif
