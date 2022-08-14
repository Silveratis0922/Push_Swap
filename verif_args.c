#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

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

int	verif_size_line(char *str)
{
	int	i;
	int	j;
	int len;

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
	while(str[i])
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
	int i;
	int	len;

	i = 0;
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
int	verif_args(char *str)
{
	int i;
	int	j;

	i = verif_size_line(str);
	j = verif_atoi_output(ft_atoi(str));
	if (i == j)
		return (0);
	else
		return (1);
}

int	main()
{
	printf("%d", verif_args("-0"));
	return (0);
}
