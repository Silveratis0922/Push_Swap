/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_list.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchantro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/18 16:20:56 by tchantro          #+#    #+#             */
/*   Updated: 2022/09/01 21:23:45 by tchantro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_swap(int *tab1, int *tab2)
{
	int	temp;

	temp = *tab1;
	*tab1 = *tab2;
	*tab2 = temp;
}

void	ft_sort_int_tab(int *tab, int size)
{
	int	i;
	int	j;
	int	min_idx;

	i = 0;
	while (i < size - 1)
	{
		min_idx = i;
		j = i + 1;
		while (j < size)
		{
			if (tab[j] < tab[min_idx])
				min_idx = j;
			j++;
		}
		ft_swap(&tab[min_idx], &tab[i]);
		i++;
	}
}

int	*ft_sort_list(t_list **list)
{
	int		*tab;
	int		i;
	int		size;
	t_list	*first;

	i = 0;
	first = (*list);
	size = ft_lstsize(*list);
	tab = malloc(sizeof (int) * size);
	if (!tab)
		return (NULL);
	while ((*list))
	{
		tab[i] = (*list)->content;
		i++;
		(*list) = (*list)->next;
	}
	ft_sort_int_tab(tab, size);
	(*list) = first;
	return (tab);
}
