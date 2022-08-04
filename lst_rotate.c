/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_rotate.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchantro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/01 18:41:05 by tchantro          #+#    #+#             */
/*   Updated: 2022/08/05 01:12:35 by tchantro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	lst_rotate(t_list *list)
{
	t_list	*tmp;

	tmp = list;
	ft_lstdelone(list); 
	ft_lstadd_back(&list, ft_lstnew(tmp->content));
}
