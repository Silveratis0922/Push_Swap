/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   delete_lst.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchantro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/15 09:36:03 by tchantro          #+#    #+#             */
/*   Updated: 2022/09/15 09:56:39 by tchantro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	delete_lst(t_list **a_list)
{
	t_list	*tmp;

	while ((*a_list) != NULL)
	{
		tmp = (*a_list)->next;
		free(*a_list);
		(*a_list) = tmp;
	}
	(*a_list) = NULL;
}
