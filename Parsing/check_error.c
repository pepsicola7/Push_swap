/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_error.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: peli <peli@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/18 19:36:11 by peli              #+#    #+#             */
/*   Updated: 2024/09/09 20:44:18 by peli             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static long	ft_atol(const char *nptr);
static int	ft_isnumber(char *str);

int	check_error(int len, char **args)
{
	int		i;
	long	temp;
	int		*tmp;

	if (!len)
		return (0);
	i = 0;
	temp = 0;
	tmp = malloc(sizeof(int) * len);
	while (args[i])
	{
		if (ft_isnumber(args[i]) == 0)
			return (free(tmp), 0);
		temp = ft_atol(args[i]);
		if ((temp == (long)INT_MAX + 1) || ft_multiduplicate(tmp, i, temp))
			return (free(tmp), 0);
		tmp[i] = (int)temp;
		i++;
	}
	return (free(tmp), 1);
}

int	ft_multiduplicate(int *tab, int i, int data)
{
	int	j;

	j = 0;
	while (j < i)
	{
		if (tab[j] == data)
			return (1);
		j++;
	}
	return (0);
}

static long	ft_atol(const char *nptr)
{
	int		sign;
	long	result;

	result = 0;
	sign = 1;
	if (ft_strlen(nptr) > 11)
		return ((long)INT_MAX + 1);
	while ((*nptr >= 9 && *nptr <= 13) || (*nptr == 32))
		nptr++;
	if (*nptr == '-' || *nptr == '+')
	{
		if (*nptr == '-')
			sign = -1;
		nptr++;
	}
	if (!(*nptr >= '0' && *nptr <= '9'))
		return ((long)INT_MAX + 1);
	while (*nptr >= '0' && *nptr <= '9')
	{
		result = result * 10 + ((*nptr - 48) % 10);
		nptr++;
	}
	return (result * sign);
}

static int	ft_isnumber(char *str)
{
	int	i;

	i = 0;
	if (str[i] == '\0')
		return (0);
	if (str[i] == '-' || str[i] == '+')
		i++;
	while (str[i] != '\0')
	{
		if (ft_isdigit(str[i]) == 0)
			return (0);
		i++;
	}
	if (ft_atol(str) > INT_MAX || ft_atol(str) < INT_MIN)
		return (0);
	return (1);
}
