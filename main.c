/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchantro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/15 11:53:20 by tchantro          #+#    #+#             */
/*   Updated: 2022/09/03 15:25:02 by tchantro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	int	i;
	int	j;
	int	res;
	char	***tab;
	t_list	*a_list;
	t_list	*b_list;

	i = 1;
	j = 0;
	a_list = NULL;
	b_list = NULL;
	tab = malloc (sizeof(char**) * argc - 1);
	if (argc >= 2)
	{
		while (argv[i])
		{
			tab[j] = ft_split(argv[i], ' ');
			if (error_test(tab[j]) == NULL)
				return (write (2, "Error\n", 6));
			i++;
			j++;
		}
		res = verif_overflow(tab, &a_list);
		if (res == 1)
			return (write (2, "Error0\n", 6));
	}
	test_algo(&a_list, &b_list);
	while (a_list != NULL)
	{
		printf("l'element de ma liste a est : [%d]", a_list->content);
		printf("      Index a : (%d)\n", a_list->index);
		printf("      Position : <%d>\n", a_list->pos);
		printf("      cost_a : <%d>\n", a_list->cost_a);
		printf("      cost_b : <%d>\n", a_list->cost_b);
		a_list = a_list->next;
	}
	printf("\n");
	while (b_list != NULL)
        {
                printf("l'element de ma liste b est : [%d]", b_list->content);
                printf ("      Index b : (%d)\n", b_list->index);
		printf("      Position : <%d>\n", b_list->pos);
		printf("      Target_Position : %%%d%%\n", b_list->t_pos);
		printf("      cost_a : <%d>\n", b_list->cost_a);
		printf("      cost_b : %d\n", b_list->cost_b);
                b_list = b_list->next;
        }
	return (write(1, "OK", 2));
}
