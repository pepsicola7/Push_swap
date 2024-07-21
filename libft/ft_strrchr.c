/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: peli <peli@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/27 15:52:01 by peli              #+#    #+#             */
/*   Updated: 2024/05/15 16:35:05 by peli             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int		i;
	int		a;

	i = 0;
	a = -1;
	while (s[i] != '\0')
	{
		if (s[i] == (unsigned char)c)
		{
			a = i;
		}
		i++;
	}
	if (c == '\0')
		return ((char *)&s[i]);
	if (a == -1)
		return (NULL);
	return ((char *)&s[a]);
}
/*
int	main(int argc, char *argv[])
{
	if (argc < 3)
		return (1);
	printf("%s", ft_strrchr(argv[1], argv[2][0]));
	return (0);
}
*/