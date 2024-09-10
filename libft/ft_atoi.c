/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: peli <peli@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/01 17:02:22 by peli              #+#    #+#             */
/*   Updated: 2024/09/09 20:13:43 by peli             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(const char *nptr)
{
	int	sign;
	int	result;

	result = 0;
	sign = 1;
	while ((*nptr >= 9 && *nptr <= 13) || (*nptr == 32))
		nptr++;
	if (*nptr == '-' || *nptr == '+')
	{
		if (*nptr == '-')
			sign = -1;
		nptr++;
	}
	while (*nptr >= '0' && *nptr <= '9')
	{
		result = result * 10 + ((*nptr - 48) % 10);
		nptr++;
	}
	return (result * sign);
}
/*
int main()
{
	char	*str = "    \n-42test";
	char	*str1 = "    \n-42test";
	printf("ton atoi = %d\n", ft_atoi(str));
	printf("le vrai atoi = %d\n", atoi(str1));
}
*/
