/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstswap.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchantro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/01 18:36:24 by tchantro          #+#    #+#             */
/*   Updated: 2022/08/05 07:25:23 by tchantro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_lstswap(t_list *list)
{
	t_list *second;
	int	tmp;

	if (ft_lstsize(list) > 1)
	{
		second = list->next;
		tmp = list->content;
		list->content = second->content;
		second->content = tmp; 
	}
	else
		return ;
}
