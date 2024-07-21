/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: peli <peli@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/08 17:04:03 by peli              #+#    #+#             */
/*   Updated: 2024/05/15 16:33:19 by peli             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putchar_fd(char c, int fd)
{
	write(fd, &c, 1);
}
/*
int main() {
	// Écrire "Hello, World!" sur la sortie standard
	ft_putchar_fd('h', 1);

	// Écrire "Something went wrong!" sur l'erreur standard
	ft_putchar_fd('s', 2);

	return 0;
}
*/