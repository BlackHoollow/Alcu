/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_resolv.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rporcon <rporcon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/21 21:27:21 by rporcon           #+#    #+#             */
/*   Updated: 2015/12/21 22:49:01 by nromptea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "alum.h"

void	print_tab(int *tab)
{
	int		i;
	int		j;

	i = 0;
	while (tab[i])
	{
		j = 0;
		while (j < tab[i])
		{
			ft_putchar('|');
			j++;
		}
		ft_putchar('\n');
		i++;
	}
	ft_putchar('\n');
}

int		win_this(int *tab, int i)
{
	if ((tab[i] - 1) % 4 == 3)
		return (3);
	else if ((tab[i] - 1) % 4 == 2)
		return (2);
	else if ((tab[i] - 1) % 4 == 1)
		return (1);
	else if ((tab[i] - 1) % 4 == 0)
		return (1);
	return (0);
}

int		loose_this(int *tab, int i)
{
	if (tab[i] % 4 == 3)
		return (3);
	else if (tab[i] % 4 == 2)
		return (2);
	else if (tab[i] % 4 == 1)
		return (1);
	else if (tab[i] % 4 == 0)
		return (1);
	return (0);
}

int		ia_turn(int *tab, int len)
{
	int		res;

	res = 0;
	if (tab[len] % 4 == 1)
	{
		res = loose_this(tab, len);
		if (res == 0)
			return (0);
	}
	else
	{
		res = win_this(tab, len);
		if (res == 0)
			return (0);
	}
	return (res);
}

int		ft_resolv(int *tab, int len)
{
	int	res;
	int	ret;

	res = 0;
	if (len == 0)
	{
		write(2, "ERROR\n", 6);
		return (1);
	}
	if (len > 0)
		ret = ft_turn(tab, len, res);
	return (1);
}
