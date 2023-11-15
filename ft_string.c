/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_string.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yboutsli <yboutsli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 21:30:03 by yboutsli          #+#    #+#             */
/*   Updated: 2023/11/15 20:48:14 by yboutsli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft.h"

static int check(int x, int *count)
{
	if (x == -1)
		return (1);
	else
		*count += x;
	return (0);
}

static int check2(int a, int b, int *count)
{
	if (check(a, count) || check(b, count))
		return (1);
	return (0);
}

int	ft_putchar(unsigned char c)
{
	int res;
	extern int g_i;
	res = write(1, &c, 1);
	if (res == -1)
	{
		g_i = -1;
		return (-1);
	}
	return(res);
}

int	ft_putstr(char *str)
{
	int	count;
	int	x;
	int	i;

	x = 0;
	count = 0;
	i = 0;
	if (str == NULL)
	{
		x = write(1, "(null)", 6);
		if ( x == -1)
			return (-1);
		return (x);
	}
	while (str[i])
	{
		x = ft_putchar(str[i++]);
		if (check(x, &count))
			return (-1);
	}
	return (count);
}
int ft_putnbr(int nb)
{
	int count;

	count = 0;
	if (nb == -2147483648)
	{
		if (check(ft_putstr("-2147483648"), &count))
			return (-1);
	}
	else if (nb < 0)
	{
		nb = -nb;
		if (check2(ft_putchar('-'), ft_putnbr(nb), &count))
			return (-1);
	}
	else if (nb >= 10)
	{
		if (check2(ft_putnbr(nb / 10), ft_putnbr(nb % 10), &count))
			return (-1);
	}
	else if (nb <10)
	{
		if (check(ft_putchar(nb + 48), &count))
			return (-1);
	}
	return (count);
}
static int casehexa(unsigned int nb,int *count, char casef)
{
	int i;

	if (casef == 'X')
		i = 55;
	else
		i = 87;
	if (nb < 10)
	{
		if(check(ft_putchar(nb + 48), count))
			return (-1);
	}
	else
	{
		if (check(ft_putchar(nb + i), count))
			return (-1);
	}
	return (*count);
}
int ft_putnbrhexa(unsigned long nb, char casef)
{
	int count;

	count = 0;
	if (nb >= 16)
	{
		if (check2(ft_putnbrhexa(nb / 16, casef), ft_putnbrhexa(nb % 16, casef), &count))
			return (-1);
	}
	else
	{
		if (casehexa(nb, &count, casef) == -1)
			return (-1);
	}
	return (count);
}
int ft_putpointer(unsigned long adress)
{
	int	count;
	int	x;

	x = 0;
	count = 0;
	if (check(ft_putstr("0x"), &count))
		return (-1);
	x = ft_putnbrhexa(adress, 'x');
	if (x == -1)
		return (-1);
	else
		count += x;
	return (count);
}
int ft_putunsigned(unsigned int nb)
{
	int count;

	count = 0;
	if (nb >= 10)
	{
		if (check2(ft_putnbr(nb / 10), ft_putnbr(nb % 10), &count))
			return (-1);
	}
	else if (nb <10)
	{
		if (check(ft_putchar(nb + 48), &count))
			return (-1);
	}
	return (count);
}
