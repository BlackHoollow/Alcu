/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_resolv_bis.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nromptea <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/20 15:52:38 by nromptea          #+#    #+#             */
/*   Updated: 2015/12/21 21:03:29 by nromptea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "alum.h"

int		player_turn(int *tab, int len)
{
	char	*line;
	int		value;
	int		i;

	value = 0;
	i = 0;
	while (42)
	{
		ft_putstr("Choisi un chiffre entre un et trois s'il te plait : ");
		get_next_line(0, &line);
		while (line[i])
		{
			if (ft_isdigit(line[i]) == 0)
				break ;
			i++;
		}
		value = ft_atoi(line);
		if ((value > 0 && value < 4) && (value <= tab[len]))
			return (value);
	}
}

int		check_len(int *tab, int *len)
{
	if (tab[*len] == 0)
	{
		*len = *len - 1;
		if (*len < 0)
		{
			ft_putendl("PLAYER WON");
			return (1);
		}
	}
	return (0);
}

int		ft_turn(int *tab, int len, int res)
{
	while (len >= 0)
	{
		while (tab[len] > 0)
		{
			ft_putendl("computer playing");
			print_tab(tab);
			res = ia_turn(tab, len);
			tab[len] = tab[len] - res;
			if (check_len(tab, &len) == 1)
				return (1);
			ft_putchar('\n');
			ft_putendl("player playing");
			print_tab(tab);
			res = player_turn(tab, len);
			tab[len] = tab[len] - res;
			ft_putchar('\n');
		}
		len--;
	}
	ft_putendl("COMPUTER WIN");
	return (0);
}
