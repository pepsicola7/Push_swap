/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: peli <peli@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/26 14:27:10 by peli              #+#    #+#             */
/*   Updated: 2024/05/15 16:24:11 by peli             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	i;
	size_t	a;
	size_t	b;

	i = 0;
	a = ft_strlen(dst);
	b = ft_strlen(src);
	if (size <= a)
	{
		return (size + b);
	}
	while (a + i < (size - 1) && src[i])
	{
		dst[a + i] = src[i];
		i++;
	}
	dst[a + i] = '\0';
	return (a + b);
}
/*
 int	main(int argc, char **argv)
 {
 	int	i;

	i = 0;
 	if (argc < 4)
 	{
 		return (0);
 	}
 	printf("%zu", ft_strlcat(argv[1], argv[2], atoi(argv[3])));
 	return (0);
 }
 */