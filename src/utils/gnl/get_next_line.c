/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thjacque <thjacque@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/26 16:27:10 by thjacque          #+#    #+#             */
/*   Updated: 2020/12/01 09:59:48 by thjacque         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void	ft_strdel(char **str)
{
	if (*str)
	{
		wrfree(*str);
		*str = NULL;
	}
}

char	*joinnfree(char *str1, char *str2)
{
	char	*newstr;
	int		i;
	int		j;

	if (!str1 || !str2)
		return (NULL);
	i = ft_strlen(str1);
	j = ft_strlen(str2);
	newstr = wrmalloc((i + j + 1) * sizeof(char));
	j = -1;
	ft_strcpy(newstr, str1);
	while (str2[++j])
		newstr[i++] = str2[j];
	wrfree(str1);
	newstr[i] = 0;
	return (newstr);
}

char	*forward(char *rest, char **line, int *eof)
{
	char				*tmp;
	unsigned int		i;

	i = 0;
	if (rest && rest[i])
	{
		while (rest[i] != '\n' && rest[i])
			i++;
		if (i == 0)
			*line = ft_strdup("");
		else
			*line = ft_substr(rest, 0, i);
		if (rest[i] == '\n')
		{
			tmp = ft_strdup(rest + i + 1);
			ft_strcpy(rest, tmp);
			ft_strdel(&tmp);
			return (*line);
		}
		else if (++(*eof))
			return (*line);
	}
	*eof = 1;
	return (ft_strdup(""));
}

char	*get_actual_line(char *buffer, char **rest, int fd)
{
	int		i;
	char	*temp;

	i = read(fd, buffer, 3);
	while (i != 0)
	{
		if (i < 0)
			return ((char *)(-1));
		if (!rest[fd])
			rest[fd] = ft_strdup("");
		buffer[i] = 0;
		temp = joinnfree(rest[fd], buffer);
		if (!temp)
			return ((char *)(-1));
		rest[fd] = temp;
		if (ft_strchr(rest[fd], '\n'))
			break ;
		i = read(fd, buffer, 3);
	}
	return (rest[fd]);
}

int	get_next_line(int fd, char **line)
{
	static char		*rest[4096];
	char			buffer[3 + 1];
	int				eof;

	eof = 0;
	if (fd < 0 || read(fd, buffer, 0) < 0 || !line || 3 < 1)
	{
		if (line)
			*line = NULL;
		return (-1);
	}
	rest[fd] = get_actual_line(buffer, rest, fd);
	if (rest[fd] == (char *)(-1))
	{
		*line = NULL;
		return (-1);
	}
	*line = forward(rest[fd], line, &eof);
	if (eof == 1)
		ft_strdel(&rest[fd]);
	return (eof != 1);
}
