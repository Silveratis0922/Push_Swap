/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstswap.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchantro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/01 18:36:24 by tchantro          #+#    #+#             */
/*   Updated: 2022/08/05 01:08:55 by tchantro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_lstswap(t_list *list)
{
	int_list *second;
	int_list	*third;
	int_list	*tmp;

	if (ft_lstsize(list) > 1)
	{
		second = list->next;
		third = second->next;
		tmp = list;
		list = second;
		second = tmp;
		second->next = third;
	}
	else
		return ;
}
