/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   x.c                                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pivanovi <pivanovi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/18 13:56:18 by pivanovi          #+#    #+#             */
/*   Updated: 2015/11/18 13:56:18 by pivanovi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <errno.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "bircd.h"

int		x_int(int err, int res, char *str, char *file)
{
	if (res == err)
	{
		fprintf(stderr, "%s error (%s): %s\n",
		str, file, strerror(errno));
		exit(1);
	}
	return (res);
}

void	*x_void(void *err, void *res, char *str, char *file)
{
	if (res == err)
	{
		fprintf(stderr, "%s error (%s): %s\n",
		str, file, strerror(errno));
		exit(1);
	}
	return (res);
}
