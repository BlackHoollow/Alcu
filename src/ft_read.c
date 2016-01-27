/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_read.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nromptea <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/20 11:21:30 by nromptea          #+#    #+#             */
/*   Updated: 2015/12/21 22:41:17 by nromptea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "alum.h"

int		main(int argc, char **argv)
{
	int		error;
	int		fd;

	error = 0;
	if (argc)
	{
		fd = open(argv[1], O_RDONLY);
		error = ft_read(argc, argv);
		if (error == 1)
		{
			write(2, "ERROR\n", 6);
			return (1);
		}
	}
	return (0);
}

int		tab_len(char *str)
{
	int		i;
	int		len;

	i = 0;
	len = 0;
	while (str[i] != '\0')
	{
		if (str[i] == '\n')
			len++;
		i++;
	}
	return (len);
}

char	*ft_read_stdin(char *str, int **tab, int *len)
{
	int		ret;
	int		i;
	char	*str_stdin;
	char	**matrice;

	init_value_rstdin(&ret, &i);
	str_stdin = ft_strnew(0);
	while ((ret = get_next_line(0, &str)) > 0)
	{
		if (ft_strcmp(str, "") == 0)
			break ;
		str_stdin = ft_strjoin(str_stdin, str);
		str_stdin = ft_strjoin(str_stdin, "/");
		*len += 1;
	}
	matrice = ft_strsplit(str_stdin, '/');
	while (matrice[i])
	{
		if (ft_check_stdin_error(matrice[i]) == 1)
			return (NULL);
		i++;
	}
	*tab = ft_atoi_tab(matrice);
	ft_memdel((void **)matrice);
	return (str_stdin);
}

int		ft_read(int argc, char **argv)
{
	int		fd;
	char	*cpy_buff;
	char	buff[BUFF_SIZE + 1];
	int		*tab;
	int		len;

	init_value_read(&fd, &len, &cpy_buff);
	if (ft_argc1(&argc, &cpy_buff, &tab, &len) == 1)
		return (1);
	if (argc == 2)
	{
		if ((fd = open(argv[1], O_RDONLY)) == -1)
			return (1);
		cpy_buff = ft_boucle(buff, cpy_buff, fd);
		if (ft_check_error(cpy_buff) == 1)
			return (1);
		tab = ft_get_tab(cpy_buff, &len);
		if (close(fd) == -1)
			return (1);
	}
	free(cpy_buff);
	if (ft_resolv(tab, len) != 1)
		return (1);
	free(tab);
	return (0);
}

char	*ft_boucle(char *buff, char *cpy_buff, int fd)
{
	char	*tmp;
	int		ret;

	tmp = NULL;
	while (42)
	{
		ret = read(fd, buff, BUFF_SIZE);
		if (ret <= 0)
			break ;
		buff[ret] = '\0';
		if (!(cpy_buff = (char *)malloc(sizeof(char) * (BUFF_SIZE + ret + 1))))
			exit(1);
		if (tmp == NULL)
			ft_strcpy(cpy_buff, buff);
		else
		{
			ft_strcpy(cpy_buff, tmp);
			ft_strcat(cpy_buff, buff);
			free(tmp);
		}
	}
	return (cpy_buff);
}
