/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: peli <peli@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/01 19:48:51 by peli              #+#    #+#             */
/*   Updated: 2024/05/15 16:22:54 by peli             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*ptr;
	size_t	total_size;

	total_size = nmemb * size;
	if ((size >= 65535 && nmemb >= 65535) || total_size >= 65535)
		return (NULL);
	ptr = (void *)malloc(total_size);
	if (ptr == 0)
		return (NULL);
	ft_bzero(ptr, total_size);
	return (ptr);
}

/*
int main()
{
	printf("%d", (int)ft_calloc(100, sizeof(int)));
	printf("%d", calloc(100, sizeof(int)));
	return (0);
}
*/
