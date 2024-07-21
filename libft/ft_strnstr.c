/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: peli <peli@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/30 11:50:55 by peli              #+#    #+#             */
/*   Updated: 2024/05/15 20:47:56 by peli             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	i;
	size_t	j;

	i = 0;
	if (!little[0])
		return ((char *)big);
	while (big[i] != '\0' && i < len)
	{
		j = 0;
		while (little[j] == big[i + j] && little[j] != '\0')
			j++;
		if (j == ft_strlen(little) && j + i <= len)
			return ((char *)big + i);
		i++;
	}
	return (NULL);
}

	// PEIQI's OLD FUNCTION
	//j = 0;
	/*while (i < len && big[i] != '\0')
	{
		while ((big[i] == little[j]) && i < len)
		{
			j++;
			i++;
			if (little[j] == '\0')
				return (&((char *)big)[i - j]);
			if (big[i] != little[j])
				break ;
		}
		i++;
		i++;
		j = 0;
		if(big[i] == little[j])
			i = i - 1; */
	//}
	//return (NULL);/**/

/* int main()
{
	printf("%s\n", ft_strnstr("lorem ipsum dolor ipsumm sit amet","ipsumm",30));
	return (0);
} */