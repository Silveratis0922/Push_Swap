/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchantro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/04 00:43:12 by tchantro          #+#    #+#             */
/*   Updated: 2022/08/08 15:35:12 by tchantro         ###   ########.fr       */
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
void	lst_rotate(t_list **list);
void	ft_lstswap(t_list *list);
void    lst_reverse_rotate(t_list **list);
void    lst_push(t_list **output, t_list **input);

#endif
