/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchantro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/04 00:43:12 by tchantro          #+#    #+#             */
/*   Updated: 2022/09/15 11:47:21 by tchantro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include <stdio.h>
# include <stdlib.h>
# include <stddef.h>
# include <unistd.h>
# include "libft.h"

void	lst_rotate(t_list **list, int write);
void	lst_swap(t_list **list, int write);
void	lst_reverse_rotate(t_list **list, int write);
void	lst_push(t_list **output, t_list **input, int write);
int		all_parsing(char *str, t_list **list);
int		main(int argc, char **argv);
int		*ft_sort_list(t_list **list);
void	only_three(t_list **list);
int		first_algo(t_list **a_list, t_list **b_list);
void	struct_pos(t_list **list);
void	struct_t_pos(t_list **a_list, t_list **b_list);
void	struct_t_pos_bis(t_list **a_list, t_list **b_list);
void	write_action(int moves);
void	struct_cost_b(t_list **list);
void	struct_cost_a(t_list **a_list, t_list **b_list);
t_list	*next_push_a(t_list **b_list);
void	mini_to_the_top(t_list **a_list);
int		already_ordered(t_list **a_list);
void	delete_lst(t_list **a_list);
void	final_algo(t_list **a_list, t_list **b_list);
void	move_min_on_top(t_list **a_list, int cost_b);

#endif
