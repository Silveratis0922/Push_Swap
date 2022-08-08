/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_push.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchantro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/08 15:21:03 by tchantro          #+#    #+#             */
/*   Updated: 2022/08/08 15:51:43 by tchantro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	lst_push(t_list **output, t_list **input)
{
	t_list	*first;

	first = *output;
	if ((*input) == NULL)
	{
		*input = ft_lstnew(first->content);
	}
	else
	{
		ft_lstadd_front(input, ft_lstnew(first->content));
	}
	first = first->next;
	free(*output);
	*output = first;
}
