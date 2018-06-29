/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnieto-m <lnieto-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/19 11:11:07 by lnieto-m          #+#    #+#             */
/*   Updated: 2018/05/19 18:04:34 by lnieto-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static int			final_str(char **line, char *str)
{
	char	*tmp;

	tmp = ft_strchr(str, '\n');
	if (tmp != NULL)
	{
		*tmp = '\0';
		*line = ft_strdup(str);
		ft_memmove(str, &tmp[1], ft_strlen(&tmp[1]) + 1);
		return (1);
	}
	if (ft_strlen(str) > 0)
	{
		*line = ft_strdup(str);
		*str = '\0';
		return (1);
	}
	return (0);
}

static char			*check_mem(void)
{
	char	*str;

	str = NULL;
	if (!(str = (char *)malloc(sizeof(char) * 1)))
		return (NULL);
	ft_bzero(str, sizeof(char) * 1);
	return (str);
}

int					get_next_line(int const fd, char **line)
{
	char			buff[BUFF_SIZE + 1];
	int				rd;
	static char		*str = NULL;
	char			*tmp;

	tmp = NULL;
	if (fd < 0 || !line)
		return (-1);
	if (str == NULL)
		if (!(str = check_mem()))
			return (-1);
	while (!ft_strchr(str, '\n'))
	{
		rd = read(fd, buff, BUFF_SIZE);
		if (rd == -1)
			return (-1);
		if (rd == 0)
			break ;
		buff[rd] = '\0';
		tmp = ft_strjoin(str, buff);
		free(str);
		str = tmp;
	}
	return (final_str(line, str));
}
