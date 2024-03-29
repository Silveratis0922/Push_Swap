/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchantro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/14 11:22:09 by tchantro          #+#    #+#             */
/*   Updated: 2022/09/15 11:39:28 by tchantro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	int		i;
	t_list	*a_list;
	t_list	*b_list;

	i = 1;
	a_list = NULL;
	b_list = NULL;
	if (argc > 1)
	{
		while (argv[i])
		{
			if (all_parsing(argv[i], (&a_list)) != 0)
				return (write(2, "Error\n", 6));
			i++;
		}
		if (first_algo(&a_list, &b_list) != 0)
			return (write(2, "Error\n", 6));
	}
	return (0);
}
