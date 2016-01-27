/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_norme.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rporcon <rporcon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/21 19:22:56 by rporcon           #+#    #+#             */
/*   Updated: 2015/12/21 22:06:08 by nromptea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "alum.h"

void	init_value_rstdin(int *ret, int *i)
{
	*ret = 0;
	*i = 0;
}

void	init_value_read(int *fd, int *len, char **cpy_buff)
{
	*cpy_buff = NULL;
	*fd = 0;
	*len = 0;
}

int		ft_argc1(int *argc, char **cpy_buff, int **tab, int *len)
{
	if (*argc > 2)
		return (1);
	if (*argc == 1)
	{
		*cpy_buff = ft_read_stdin(*cpy_buff, tab, len);
		if (*cpy_buff == NULL)
			return (1);
	}
	return (0);
}
