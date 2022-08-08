/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchantro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/12 16:36:48 by tchantro          #+#    #+#             */
/*   Updated: 2022/08/08 15:54:05 by tchantro         ###   ########.fr       */
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

/*int	main(int argc, char **argv)
{
	int	i;
	int	j;
	int	y;
	char	***tab;

	i = 1;
	j = 0;
	y = 0;
	tab = malloc (sizeof(char**) * argc - 1);
	if (argc >= 2)
	{
		while (argv[i])
		{
			tab[j] = ft_split(argv[i], ' ');
			if (error_test(tab[j]) == NULL)
				return(write(2, "Error\n", 6));
//			tab[j] = ft_atoi(tab[j]);
			i++;
			j++;
			
		}
	}
	return (write(1, "OK", 2));
}*/

	
int	main(int argc, char **argv)
{
	(void) argc;
	(void) argv;
	t_list	*list = NULL;
	t_list	*blist = NULL;


	blist = ft_lstnew(1);
	ft_lstadd_back(&blist, ft_lstnew(2));
	list = ft_lstnew(3);
	//ft_lstadd_back(&list, ft_lstnew(3));
	ft_lstadd_back(&list, ft_lstnew(4));
	ft_lstadd_back(&list, ft_lstnew(5));
	ft_lstadd_back(&list, ft_lstnew(6));
	ft_lstadd_back(&list, ft_lstnew(7));
	lst_push(&blist, &list);
	lst_push(&blist, &list);
	while (list != NULL)
	{
		printf("%d", list->content);
		list = list->next;
	}
	printf("\n");
	 while (blist != NULL)
        {
                printf("%d", blist->content);
                blist = blist->next;
        }
//	printf("%d", list->content);
//	printf("%d", list->next->content);
//	printf("%d", list->next->content);
//	lst_rotate(list);
	return (0);
}
