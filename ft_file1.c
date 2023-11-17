/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_file1.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yboutsli <yboutsli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 21:30:03 by yboutsli          #+#    #+#             */
/*   Updated: 2023/11/17 10:38:36 by yboutsli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	check(int x, int *count)
{
	if (x < 0)
		return (1);
	else
		*count += x;
	return (0);
}

int	check2(int a, int b, int *count)
{
	if (check(a, count) || check(b, count))
		return (1);
	return (0);
}

int	ft_putchar(unsigned char c)
{
	int	res;

	res = write(1, &c, 1);
	return (res);
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
		return (write(1, "(null)", 6));
	}
	while (str[i])
	{
		if (check(ft_putchar(str[i++]), &count))
			return (-1);
	}
	return (count);
}

int	ft_putnbr(int nb)
{
	int	count;

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
	else if (nb < 10)
	{
		if (check(ft_putchar(nb + 48), &count))
			return (-1);
	}
	return (count);
}
