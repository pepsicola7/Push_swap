/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gnl.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: peli <peli@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/06 11:25:20 by peli              #+#    #+#             */
/*   Updated: 2024/09/09 15:22:25 by peli             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

char	*ft_nextstr(char **nextstr_ptr)
{
	int		a;
	char	*text;
	char	*nextstr;

	a = 0;
	text = NULL;
	nextstr = *nextstr_ptr;
	while ((*nextstr_ptr)[a] != '\n' && (*nextstr_ptr)[a] != '\0')
		a++;
	if (a == ft_strlen_gnl(nextstr))
		text = ft_strdup_gnl(nextstr);
	else
	{
		text = ft_substr_gnl(nextstr, 0, ++a);
		if (nextelse(a, nextstr_ptr) == 0)
			return (text);
	}
	free (nextstr);
	*nextstr_ptr = NULL;
	return (text);
}

char	*read_buffer(int fd, int *bytes_read)
{
	char	*buf;

	buf = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buf)
		return (NULL);
	*bytes_read = read(fd, buf, BUFFER_SIZE);
	if (*bytes_read < 0)
	{
		free(buf);
		return (NULL);
	}
	buf[*bytes_read] = '\0';
	return (buf);
}

char	*concat_text(char *text, char *buf)
{
	char	*temp;

	if (text)
	{
		temp = ft_strdup_gnl(text);
		free(text);
		text = ft_strjoin_gnl(temp, buf);
	}
	else
	{
		text = ft_strdup_gnl(buf);
		free(buf);
	}
	return (text);
}

int	ft_end(char *buf, char **text, char **nextstr)
{
	int	i;

	i = 0;
	while (buf[i] != '\0' && buf[i] != '\n')
		i++;
	if (buf[i] == '\0')
		*text = concat_text(*text, buf);
	else if (buf[i] == '\n')
	{
		*text = ft_strjoin_gnl(*text, ft_substr_gnl(buf, 0, ++i));
		if (i != ft_strlen_gnl(buf))
			*nextstr = ft_substr_gnl(buf, i, ft_strlen_gnl(buf));
		return (0);
	}
	return (1);
}

char	*get_next_line(int fd)
{
	char		*buf;
	char		*text;
	int			j;
	static char	*nextstr;

	text = NULL;
	while (1)
	{
		if (nextstr)
		{
			text = ft_nextstr(&nextstr);
			if (nextstr)
				return (text);
		}
		buf = read_buffer(fd, &j);
		if (!buf)
			return (NULL);
		if (j == 0)
			break ;
		if (!ft_end(buf, &text, &nextstr))
			break ;
	}
	free (buf);
	return (text);
}
