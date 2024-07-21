/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: peli <peli@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/08 17:27:04 by peli              #+#    #+#             */
/*   Updated: 2024/05/15 16:38:34 by peli             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putstr_fd(char *s, int fd)
{
	int		i;

	i = 0;
	if (!s)
		return ;
	while (s[i])
	{
		write(fd, &s[i], 1);
		i++;
	}
}
/*
int main() 
{
	// Écrire "Hello, World!" sur la sortie standard
	ft_putstr_fd("Hello, World!\n", STDOUT_FILENO);

	// Écrire "Something went wrong!" sur l'erreur standard
	ft_putstr_fd("Something went wrong!\n", STDERR_FILENO);

	return 0;
}
*/