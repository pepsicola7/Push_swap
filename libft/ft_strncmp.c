/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: peli <peli@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/29 11:03:51 by peli              #+#    #+#             */
/*   Updated: 2024/05/15 16:35:26 by peli             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t			i;
	unsigned char	c1;
	unsigned char	c2;

	i = 0;
	if (!s1 || !s2)
		return (-1);
	while (i < n)
	{
		c1 = (unsigned char)s1[i];
		c2 = (unsigned char)s2[i];
		if (c1 == '\0' || c2 == '\0')
			return (c1 - c2);
		if (c1 != c2)
			return (c1 - c2);
		i++;
	}
	return (0);
}

/* int main()
{
	printf("%d\n", ft_strncmp("test\200", "test\0", 5));
	printf("standard %d\n", strncmp("test\200", "test\0", 5));
	return (0);
} */
