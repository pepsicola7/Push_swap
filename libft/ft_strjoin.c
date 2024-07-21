/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: peli <peli@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/03 11:42:18 by peli              #+#    #+#             */
/*   Updated: 2024/05/15 16:34:07 by peli             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*strjoin;
	int		len1;
	int		len2;

	if (s1 == NULL && s2 == NULL)
		return (ft_strdup(""));
	if (s1 == NULL)
		return (ft_strdup(s2));
	if (s2 == NULL)
		return (ft_strdup(s1));
	len1 = ft_strlen(s1);
	len2 = ft_strlen(s2);
	strjoin = (char *)malloc((len1 + len2 + 1) * sizeof(char));
	if (!strjoin)
		return (NULL);
	ft_strlcpy(strjoin, s1, len1 + 1);
	ft_strlcat(strjoin, s2, len1 + len2 + 1);
	return (strjoin);
}
/*
int main(void)
{
	char	*dest = ft_strjoin("Hello", "");
	if (dest == NULL)
	{
		printf("split returned NULL\n");
		return 1;
	}
	free(dest);
}
*/
/*
 while (*s1 != '\0' || *s2 != '\0')
	{
	    if (*s1 != '\0')
	    {
	        *strjoin = *s1;
	        s1++;
	    }
	    else if (*s2 != '\0')
	    {
	        *strjoin = *s2;
	        s2++;
	    }
	    strjoin++;
	}
*/
