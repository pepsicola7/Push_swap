/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: peli <peli@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/06 13:52:43 by peli              #+#    #+#             */
/*   Updated: 2024/05/15 16:37:55 by peli             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_compteword(char const *s, char c)
{
	int		i;
	int		j;
	int		start;

	i = 0;
	j = 0;
	start = 0;
	while (s[i] != '\0')
	{
		while (s[i] == c)
			i++;
		if (s[i] != '\0')
		{
			j++;
			while (s[i] && s[i] != c)
				i++;
		}
	}
	return (j);
}

char	**ft_split(char const *s, char c)
{
	char	**result;
	int		start;
	int		i;
	int		a;
	int		len;

	i = 0;
	a = 0;
	if (s == NULL)
		return (NULL);
	len = ft_compteword(s, c);
	result = malloc((len + 1) * sizeof(char *));
	if (!result)
		return (NULL);
	while (a < len)
	{
		while (s[i] == c)
			i++;
		start = i;
		while (s[i] != '\0' && s[i] != c)
			i++;
		result[a++] = ft_substr(s, start, i - start);
	}
	result[a] = NULL;
	return (result);
}
