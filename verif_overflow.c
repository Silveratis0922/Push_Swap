/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   verif_overflow.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchantro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/15 14:02:08 by tchantro          #+#    #+#             */
/*   Updated: 2022/09/01 21:20:02 by tchantro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	verif_size_line(char *str)
{
	int	i;
	int	j;
	int	len;

	i = 0;
	j = 0;
	len = 0;
	if (str[i] == '-')
	{
		i++;
		j++;
		len++;
	}
	while (str[i] == '0')
		i++;
	while (str[i])
	{
		i++;
		len++;
	}
	if (j == len)
		len = 0;
	return (len);
}

int	verif_atoi_output(int output)
{
	int	len;

	len = 0;
	if (output < 0)
		len++;
	while (output != 0)
	{
		output = output / 10;
		len++;
	}
	return (len);
}

int	creat_list(t_list **list, int atoi_res)
{
	t_list	*first;

	if ((*list) == NULL)
		*list = ft_lstnew(atoi_res);
	else
	{
		first = (*list);
		while ((*list) != NULL)
		{
			if (atoi_res == (*list)->content)
				return (1);
			*list = (*list)->next;
		}
		*list = first;
		ft_lstadd_back(list, ft_lstnew(atoi_res));
	}
	return (0);
}

int	verif_overflow(char ***str, t_list **list)
{
	int	split;
	int	atoi_res;
	int	line;
	int	res;

	split = 0;
	line = 0;
	while (str[split])
	{
		while (str[split][line])
		{
			atoi_res = ft_atoi(str[split][line]);
			if (verif_size_line(str[split][line]) != verif_atoi_output(atoi_res))
				return (1);
			res = creat_list(list, atoi_res);
			if (res == 1)
				return (1);
			line++;
		}
		split++;
		line = 0;
	}
	return (0);
}
