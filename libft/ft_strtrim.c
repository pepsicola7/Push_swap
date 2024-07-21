/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: peli <peli@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/03 13:49:51 by peli              #+#    #+#             */
/*   Updated: 2024/05/15 20:01:53 by peli             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

unsigned int	ft_whereisend(char const *s1, char const *set, unsigned int i)
{
	unsigned int	s;
	unsigned int	b;

	if (s1[0] == '\0')
		return (-1);
	s = ft_strlen(s1) - 1;
	b = 0;
	while (set[b] != '\0')
	{
		if (s1[s] == set[b] && s1[s] != '\0' && s > i)
		{
			s--;
			b = 0;
		}
		else
			b++;
	}
	return (s);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	char			*str;
	unsigned int	i;
	unsigned int	j;
	unsigned int	s;

	i = 0;
	j = 0;
	if (!s1)
		return (NULL);
	if (!set)
		return (ft_strdup(s1));
	while (set[j] != '\0')
	{
		if (s1[i] == set[j] && s1[i] != '\0')
		{
			i++;
			j = 0;
		}
		else
			j++;
	}
	s = ft_whereisend(s1, set, i);
	str = ft_substr(s1, i, (s - i + 1));
	return (str);
}
