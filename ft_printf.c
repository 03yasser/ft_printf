/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yboutsli <yboutsli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 18:33:16 by yboutsli          #+#    #+#             */
/*   Updated: 2023/11/16 12:25:44 by yboutsli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft.h"

int	ft_printforma(va_list args, const char format)
{
	int	count;
	int	x;

	count = 0;
	if (format == '%')
		x = ft_putchar(format);
	else if (format == 'c')
		x = ft_putchar(va_arg(args, int));
	else if (format == 's')
		x = ft_putstr(va_arg(args, char*));
	else if (format == 'd' || format == 'i')
		x = ft_putnbr(va_arg(args ,int));
	else if (format == 'x' || format == 'X')
		x = ft_putnbrhexa(va_arg(args, unsigned int), format);
	else if (format == 'p')
		x = ft_putpointer(va_arg(args, unsigned long));
	else if (format == 'u')
		x = ft_putunsigned(va_arg(args, unsigned int));
	else
		x = ft_putchar(format);
	return (x);
}


int	ft_printf(const char *format, ...)
{
	va_list	args;
	int 	count;
	int		x;
	int		i;

	count = 0;
	va_start(args, format);
	i = 0;
	while (format[i])
	{
		if (format[i] == '%' && format[i + 1])
			x = ft_printforma(args, format[i++ + 1]);
		else
			x = ft_putchar(format[i]);
		if (x == -1)
		{
			va_end(args);
			return (-1);
		}
		else
			count += x;	
		i++;
	}
	va_end(args);
	return (count);
}
