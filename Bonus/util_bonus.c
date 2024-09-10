/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: peli <peli@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/06 15:40:50 by peli              #+#    #+#             */
/*   Updated: 2024/09/09 15:23:02 by peli             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	ft_push_a_bonus(t_stack **a, t_stack **b)
{
	t_stack	*temp;

	if (!*b)
		return ;
	temp = pop_from_stack(b);
	push_to_stack(a, temp);
}

void	ft_push_b_bonus(t_stack **b, t_stack **a)
{
	t_stack	*temp;

	if (!*a)
		return ;
	temp = pop_from_stack(a);
	push_to_stack(b, temp);
}

int	ft_strcmp_gnl(const char *s1, const char *s2)
{
	int	i;

	i = 0;
	while (s1[i] && s2[i] && s1[i] == s2[i])
		i++;
	return (s1[i] - s2[i]);
}

int	ft_checker(t_stack **a, t_stack **b)
{
	char	*commande;

	commande = get_next_line(0);
	while (commande != NULL)
	{
		if (ft_execute_commande(commande, a, b) == 0)
		{
			free(commande);
			write (1, "Error\n", 6);
			return (0);
		}
		free (commande);
		commande = get_next_line(0);
	}
	return (1);
}
