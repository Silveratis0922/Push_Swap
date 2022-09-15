/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   final_algo.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchantro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/15 11:22:48 by tchantro          #+#    #+#             */
/*   Updated: 2022/09/15 16:20:54 by tchantro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_list	*rr_cond(t_list **a_list, t_list **b_list, t_list *push)
{
	while (push->cost_a > 0 && push->cost_b > 0)
	{
		lst_rotate(a_list, 0);
		lst_rotate(b_list, 10);
		push->cost_a--;
	}
	return (push);
}

t_list	*rrr_cond(t_list **a_list, t_list **b_list, t_list *push)
{
	while (push->cost_a < 0 && push->cost_b < 0)
	{
		lst_reverse_rotate(a_list, 0);
		lst_reverse_rotate(b_list, 11);
		push->cost_a++;
	}
	return (push);
}

t_list	*ra_or_rra(t_list **a_list, t_list *push)
{
	while (push->cost_a != 0)
	{
		if (push->cost_a > 0)
		{
			lst_rotate(a_list, 5);
			push->cost_a--;
		}
		else
		{
			lst_reverse_rotate(a_list, 7);
			push->cost_a++;
		}
	}
	return (push);
}

t_list	*rb_or_rrb(t_list **b_list, t_list *push)
{
	while (push->cost_b != 0)
	{
		if (push->cost_b > 0)
			lst_rotate(b_list, 6);
		else
			lst_reverse_rotate(b_list, 8);
	}
	return (push);
}

void	final_algo(t_list **a_list, t_list **b_list)
{
	t_list	*push;

	while ((*b_list) != NULL)
	{
		push = next_push_a(b_list);
		rr_cond(a_list, b_list, push);
		rrr_cond(a_list, b_list, push);
		ra_or_rra(a_list, push);
		rb_or_rrb(b_list, push);
		lst_push(a_list, b_list, 3);
	}
}
