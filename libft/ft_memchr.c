/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: peli <peli@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/29 15:30:36 by peli              #+#    #+#             */
/*   Updated: 2024/05/15 16:05:00 by peli             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n)
	{
		if (((unsigned char *)s)[i] == (unsigned char)c)
			return ((void *)&s[i]);
		i++;
	}
	return (NULL);
}
/*
int main (int argc, char *argv[])
{
	if (argc < 4)
		return (1);
	printf ("Moi valeur : %s", 
	(char *)ft_memchr(argv[1], argv[2][0], atoi(argv[3])));
	printf ("  | Moi adresse %p\n", 
	((char *)ft_memchr(argv[1], argv[2][0], atoi(argv[3]))));
	printf ("Original valeur : %s", 
	(char *)ft_memchr(argv[1], argv[2][0], atoi(argv[3])));
	printf ("  | Original adresse %p\n", 
	((char *)ft_memchr(argv[1], argv[2][0], atoi(argv[3]))));
	return (0);
}
*/
