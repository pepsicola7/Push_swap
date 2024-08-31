/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_error.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: peli <peli@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/18 19:36:11 by peli              #+#    #+#             */
/*   Updated: 2024/08/31 12:03:19 by peli             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static long	ft_atol(const char *nptr);
static int ft_isnumber(char *str);
static int ft_strcmp(char *s1, char *s2);
static int ft_multiduplicate(char **str, int count);

int	check_error(int len, char **args)
{
	int	i;

	if (!len)
		return (0);
	i = 0;
	while (args[i])
	{
		if (ft_isnumber(args[i]) == 0)
		{
			return (0);
		}
		i++;
	}
	if (ft_multiduplicate(args, len) == 0)
	{
		return (0);
	}
	return (1);
}

static long	ft_atol(const char *nptr)
{
	int	sign;
	long	result;

	result = 0;
	sign = 1;
	if(ft_strlen(nptr) > 11)
		return ((long)INT_MAX + 1);
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

static int ft_isnumber(char *str)
{
	int i;

	i = 0;
	if (str[i] == '\0')
		return (0);
	if (str[i] == '-')
		i++;
	while (str[i] != '\0')
	{
		if(ft_isdigit(str[i]) == 0)
			return (0);
		i++;
	}
	if (ft_atol(str) > INT_MAX || ft_atol(str) < INT_MIN)
		return(0);
	return (1);
}

static int ft_strcmp(char *s1, char *s2)
{
	int i;

	i = 0;
	while (s1[i] || s2[i])
	{
		if (s1[i] != s2[i])
			return (s1[i] - s2[i]);
		i++;
	}
	return (0);
}

static int ft_multiduplicate(char **str, int count)
{
	int i;
	int j;

	i = 0;
	while (i < count - 1)
	{
		j = i + 1;
		while (j < count)
		{
			if (ft_strcmp(str[i], str[j]) == 0)
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}
