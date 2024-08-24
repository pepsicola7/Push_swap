/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: peli <peli@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/12 14:17:49 by peli              #+#    #+#             */
/*   Updated: 2024/08/24 14:46:01 by peli             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

// void	ft_push_a(t_stack **a, t_stack **b)
// {
// 	t_stack *futur_b;

// 	if(!*b)
// 		return;
// 	futur_b = (*b)->next;
// 	if (futur_b == *b)
// 		futur_b = NULL;
// 	else
// 	{
// 		(*b)->next->prev = (*b)->prev;
// 		(*b)->prev->next = (*b)->next;
// 	}
// 	if(!*a)
// 	{
// 		*a = futur_b;
// 		(*a)->next = *a;
// 		(*a)->prev = *a;
// 	}
// 	(*b)->next = (*a);
// 	(*b)->prev = (*a)->prev;
// 	(*a)->prev = *b;
// 	(*b)->prev->next = *b;
// 	*a = (*b);
// 	*b = futur_b;
// 	printf("pa\n");
// }
// void	ft_push_b(t_stack **b, t_stack **a)
// {
// 	t_stack *futur_a;

// 	if(!*a)
// 		return;
// 	futur_a = (*a)->next;
// 	if (futur_a == *a)
// 		futur_a = NULL;
// 	else
// 	{
// 		(*a)->next->prev = (*a)->prev;
// 		(*a)->prev->next = (*a)->next;
// 	}
// 	if(!*b)
// 	{
// 		*b = futur_a;
// 		(*b)->next = *b;
// 		(*b)->prev = *b;
// 	}
// 	(*a)->next = (*b);
// 	(*a)->prev = (*b)->prev;
// 	(*b)->prev = *a;
// 	(*a)->prev->next = *a;
// 	*b = (*a);
// 	*a = futur_a;
// 	printf("pb\n");
// }
// void	ft_push_a(t_stack **a, t_stack **b)
// {
// 	t_stack	*temps;

// 	if(!*b)
// 		return;
// 	printf("LAST OF A : %d\n", (*a)->prev->value);
// 	temps = *b;
// 	if (*b == (*b)->next)
// 		*b = NULL;
// 	else
// 	{
// 		(*b)->prev->next = (*b)->next;
// 		(*b)->next->prev = (*b)->prev;
// 		*b = (*b)->next;
// 	}
// 	if(!*a)
// 	{
// 		*a = temps;
// 		(*a)->next = *a;
// 		(*a)->prev = *a;
// 	}
// 	else
// 	{
// 		temps->next = *a;
// 		temps->prev = (*a)->prev;
// 		(*a)->prev->next =temps;
// 		(*a)->prev = temps;
// 		*a = temps;
// 	}
// 	printf("pa\n");
// 	return;
// }

void	ft_push_a(t_stack **a, t_stack **b)
{
	t_stack	*temp;

	if (!*b)
		return;
	temp = *b;
	if (*b == (*b)->next)
		*b = NULL;
	else
	{
		(*b)->prev->next = (*b)->next;
		(*b)->next->prev = (*b)->prev;
		*b = (*b)->next;
	}
	if (!*a)
	{
		*a = temp;
		temp->next = temp;
		temp->prev = temp;
	}
	else
	{
		temp->next = *a;
		temp->prev = (*a)->prev;
		(*a)->prev->next = temp;
		(*a)->prev = temp;
		*a = temp;
	}

	printf("pa\n");
	return;
}

void	ft_push_b(t_stack **b, t_stack **a)
{
	t_stack	*temp;

	if (!*a)
		return;
	temp = *a;
	if (*a == (*a)->next)
		*a = NULL;
	else
	{
		(*a)->prev->next = (*a)->next;
		(*a)->next->prev = (*a)->prev;
		*a = (*a)->next;
	}
	if (!*b)
	{
		*b = temp;
		temp->next = temp;
		temp->prev = temp;
	}
	else
	{
		temp->next = *b;
		temp->prev = (*b)->prev;
		(*b)->prev->next = temp;
		(*b)->prev = temp;
		*b = temp;
	}
	printf("pb\n");
	return;
}

// void ft_push_a(t_stack **a, t_stack **b)
// {
// 	t_stack *futur_b;

// 	if (!*b) // Si la pile b est vide, il n'y a rien à faire
// 		return;

// 	futur_b = (*b)->next; // Sauvegarde de l'élément suivant dans b
// 	if (futur_b == *b)	  // Si b ne contient qu'un seul élément
// 		futur_b = NULL;
// 	else
// 	{
// 		(*b)->next->prev = (*b)->prev; // Le suivant de b pointe sur le précédent de b
// 		(*b)->prev->next = (*b)->next; // Le précédent de b pointe sur le suivant de b
// 	}

// 	if (!*a) // Si a est vide, on initialise a avec l'élément de b
// 	{
// 		*a = *b;
// 		(*a)->next = *a;
// 		(*a)->prev = *a;
// 	}
// 	else // Sinon on ajoute l'élément en tête de la pile a
// 	{
// 		(*b)->next = *a;
// 		(*b)->prev = (*a)->prev;
// 		(*a)->prev->next = *b;
// 		(*a)->prev = *b;
// 		*a = *b; // Mise à jour de la tête de a
// 	}

// 	*b = futur_b; // Mise à jour de la tête de b
// 	printf("pa\n");
// }
// void ft_push_b(t_stack **b, t_stack **a)
// {
// 	t_stack *futur_a;

// 	if (!*a) // Si la pile a est vide, il n'y a rien à faire
// 		return;

// 	futur_a = (*a)->next; // Sauvegarde de l'élément suivant dans a
// 	if (futur_a == *a)	  // Si a ne contient qu'un seul élément
// 		futur_a = NULL;
// 	else
// 	{
// 		(*a)->next->prev = (*a)->prev; // Le suivant de a pointe sur le précédent de a
// 		(*a)->prev->next = (*a)->next; // Le précédent de a pointe sur le suivant de a
// 	}

// 	if (!*b) // Si b est vide, on initialise b avec l'élément de a
// 	{
// 		*b = *a;
// 		(*b)->next = *b;
// 		(*b)->prev = *b;
// 	}
// 	else // Sinon on ajoute l'élément en tête de la pile b
// 	{
// 		(*a)->next = *b;
// 		(*a)->prev = (*b)->prev;
// 		(*b)->prev->next = *a;
// 		(*b)->prev = *a;
// 		*b = *a; // Mise à jour de la tête de b
// 	}

// 	*a = futur_a; // Mise à jour de la tête de a
// 	printf("pb\n");
// }
