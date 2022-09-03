/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   count_move.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchantro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/02 14:20:28 by tchantro          #+#    #+#             */
/*   Updated: 2022/09/03 15:34:52 by tchantro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void    mini_to_the_top(t_list **a_list)
{
        t_list  *first;
        t_list  *index_zero;
        int     cost_b;

        first = (*a_list);
        index_zero = (*a_list);
        while ((*a_list)!= NULL)
        {
                if ((*a_list)->index == 0)
                {
                        index_zero = (*a_list);
                        cost_b = index_zero->cost_b;
                        break ;
                }
                (*a_list) = (*a_list)->next;
        }
        (*a_list) = first;
        while (cost_b != 0)
        {
                if (cost_b > 0)
                {
                        lst_rotate(a_list, 5);
                        cost_b--;
                }
                else
                {
                        lst_reverse_rotate(a_list, 7);
                        cost_b++;
                }
        }
}


t_list	*next_push_a(t_list **b_list)
{
	t_list	*first;
	t_list	*save;
	int	nbr_save;
	int	nbr;

	save = (*b_list);
	first = (*b_list);
	(*b_list) = (*b_list)->next;
	while ((*b_list) != NULL)
	{
		nbr_save = abs(save->cost_a) + abs(save->cost_b);
		nbr = abs((*b_list)->cost_a) + abs((*b_list)->cost_b);
		if (nbr < nbr_save)
			save = (*b_list);
		(*b_list) = (*b_list)->next;
	}
	(*b_list) = first;
	return (save);
}

void	second_algo_part(t_list **a_list, t_list **b_list)
{
	int	cost_a;
	int	cost_b;
	t_list	*push;

	while ((*b_list) != NULL)
	{
		push = next_push_a(b_list);
		cost_a = push->cost_a;
		cost_b = push->cost_b;
		
		if (cost_a  > 0 && cost_b > 0)
		{
			while (cost_a != 0 && cost_b != 0)
			{
				lst_rotate(a_list, 0);
				lst_rotate(b_list, 10);
				cost_a--;
				cost_b--;
			}
		}
		else if (cost_a < 0 && cost_b < 0)
		{
			while (cost_a != 0 && cost_b != 0)
			{
				lst_reverse_rotate(a_list, 0);
				lst_reverse_rotate(b_list, 11);
				cost_a++;
				cost_b++;
			}
		}
		while (cost_a != 0)
		{
			if (cost_a > 0)
			{
				lst_rotate(a_list, 5);
				cost_a--;
			}
			else
			{
				lst_reverse_rotate(a_list, 7);
				cost_a++;
			}
		}
		while (cost_b != 0)
		{
			if (cost_b > 0)
			{
				lst_rotate(b_list, 6);
				cost_b--;
			}
			else
			{
				lst_reverse_rotate(b_list, 8);
				cost_b++;
			}
		}
		lst_push(a_list, b_list, 3);
	}
}

/*void	mini_to_the_top(t_list **a_list)
{
	t_list	*first;
	t_list	*index_zero;
	int	cost_b;

	first = (*a_list);
	index_zero = (*a_list);
	while ((*a_list)!= NULL)
	{
		if ((*a_list)->index == 0)
		{
			index_zero = (*a_list);
			cost_b = index_zero->cost_b;
			break ;
		}
		(*a_list) = (*a_list)->next;
	}
	(*a_list) = first;
	while (cost_b != 0)
	{
		if (cost_b > 0)
		{
			lst_rotate(a_list, 5);
			cost_b--;
		}
		else
		{
			lst_reverse_rotate(a_list, 7);
			cost_b++;
		}
	}
}*/
