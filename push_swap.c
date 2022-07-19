/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchantro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/12 16:36:48 by tchantro          #+#    #+#             */
/*   Updated: 2022/07/19 05:38:03 by tchantro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

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
	str[a++] = '\0';
	return (str);
}

int	ft_atoi(const char *nptr)
{
	int	i;
	int	j;
	int	k;
	int	a;

	i = 0;
	j = 0;
	k = 1;
	a = 0;
	while (nptr[i] == 32 || (nptr[i] >= 9 && nptr[i] <= 13))
		i++;
	while (nptr[i] == '+' || (nptr[i] == '-'))
	{
		if (nptr[i] == '-')
			k = k * -1;
		i++;
		j++;
	}
	if (j >= 2)
		return (0);
	while (nptr[i] >= 48 && nptr[i] <= 57)
		a = a * 10 + nptr[i++] - 48;
	return (a * k);
}

char	*error_test(char **str)
{
	int	x;
	int	y;
	int	len;

	x = 0;
	y = 0;
	len = ft_strlen(str[y]);
	while (str[y] != NULL)
	{
		while (str[y][x])
		{
			if (!(str[y][x] >= '0' && str[y][x] <= '9' || str[y][x] == '-'))
 				return (NULL);
			if (str[y][x] == '-')
			{
				if (x != 0 || str[y][++x] == '-' || len = 1)
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
	char	***tab;

	i = 1;
	j = 0;
	if (argc > 2)
	{
		while (argv[i])
		{
			tab[j] = ft_split(argv[i], '\n');
			tab[j] = error_test(tab[j]);
			i++;
			j++;
		}
	}

	
/*
int	main()
{
	//printf("%s", error_test("01324i8"));
	if (!(error_test("")))
		return (write(2, "Error\n", 6));
	return (0);
}*/
