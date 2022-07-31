/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchantro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/12 16:36:48 by tchantro          #+#    #+#             */
/*   Updated: 2022/07/19 18:22:17 by tchantro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

size_t	ft_strlen(const char *str)
{
	int	i;

	i = 0;
	if (str == NULL)
		return (0);
	while (str[i])
		i++;
	return (i);
}

char	*tab_line(const char *s, int i, int j)
{
	int		k;
	char	*str;

	k = 0;
	str = malloc(sizeof(char) * j + 1);
	if (!str)
		return (0);
	while (k < j)
	{
		str[k] = s[i - j];
		i++;
		k++;
	}
	str[k] = '\0';
	return (str);
}

static int	word_count(const char *s, char c)
{
	int	i;
	int	j;
	int	word;

	i = 0;
	j = 0;
	word = 0;
	while (s[i])
	{
		if (s[i] == c)
			j = 0;
		if (s[i] != c)
			j++;
		if (j == 1)
			word++;
		i++;
	}
	return (word + 1);
}

char	**ft_split(const char *s, char c)
{
	int		i;
	int		j;
	int		a;
	char	**str;

	i = -1;
	j = 0;
	a = 0;
	str = malloc(sizeof(char *) * word_count(s, c));
	if (!str)
		return (0);
	while (s[++i])
	{
		if (s[i] == c && j > 0)
		{
			str[a++] = tab_line(s, i, j);
			j = 0;
		}
		else if (s[i] != c)
			j++;
	}
	if (j > 0)
		str[a++] = tab_line(s, i, j);
	str[a] = NULL;
	return (str);
}

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
			if (!(str[y][x] >= '0' && str[y][x] <= '9' || str[y][x] == '-'))
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

int	main(int argc, char **argv)
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
}

	

/*int	main(int argc, char **argv)
{
	printf("%d", argc);
	return (0);
}*/
