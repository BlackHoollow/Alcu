/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rporcon <rporcon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/21 15:22:29 by rporcon           #+#    #+#             */
/*   Updated: 2015/12/21 20:44:46 by rporcon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "alum.h"

int		*ft_get_tab(char *str, int *len)
{
	int		i;
	int		j;
	int		*tab;

	i = 0;
	j = 0;
	*len = tab_len(str);
	tab = (int *)malloc(sizeof(int) * ((*len) + 1));
	tab[j] = ft_atoi(str);
	j++;
	while (str[i] != '\0')
	{
		if (str[i] == '\n')
		{
			tab[j] = ft_atoi(str + i);
			j++;
		}
		i++;
	}
	return (tab);
}

int		ft_check_error(char *str)
{
	int		i;
	int		count_bsn;

	i = 0;
	count_bsn = 0;
	if (str[i] == '\n')
		return (1);
	while (str[i] != '\0')
	{
		if (ft_isdigit(str[i]) == 0 && str[i] != '\n')
			return (1);
		if (str[i] == '\n')
			count_bsn++;
		if (str[i] == '\n' && str[i + 1] == '\n')
			return (1);
		i++;
	}
	if (i < 1 || i > 9999 || count_bsn == 0)
		return (1);
	return (0);
}

int		ft_check_stdin_error(char *str)
{
	int		i;

	i = 0;
	while (str[i] != '\0')
	{
		if (ft_isdigit(str[i]) == 0)
			return (1);
		i++;
	}
	if (i < 1 || i > 9999)
		return (1);
	return (0);
}

int		*ft_atoi_tab(char **file)
{
	int		count;
	int		i;
	int		*tab;

	i = 0;
	count = 0;
	while (file[i])
	{
		count++;
		i++;
	}
	tab = (int *)malloc(sizeof(int) * count);
	i = 0;
	while (file[i])
	{
		tab[i] = ft_atoi(file[i]);
		i++;
	}
	return (tab);
}
