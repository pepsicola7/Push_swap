/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: peli <peli@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/15 15:41:30 by peli              #+#    #+#             */
/*   Updated: 2024/05/15 16:32:26 by peli             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_nb_len(int n)
{
	int	len;

	len = 0;
	if (n < 0)
		len++;
	while (n != 0)
	{
		n /= 10;
		len++;
	}
	return (len);
}

static void	ft_fill_str(int n, int len, char *str)
{
	int	idx;

	idx = len - 1;
	str[len] = '\0';
	if (n < 0)
	{
		n = n * (-1);
		str[0] = '-';
	}
	while (n > 0)
	{
		str[idx] = (n % 10) + '0';
		n /= 10;
		idx--;
	}
}

char	*ft_itoa(int n)
{
	char	*str;
	int		len;

	str = NULL;
	if (n == 0)
		return (ft_strdup("0"));
	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	len = ft_nb_len(n);
	str = malloc((len + 1) * sizeof(char));
	if (str == NULL)
		return (ft_strdup(""));
	ft_fill_str(n, len, str);
	return (str);
}
/* 
int	main()
{
	char	* str = ft_itoa(42);
	printf("str: %s\n", str);
	free(str);
	return (0);
} */