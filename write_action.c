/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   write_action.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchantro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/29 16:18:26 by tchantro          #+#    #+#             */
/*   Updated: 2022/09/01 14:54:05 by tchantro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	write_action(int move)
{
	if (move == 0)
		return ;
	else if (move == 1)
		write(1, "sa\n", 3);
	else if (move == 2)
		write(1, "sb\n", 3);
	else if (move == 3)
		write(1, "pa\n", 3);
	else if (move == 4)
		write(1, "pb\n", 3);
	else if (move == 5)
		write(1, "ra\n", 3);
	else if (move == 6)
		write(1, "rb\n", 3);
	else if (move == 7)
		write(1, "rra\n", 4);
	else if (move == 8)
		write(1, "rrb\n", 4);
	else if (move == 9)
		write(1, "ss\n", 3);
	else if (move == 10)
		write(1, "rr\n", 3);
	else if (move == 11)
		write(1, "rrr\n", 4);
}
