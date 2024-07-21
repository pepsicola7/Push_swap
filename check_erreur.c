/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_erreur.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: peli <peli@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/18 19:36:11 by peli              #+#    #+#             */
/*   Updated: 2024/07/19 18:10:24 by peli             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int ft_isdigit(int c)
{
	if ((c >= '0' && c <= '9'))
		return (1);
	else
		return (0);
}

long	ft_atol(const char *nptr)
{
	int	sign;
	long	result;

	result = 0;
	sign = 1;
	while ((*nptr >= 9 && *nptr <= 13) || (*nptr == 32))
	{
		nptr++;
	}
	if (*nptr == '-' || *nptr == '+')
	{
		if (*nptr == '-')
		{
			sign = -1;
		}
		nptr++;
	}
	while (*nptr >= '0' && *nptr <= '9')
	{
		result = result * 10 + ((*nptr - 48) % 10);
		nptr++;
	}
	return (result * sign);
}

int ft_isnumber(char *str)
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
	// printf("%ld\n", ft_atol(str));
	if (ft_atol(str) > INT_MAX || ft_atol(str) < INT_MIN)
		return(0);
	return (1);
}

int ft_strcmp(char *s1, char *s2)
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

int ft_multidoublon(char **str, int count)
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

int	check_erreur(int argc, char **argv)
{
	int	i;
	
	char	**args;
	if (argc <= 1)
		return(0);
	else 
	{
		args = argv;
		i = 1;
		if (argc == 2)
		{
			args = ft_split(argv[1], ' ');
			i = 0;
		}
		while (args[i])
		{
			if (ft_isnumber(args[i]) == 0)
				return (0);
			i++;
		}
		if (argc == 2)
			argc = i++;
		if (ft_multidoublon(args, argc) == 0)
			return (0);
	}
	return (1);
}
