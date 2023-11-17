/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_file2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yboutsli <yboutsli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/17 10:14:40 by yboutsli          #+#    #+#             */
/*   Updated: 2023/11/17 10:39:24 by yboutsli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	casehexa(unsigned int nb, int *count, char casef)
{
	int	i;

	if (casef == 'X')
		i = 55;
	else
		i = 87;
	if (nb < 10)
	{
		if (check(ft_putchar(nb + 48), count))
			return (-1);
	}
	else
	{
		if (check(ft_putchar(nb + i), count))
			return (-1);
	}
	return (*count);
}

int	ft_putnbrhexa(unsigned long nb, char casef)
{
	int	count;

	count = 0;
	if (nb >= 16)
	{
		if (check2(ft_putnbrhexa(nb / 16, casef), 
				ft_putnbrhexa(nb % 16, casef), &count))
			return (-1);
	}
	else
	{
		if (casehexa(nb, &count, casef) == -1)
			return (-1);
	}
	return (count);
}

int	ft_putpointer(unsigned long adress)
{
	int	count;
	int	x;

	x = 0;
	count = 0;
	if (check(ft_putstr("0x"), &count))
		return (-1);
	if (check(ft_putnbrhexa(adress, 'x'), &count))
		return (-1);
	return (count);
}

int	ft_putunsigned(unsigned int nb)
{
	int	count;

	count = 0;
	if (nb >= 10)
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
