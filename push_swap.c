/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchantro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/12 16:36:48 by tchantro          #+#    #+#             */
/*   Updated: 2022/09/01 21:14:45 by tchantro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

char	**error_test(char **str)
{
	int	x;
	int	y;
	int	len;

	y = 0;
	if (str[y] == NULL)
		return (NULL);
	while (str[y] != NULL)
	{
		x = 0;
		len = ft_strlen(str[y]);
		while (str[y][x])
		{
			if (!((str[y][x] >= '0' && str[y][x] <= '9') || (str[y][x] == '-')))
 				return (NULL);
			if (str[y][x] == '-')
			{
				if (x != 0 || len == 1 || str[y][++x] == '-' )
					return (NULL);
				else
					x--;
			}
			x++;
		}
		y++;
	}
	return (str);
}
