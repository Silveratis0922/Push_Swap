/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   verif_overflow.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchantro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/15 14:02:08 by tchantro          #+#    #+#             */
/*   Updated: 2022/09/14 15:16:25 by tchantro         ###   ########.fr       */
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

char	*string_error(char *str)
{
	int	i;
	int	len;

	i = 0;
	len = ft_strlen(str);
	while (str[i])
	{
		if (!((str[i] >= '0' && str[i] <= '9') || (str[i] == '-')))
			return (NULL);
		if (str[i] == '-')
		{
			if (i != 0 || len == 1)
				return (NULL);
		}
		i++;
	}
	if (len == 0)
		return (NULL);
	return (str);
}

int	all_parsing(char *str, t_list **list)
{
	int		atoi_res;
	int		res;
	char	*str_res;

	str_res = string_error(str);
	if (str_res == NULL)
	{
		return (1);
	}
	atoi_res = ft_atoi(str);
	if (verif_size_line(str) != verif_atoi_output(atoi_res))
		return (2);
	res = creat_list(list, atoi_res);
	if (res == 1)
		return (3);
	return (0);
}
