/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_loop.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pivanovi <pivanovi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/01 17:28:59 by pivanovi          #+#    #+#             */
/*   Updated: 2015/12/01 17:29:00 by pivanovi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bircd.h"

void	main_loop(t_env *e)
{
	while (1)
	{
		init_fd(e);
		do_select(e);
		check_fd(e);
	}
}