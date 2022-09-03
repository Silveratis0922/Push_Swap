/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchantro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/04 00:43:12 by tchantro          #+#    #+#             */
/*   Updated: 2022/09/03 15:33:15 by tchantro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include <stdio.h>
# include <stdlib.h>
# include <stddef.h>
# include <unistd.h>
# include "libft.h"

char	**error_test(char **str);
void	lst_rotate(t_list **list, int write);
void	lst_swap(t_list **list, int write);
void	lst_reverse_rotate(t_list **list, int write);
void	lst_push(t_list **output, t_list **input, int write);
int		verif_overflow(char ***str, t_list **list);
int		main(int argc, char **argv);
int		*ft_sort_list(t_list **list);
void	only_three(t_list **list);
int		test_algo(t_list **a_list, t_list **b_list);
void	struct_pos(t_list **list);
void	struct_t_pos(t_list **a_list, t_list **b_list);
void	struct_t_pos_bis(t_list **a_list, t_list **b_list);
void	write_action(int moves);
void	struct_cost_b(t_list **list);
void	struct_cost_a(t_list **a_list, t_list **b_list);
t_list	*next_push_a(t_list **b_list);
void    second_algo_part(t_list **a_list, t_list **b_list);
void    mini_to_the_top(t_list **a_list);

#endif
