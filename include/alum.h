/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   alum.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rporcon <rporcon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/21 21:28:16 by rporcon           #+#    #+#             */
/*   Updated: 2015/12/21 21:28:20 by rporcon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ALUM_H
# define ALUM_H

# include "libft.h"
# include <fcntl.h>
# define BUFF_SIZE 42

char	*ft_boucle(char *buff, char *cpy_buff, int fd);
int		ft_read(int argc, char **argv);
int		tab_len(char *str);
int		*ft_get_tab(char *str, int *len);
int		ft_check_error(char *str);
int		ft_check_stdin_error(char *str);
char	*ft_read_stdin(char *str, int **tab, int *len);
int		*ft_atoi_tab(char **file);
void	init_value_rstdin(int *ret, int *i);
void	init_value_read(int *fd, int *len, char **cpy_buff);
int		ft_argc1(int *argc, char **cpybuff, int **tab, int *len);

void	print_tab(int *tab);
int		win_this(int *tab, int i);
int		loose_this(int *tab, int i);
int		ia_turn(int *tab, int i);
int		ft_resolv(int *tab, int len);

int		player_turn(int *tab, int len);
int		check_len(int *tab, int *len);
int		ft_turn(int *tab, int len, int res);

int		get_next_line(int const fd, char **line);

#endif
