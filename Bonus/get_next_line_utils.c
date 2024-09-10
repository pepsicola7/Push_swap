/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: peli <peli@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/06 13:19:32 by peli              #+#    #+#             */
/*   Updated: 2024/09/09 15:15:41 by peli             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	nextelse(int a, char **nextstr_ptr)
{
	char	*t1;
	char	*nextstr;

	t1 = NULL;
	nextstr = *nextstr_ptr;
	if (a != ft_strlen_gnl(nextstr))
	{
		t1 = ft_strdup_gnl(nextstr);
		free(nextstr);
		*nextstr_ptr = ft_substr(t1, a, ft_strlen_gnl(t1) - a);
		free(t1);
		return (0);
	}
	return (1);
}

char	*ft_strdup_gnl(char *s)
{
	char	*str;
	int		i;
	int		j;

	if (!s)
		return (NULL);
	i = ft_strlen_gnl(s);
	j = 0;
	str = malloc(sizeof(char) * (i + 1));
	if (!str)
		return (NULL);
	while (s[j] != '\0')
	{
		str[j] = s[j];
		j++;
	}
	str[j] = '\0';
	return (str);
}

int	ft_strlen_gnl(const char *str)
{
	int	i;

	i = 0;
	if (!str)
		return (0);
	while (str[i])
		i++;
	return (i);
}

char	*ft_strjoin_gnl(char *s1, char *s2)
{
	char	*strjoin;
	int		i;
	int		j;

	if (s1 == NULL)
		strjoin = ft_strdup_gnl(s2);
	else if (s2 == NULL)
		strjoin = ft_strdup_gnl(s1);
	else
	{
		strjoin = malloc((ft_strlen_gnl(s1) + ft_strlen_gnl(s2) + 1));
		if (!strjoin)
			return (NULL);
		i = 0;
		j = 0;
		while (s1[i])
			strjoin[j++] = s1[i++];
		i = 0;
		while (s2[i])
			strjoin[j++] = s2[i++];
		strjoin[j] = '\0';
	}
	free(s1);
	free(s2);
	return (strjoin);
}

char	*ft_substr_gnl(char *s, int start, int len)
{
	char	*ptr;
	int		i;

	i = 0;
	if (!s)
		return (NULL);
	if (ft_strlen_gnl(s) < start)
		return (ft_strdup_gnl(""));
	if (ft_strlen_gnl(s + start) < len)
		len = ft_strlen_gnl(s + start);
	ptr = malloc ((len + 1) * sizeof(char));
	if (!ptr)
		return (NULL);
	while (s[start] && i < len)
	{
		ptr[i] = (char)s[start];
		i++;
		start++;
	}
	ptr[i] = '\0';
	return (ptr);
}
