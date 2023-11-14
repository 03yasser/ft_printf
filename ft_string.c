/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_string.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yboutsli <yboutsli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 21:30:03 by yboutsli          #+#    #+#             */
/*   Updated: 2023/11/14 23:10:58 by yboutsli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft.h"

int	ft_putchar(int c)
{
	int	a;
	
	a = write(1, &c, 1);
	return (a);
}

int	ft_putstr(char *str)
{
	int	count;
	int	x;
	int	i;

	x = 0;
	count = 0;
	i = 0;
	if (!str)
		x = write(1, "(null)", 6);
	while (str[i])
	{
		x = ft_putchar(str[i++]);
		if (x != -1)
			count += x;
		else 
			return (-1);
	}
	return (count);
}
