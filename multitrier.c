/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   multitrier.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: peli <peli@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/14 11:03:44 by peli              #+#    #+#             */
/*   Updated: 2024/08/28 11:09:11 by peli             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
// int	whereisposition(t_stack *a, t_stack *b, int position)
// {
// 	int	i;
// 	t_stack *push_stack;

// 	push_stack = a;
// 	while (position != 0)
// 	{
// 		push_stack = push_stack->next;
// 		position--;
// 	}
	
// 	while (temps)
// 	{
//         if (temps->value == value)
//             return i;
//         temps = temps->next;
//         i++;
//     }
//     // If the value isn't found, return -1 or an indication that the value doesn't exist.
//     return -1;
// }
//But : Calculer la position optimale pour 
//insérer un élément de b dans a en comptant les coups nécessaires.
// int	ft_calculcoup(t_stack **a, t_stack **b, int len_itself, int len_enface)
// {
// 	int position;
// 	int	move_a;
// 	int move_b;
// 	int	i;
// 	t_stack	*temps_a;

// 	position = 0;
// 	temps_a = *a;
// 	i = 0;
// 	move_a = ft_howmany_coup(temps_a, *b, len_enface);
// 	while (temps_a->value != (*a)->value)
// 	{
// 		temps_a =  temps_a->next;
// 		i++;
// 		if (i >= len_itself / 2)
// 			move_b = ft_howmany_coup(temps_a, *b, len_enface) + (len_itself - i);
// 		else
// 			move_b = ft_howmany_coup(temps_a, *b, len_enface) + i;
// 		if (move_b < move_a) 
// 		{
//             move_a = move_b;
//             position = i;  // Update position to current index i
//         }
// 	}
// 	return(position); // ici est la position de a;
// }

int	find_max(t_stack *stack)
{
	int	max;
	t_stack *start = stack;

	if (!stack)
		return INT_MIN;
	max = stack->value;
	stack = stack->next;
	while (stack != start)
	{
		if (max < stack->value)
			max = stack->value;
		stack = stack->next;
	}
	return (max);
}
//But : Calculer le nombre de rotations nécessaires pour 
//when the top element of stack a is pushed onto b, it ends up in the appropriate sorted position.
int ft_howmany_coup(t_stack *a, t_stack *b, int len_itself)
{
    int rotatetime = 0;
    int min, max;
    t_stack *temps;

	if (!b)
        return 0;

    // Find the minimum and maximum values in stack b
    temps = b;
    min = find_min(temps);
    max = find_max(temps);

    // Case 1: If the value in 'a' is smaller than the minimum or larger than the maximum in 'b'
    if (a->value < min || a->value > max)
    {
        // Rotate until the minimum value is on top of 'b'
        while (temps->value != min)
        {
            temps = temps->next;
            rotatetime++;
        }
    }
    else
    {
        if (a->value > temps->value)
        {
            while (a->value > temps->value)
            {
                rotatetime++;
                temps = temps->next;
            }
        }
        else
        {
            while (a->value < temps->prev->value)
            {
                rotatetime++;
                temps = temps->prev;
            }
            // Convert rotations needed to the reverse rotations equivalent
			rotatetime = len_itself -rotatetime;
        }
    }
	// printf ("totate time : %d\n", rotatetime);
    return rotatetime; // Return the number of rotations needed
}

void	execute_individual_moves(t_stack **a, t_stack **b, int position_a, int position_b, int lena, int lenb)
{
	while (position_a > 0 || position_b > 0) 
	{	
		// printf("ooooooooooooooooooooooooo\n");
		if (position_a > 0 && position_a != lena) 
		{
			if (position_a <= lena / 2) 
			{
				while (position_a != 0)
				{					
					ft_rotate_a(a);
					position_a--;
				}
			} 
			else 
			{
				while (position_a != lena)
				{
					ft_reverse_rotate_a(a);
					position_a++;
				}
			}
		}
		if (position_b > 0 && position_b != lenb) 
		{
			if (position_b <= lenb / 2) 
			{
				while (position_b != 0)
				{					
					ft_rotate_b(b);
					position_b--;
				}
			} 
			else 
			{
				while (position_b != lenb)
				{
					ft_reverse_rotate_b(b);
					position_b++;
				}
			}
		}
		break;
	}
}



void execute_optimized_moves(t_stack **a, t_stack **b, int position_a, int position_b, int lena, int lenb) 
{
	while (position_a > 0 && position_b > 0) 
	{
		// printf ("position_a is : %d\n", position_a);
		// printf ("position_b is : %d\n", position_b);
		// printf ("lena is : %d\n", lena);
		// printf ("lenb is : %d\n", lenb);
		if (position_a <= lena / 2 && position_b <= lenb / 2) 
		{
			while(position_a != 0 && position_b != 0)
			{
				ft_rotate_ab(a, b);
				position_a--;
				position_b--;
			}
			break;
		} 
		else if (position_a > lena / 2 && position_b > lenb / 2) 
		{
			while (position_a != lena && position_b != lenb)
			{
				ft_reverse_rotate_ab(a, b);
				position_a++;
				position_b++;
			}
			break;
		} 
		else 
		{
			break;
		}
	}
	// printf("!Stack A :\n");
	// print_stack(*a);
	// printf("\n!Stack B :\n");
	// print_stack(*b);
	execute_individual_moves(a, b, position_a, position_b, lena, lenb);
}



int	ft_where_stack(t_stack *a, t_stack *push)
{
	int i;
	t_stack *temps;

	i = 0;
	temps = a;
	if (!a || !push)
		return -1;
	// printf ("temps id :\n");
	// print_stack(temps);
	while (temps)
	{
		if (temps->value == push->value)
			return i;
		temps = temps->next;
		i++;
		// printf ("temps id :\n");
		// print_stack(temps);
		// printf ("Last position a is: %d\n", i);
	}
	return (-1);
}
t_stack	*ft_pickyou(t_stack **a, t_stack **b, int len_a, int len_b)
{
	t_stack *push;
	t_stack *temps;
	int	move_total;
	int	move_a;
	int	move_b;

	push = *a;
	temps = *a;
	move_a = 0;
	move_b = ft_howmany_coup(push, *b, len_b);
	if (move_b > len_b / 2)
		move_b = len_b -move_b;
	move_total = move_a + move_b;
	while (temps->next != *a)
	{
		// printf ("move_a is : %d\n", move_a);
		// printf ("move_b is : %d\n", move_b);
		move_a++;
		temps = temps->next;
		move_b = ft_howmany_coup(temps, *b, len_b);
		if (move_b > len_b / 2)
			move_b = len_b -move_b;
		int current_total = move_a + move_b;
        if (move_a > len_a / 2) // Check if it's cheaper to rotate in the opposite direction
            current_total = (len_a - move_a) + move_b;
        if (current_total < move_total) // Check if current element has a cheaper move
        {
            push = temps;
            move_total = current_total;
        }
		// printf ("Push is :\n");
		// print_stack(push);
    }
	return (push);
}
void multitrier(t_stack **a, t_stack **b, int len)
{
    int len_a;
    int len_b;
    int position_a;
	int	position_b;
	t_stack	*push;

    len_a = len;
    ft_push_b(b, a);
    if ((*a)->value < (*b)->value) 
	{
        ft_push_b(b, a);
        ft_swap_b(b);
    } 
	else 
		ft_push_b(b, a);
    len_a = len - 2;
    len_b = 2;
    while (len_a > 3)//len_a > len / 3
    {
		// printf("??Stack A :\n");
		// print_stack(*a);
		// printf("\nStack B :\n");
		// print_stack(*b);	
		push = ft_pickyou(a, b, len_a, len_b);
		// printf ("push is : %d\n", push->value);
		position_a = ft_where_stack(*a, push);
		position_b = ft_howmany_coup(push, *b, len_b);
		// printf ("position a is : %d\n", position_a);
		// printf ("position b  is : %d\n", position_b);
		// Check if rotations are needed
		// if ((position_a > 0 || position_b > 0) && (position_a != len_a && position_b != len_b))
		// {
		execute_optimized_moves(a, b, position_a, position_b, len_a, len_b);
		// }
		// else
		// 	execute_individual_moves(a, b, position_a, position_b, len_a, len_b);
		ft_push_b(b, a);
		len_a--;
		len_b++;
		// printf("??Stack A :\n");
		// print_stack(*a);
		// printf("\nStack B :\n");
		// print_stack(*b);	
	}
	len_b = len - len_a;
	trier_trois(a);
	//Move elements back from b to a
	// printf("ooooooooooooooooooooooooo\n");
	// printf("??Stack A :\n");
	// print_stack(*a);
	// printf("\nStack B :\n");
	// print_stack(*b);
	while (*b)
	{
		//  printf("AAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAA\n");
		push = ft_pickyou(b, a, len_b, len_a);
		// printf("push b to a est :\n");
		// print_stack(push);
		position_b = ft_where_stack(*b, push);
		position_a = ft_howmany_coup(push, *a, len_a);
		// printf ("\nposition b is : %d\n", position_a);
		// printf ("position a  is : %d\n", position_b);
		// Check if rotations are needed
		if (position_b > 0 || position_a > 0)
		{
			execute_optimized_moves(a, b, position_a, position_b, len_a, len_b);
		}
		else
		{
			execute_individual_moves(a, b, position_a, position_b, len_a, len_b);
		}
		ft_push_a(a, b);
		len_a++;
		len_b--;
		// printf ("ooooooooooooooooo\n");
	}
	ft_triera(a, len);
	// printf("Stack A :\n");
	// print_stack(*a);
	// printf("\nStack B :\n");
	// print_stack(*b);
	return;
}

// void multitrier(t_stack **a, t_stack **b, int len)
// {
//     int len_a;
//     int len_b;
//     int position_a, position_b;

//     len_a = len;
//     ft_push_b(b, a);
//     if ((*a)->value < (*b)->value)  // Correction ici pour comparer les valeurs
//     {
//         ft_push_b(b, a);
//         ft_swap_b(b);
//     }
// 	else
// 	    ft_push_b(b, a);
//     len_a = len - 2;
// 	len_b = 2;

//     // Trier en utilisant les rotations optimisées
//     while (len_a > len / 3)
//     {
//         position_a = ft_calculcoup(a, b, len_a, len_b); // position dans a
//         position_b = whereisposition(*b, (*b)->value);    // Calculer position_b
        
// 		printf ("position a is : %d", position_a);
// 		printf ("position b  is : %d", position_b);
//         execute_optimized_moves(a, b, &position_a, &position_b, len_a, len_b);
        
//         ft_push_b(b, a);
//         len_a--;
//     }

//     len_b = len - len_a;

//     // Remettre les éléments de b dans a
//     while (*b)
//     {
//         position_b = ft_calculcoup(a,b, len_b, len_a); // position dans b
//         position_a = whereisposition(*a, (*a)->value);    // Calculer position_a
        
//         execute_optimized_moves(a, b, &position_a, &position_b, len_a, len_b);

//         ft_push_a(a, b);
//         len_b--;
//     }

//     return;
// }

void	ft_triera(t_stack **a, int len)
{
	int	min;
	int position;
	t_stack	*temps;

	min = find_min(*a);
	temps = *a;
	position = 0;
	while (temps->value != min)
	{
		temps = temps->next;
		position++;
	}
	if(position > len/2)
	{
		while ((*a)->value != min)
			ft_reverse_rotate_a(a);
	}
	else
	{
		while ((*a)->value != min)
			ft_rotate_a(a);
	}
	return;
}
// void	multitrier(t_stack **a, t_stack **b, int len) la deuxime version
// {
// 	int lena = len, lenb = 0;

// 	while (*b) {
// 		int max_b = find_max(*b);
// 		int min_a = find_min(*a);
// 		int position_b = whereisposition(*b, max_b);
// 		int position_a = whereisposition(*a, min_a);

// 		// Boucle pour pousser les éléments de `b` vers `a` tant que le max de `b` est supérieur au min de `a`
// 		while (min_a < max_b) {
// 			execute_optimized_moves(a, b, &position_a, &position_b, lena, lenb);

// 			ft_push_a(a, b); // Pousse de `b` vers `a`
// 			lenb--;
// 			lena++;
// 			max_b = find_max(*b); // Recalculer max et min après chaque opération
// 			min_a = find_min(*a);
// 			position_b = whereisposition(*b, max_b);
// 			position_a = whereisposition(*a, min_a);
// 		}

// 		// Gestion des cas où `min_a` n'est pas au sommet de `a` ou `max_b` n'est pas au sommet de `b`
// 		if ((*a)->value != min_a || (*b)->value != max_b) {
// 			execute_optimized_moves(a, b, &position_a, &position_b, lena, lenb);
// 		}

// 		ft_push_a(a, b);  // Pousse de `b` vers `a`
// 		lena++;
// 	}

// 	// Insérer les éléments de `b` à `a` dans la position correcte
// 	insert_elements_back_to_a(a, b, lena);

// 	// Finaliser le tri en inversant les rotations si nécessaire
// 	while (lena > 1) {
// 		ft_reverse_rotate_a(a);
// 		ft_push_b(b, a);
// 		lena--;
// 	}

// 	lena = len - lenb - 1; // Mise à jour de la longueur après les opérations
// 	insert_elements_back_to_a(a, b, lena);
// 	ft_triera(a,len);
// }

// void execute_individual_moves(t_stack **a, t_stack **b, int *position_a, int *position_b, int lena, int lenb)
// {
// 	if (*position_a > 0) {
// 		while (*position_a > 0) {
// 			if (*position_a < lena/2) {
// 				ft_rotate_a(a);
// 			} else {
// 				ft_reverse_rotate_a(a);
// 			}
// 			(*position_a)--;
// 		}
// 	}

// 	if (*position_b > 0) {
// 		while (*position_b > 0) {
// 			if (*position_b < lenb/2) {
// 				ft_rotate_b(b);
// 			} else {
// 				ft_reverse_rotate_b(b);
// 			}
// 			(*position_b)--;
// 		}
// 	}
// }
// // Fonction pour exécuter des mouvements optimisés
// void execute_optimized_moves(t_stack **a, t_stack **b, int *position_a, int *position_b, int lena, int lenb) 
// {
// 	if (*position_a < lena/2 && *position_b < lenb/2) {
// 		// Utilisez `rr` et `rrr` pour minimiser les opérations
// 		while (*position_a > 0 && *position_b > 0) {
// 			ft_reverse_rotate_ab(a, b);
// 			(*position_a)--;
// 			(*position_b)--;
// 		}
// 	} else {
// 		while (*position_a > 0 && *position_b > 0) {
// 			ft_rotate_ab(a, b);
// 			(*position_a)--;
// 			(*position_b)--;
// 		}
// 	}

//     execute_individual_moves(a, b, position_a, position_b, lena, lenb);
// }

// // Fonction pour exécuter les mouvements restants individuellement

// // Fonction pour insérer les éléments de `b` à `a`
// void insert_elements_back_to_a(t_stack **a, t_stack **b, int lena) 
// {
// 	while (*b) {
// 		int position = find_position(*a, *b, lena);
// 		if (position < lena / 2) {
// 			while (position > 0) {
// 				ft_rotate_a(a);
// 				position--;
// 			}
// 		} else {
// 			position = lena - position;
// 			while (position > 0) {
// 				ft_reverse_rotate_a(a);
// 				position--;
// 			}
// 		}
// 		ft_push_a(a, b);
// 		lena++;
// 	}
// }

// void insert_elements_back_to_a(t_stack **a, t_stack **b, int lena) 
// {
// 	while (*b) {
// 		int position = find_position(*a, *b, lena);

// 		// Choisissez la direction de rotation optimale
// 		if (position <= lena / 2) {
// 			while (position-- > 0) {
// 				ft_rotate_a(a);
// 			}
// 		} else {
// 			while (position++ < lena) {
// 				ft_reverse_rotate_a(a);
// 			}
// 		}
// 		ft_push_a(a, b);
// 		lena++;
// 	}
// }

// void finalize_sort(t_stack **a, int lena) {
//     // Amener le plus petit élément en haut
//     int min_position = whereisposition(*a, find_min(*a));
//     if (min_position <= lena / 2) {
//         while (min_position-- > 0) {
//             ft_rotate_a(a);
//         }
//     } else {
//         while (min_position++ < lena) {
//             ft_reverse_rotate_a(a);
//         }
//     }
// }


// void multitrier(t_stack **a, t_stack **b, int len) 
// {
// 	int lena = len, lenb = 0;

// 	while (*b) {
// 		int max_b = find_max(*b);
// 		int min_a = find_min(*a);
// 		int position_b = whereisposition(*b, max_b);
// 		int position_a = whereisposition(*a, min_a);

// 		while (min_a < max_b) {
// 			execute_optimized_moves(a, b, &position_a, &position_b, lena, lenb);

// 			ft_push_a(a, b);
// 			lenb--;
// 			lena++;
// 			max_b = find_max(*b);
// 			min_a = find_min(*a);
// 			position_b = whereisposition(*b, max_b);
// 			position_a = whereisposition(*a, min_a);
// 		}

// 		if ((*a)->value != min_a || (*b)->value != max_b) {
// 			execute_optimized_moves(a, b, &position_a, &position_b, lena, lenb);
// 		}

// 		ft_push_a(a, b);
// 		lena++;
// 	}

// 	insert_elements_back_to_a(a, b, lena);

// 	finalize_sort(a, lena);
// 	return;
// }

// Fonctions auxiliaires comme whereisposition, find_max, find_min restent inchangées

// void	multitrier(t_stack **a, t_stack **b, int len)
// {
// 	int	i;

// 	i = 0;
// 	while (i < len / 2)
// 	{
// 		if ((*a)->value > (*a)->next->value) 
// 		{
// 			ft_swap_a(a);
// 		}
// 		if ((*a)->value > (*a)->prev->value) 
// 		{
// 			ft_reverse_rotate_a(a);
// 		}
// 		else
// 		{
// 			ft_rotate_a(a);
// 		}
// 		ft_push_b(b, a);
// 		i++;
// 	}
// 	int lenb = i;
// 	int	lena = len - lenb;// c'est pas le vrai longeur de a quand len = ex 9 11 13 etc.
// 	printf("Stack A :\n");
// 	print_stack(*a);
// 	printf("\nStack B :\n");
// 	print_stack(*b);
// 	while (*b)
// 	{
// 		int max_b = find_max(*b);
// 		int	min_a = find_min(*a);
// 		printf ("min a is : %d\n", min_a);
// 		printf ("max b is : %d\n", max_b);
// 		int position_b = whereisposition(*b, max_b);
// 		printf("Je suis la\n");
// 		fflush(stdout);
// 		int	position_a = whereisposition(*a, min_a);
// 		printf("Je suis la\n");
// 		fflush(stdout);
// 		while (min_a < max_b)
// 		{
// 			if (position_a < lena/2 && position_b < lenb/2)
// 			{
// 				while (position_a != 0 || position_b != 0)
// 				{
// 					ft_reverse_rotate_ab(a, b);
// 					position_a--;
// 					position_b--;
// 				}
// 				if (position_a == 0)
// 				{
// 					if (position_b < lenb/2)
// 					{
// 						while (position_b != 0)
// 							ft_rotate_b(b);
// 					}
// 					else
// 					{
// 						while (position_b != 0)
// 							ft_reverse_rotate_b(b);
// 					}
// 				}
// 				else
// 				{
// 					if (position_a < lena/2)
// 					{
// 						while (position_a != 0)
// 							ft_rotate_a(a);
// 					}
// 					else 
// 					{
// 						while (position_a != 0)
// 							ft_reverse_rotate_a(a);
// 					}
// 				}
// 			}
// 			else // ici je peux optimiser plus?
// 			{
// 				while (position_a != 0 || position_b != 0)
// 				{
// 					ft_rotate_ab(a, b);
// 					position_a--;
// 					position_b--;
// 				}
// 				if (position_a == 0)
// 				{
// 					if (position_b < lenb/2)
// 					{
// 						while (position_b != 0)
// 							ft_rotate_b(b);
// 					}
// 					else
// 					{
// 						while (position_b != 0)
// 							ft_reverse_rotate_b(b);
// 					}
// 				}
// 				else
// 				{
// 					if (position_a < lena/2)
// 					{
// 						while (position_a != 0)
// 							ft_rotate_a(a);
// 					}
// 					else 
// 					{
// 						while (position_a != 0)
// 							ft_reverse_rotate_a(a);
// 					}
// 				}
// 			}
// 			ft_push_a(a, b); // choisir pa ou pb? on peux tester apres;
// 			lenb--;
// 			lena++;
// 			max_b = find_max(*b);
// 			min_a = find_min(*a);
// 			position_b = whereisposition(*b, max_b);
// 			position_a = whereisposition(*a, min_a);
// 		}
// 		if ((*a)->value != min_a || (*b)->value != max_b)
// 		{
// 			if (position_a < lena/2 && position_b < lenb/2)
// 			{
// 				while (position_a != 0 || position_b != 0)
// 				{
// 					ft_reverse_rotate_ab(a, b);
// 					position_a--;
// 					position_b--;
// 				}
// 				if (position_a == 0)
// 				{
// 					if (position_b < lenb/2)
// 					{
// 						while (position_b != 0)
// 							ft_rotate_b(b);
// 					}
// 					else
// 					{
// 						while (position_b != 0)
// 							ft_reverse_rotate_b(b);
// 					}
// 				}
// 				else
// 				{
// 					if (position_a < lena/2)
// 					{
// 						while (position_a != 0)
// 							ft_rotate_a(a);
// 					}
// 					else 
// 					{
// 						while (position_a != 0)
// 							ft_reverse_rotate_a(a);
// 					}
// 				}
// 			}
// 			else // ici je peux optimiser plus?
// 			{
// 				while (position_a != 0 || position_b != 0)
// 				{
// 					ft_rotate_ab(a, b);
// 					position_a--;
// 					position_b--;
// 				}
// 				if (position_a == 0)
// 				{
// 					if (position_b < lenb/2)
// 					{
// 						while (position_b != 0)
// 							ft_rotate_b(b);
// 					}
// 					else
// 					{
// 						while (position_b != 0)
// 							ft_reverse_rotate_b(b);
// 					}
// 				}
// 				else
// 				{
// 					if (position_a < lena/2)
// 					{
// 						while (position_a != 0)
// 							ft_rotate_a(a);
// 					}
// 					else 
// 					{
// 						while (position_a != 0)
// 							ft_reverse_rotate_a(a);
// 					}
// 				}
// 			}
// 		}
// 		ft_push_a(a, b);
// 		lena++;
// 		while (*b)
// 		{
// 			int position = find_position (*a, *b, lena);
// 			if (position < lena / 2)
// 			{
// 				while (position > 0)
// 				{
// 					ft_rotate_a(a);
// 					position--;
// 				}
// 			}
// 			else
// 			{
// 				position = lena - position;
// 				while (position > 0)
// 				{
// 					ft_reverse_rotate_a(a);
// 					position--;
// 				}
// 			}
// 			ft_push_a(a, b);
// 			lena++;
// 		}
// 		while(lena - 1 != 0)
// 		{
// 			ft_reverse_rotate_a(a);
// 			ft_push_b(b, a);
// 			lena--;
// 		}
// 		lena = len - lenb - 1;
// 		while(*b)
// 		{
// 			int position = find_position (*a, *b, lena);
// 			if (position < lena / 2)
// 			{
// 				while (position > 0)
// 				{
// 					ft_rotate_a(a);
// 					position--;
// 				}
// 			}
// 			else
// 			{
// 				position = lena - position;
// 				while (position > 0)
// 				{
// 					ft_reverse_rotate_a(a);
// 					position--;
// 				}
// 			}
// 			ft_push_a(a, b);
// 			lena++;
// 		}
// 	}
// 	return;
// }
// void	multitrier(t_stack **a, t_stack **b, int len)
// {
// 	int	lena;
// 	int	position;
// 	int	i;
	
// 	i = 0;
// 	while (i != len - 3)
// 	{
// 		ft_push_b(b, a);
// 		i++;	
// 	}
// 	trier_trois(a);
// 	lena = 3;
// 	while (*b)
// 	{
// 		position = find_position (*a, *b, lena);
// 		if (position < lena / 2)
// 		{
// 			while (position > 0)
// 			{
// 				ft_rotate_a(a);
// 				position--;
// 			}
// 		}
// 		else
// 		{
// 			position = lena - position;
// 			while (position > 0)
// 			{
// 				ft_reverse_rotate_a(a);
// 				position--;
// 			}
// 		}
	
// 		ft_push_a(a, b);
// 		lena++;
// 		// printf("Stack A :\n");
// 		// print_stack(*a	//if (len <= 0 || !stack));
// 		// printf("\nStack B :\n");
// 		// print_stack(*b);
// 	}
// 	ft_triera(a,lena);
// 	return ;
// }

//./push_swap 4 2 6 3 67 125 

	// while (*b)
	// {
	// 	int position = find_position (a, b, lena);//il faut verifier ici;
	// 	if(position = 0)
			
		
	// }
	
	// while (*a)
	// {
	// 	if((*a)->value < (*b)->value || (*a)->value > (*b)->prev->value)
	// 	{
	// 		ft_push_b(*b, *a);
	// 		if((*b)->value > (*b)->prev->value)
	// 			ft_rotate_b(*b);
	// 	}	
	// 	else
	// 	{
	// 		if((*a)->next->value < (*b)->value || (*a)->next->value > (*b)->prev ->value)
	// 		{
	// 			ft_swap_a(*a); // pas sur sa ou ra
	// 			ft_push_b(*b, *a);
	// 			if((*b)->value > (*b)->prev->value)
	// 				ft_rotate_b(*b);
	// 		}
	// 		else if((*a)->prev->value < (*b)->value || (*a)->prev->value > (*a)->prev->value)
	// 		{
	// 			ft_reverse_rotate_a(*a);
	// 			ft_push_b(*b, *a);
	// 			if((*b)->value > (*b)->prev->value)
	// 				ft_rotate_b(*b);
	// 		}
	// 	}
	// 	lenb++;
	// 	if (find_position((*a)->value, b) > )
		
	// }
	
	
	// while (i < len / 2)
	// {
	// 	if((*a)->value = )char ft_rotate(t_stack **stack)
	// 	i++;
	// }
	// *b = NULL;
	// left = *a;
	// right = *a;
	// while (i < len)
	// {
	// 	left = left->prev;
	// 	printf ("left stack is : %d\n", left->value);
	// 	i++;
	// }
	// i = 0;
	// while (i < len)
	// {
	// 	printf ("right stack is : %d\n", right->value);
	// 	right = right->next;
	// 	i++;
	// }





	