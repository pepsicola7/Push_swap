/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: peli <peli@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/02 14:45:28 by peli              #+#    #+#             */
/*   Updated: 2024/05/15 16:39:37 by peli             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	size_t	i;
	char	*a;
	char	*b;

	if (!dest || !src)
		return (NULL);
	a = (char *)dest;
	b = (char *)src;
	if (dest <= src)
	{
		i = 0;
		while (i < n)
		{
			a[i] = b[i];
			i++;
		}
	}
	else if (n != 0)
	{
		while (--n > 0)
			a[n] = b[n];
		a[n] = b[n];
	}
	return (dest);
}
/*
int main()
{
	char	src[] = "swis";
	printf("mon memmove : %s\n", (char *)ft_memmove(src + 2, src, 1));
	printf("vrai memmove : %s\n", (char *)memmove(dest, src, 5));
}
*/