/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yboutsli <yboutsli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 18:33:16 by yboutsli          #+#    #+#             */
/*   Updated: 2023/11/14 23:25:14 by yboutsli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft.h"
#include <stdio.h>


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
	else
		x = ft_putchar(format);
	if (x != -1)
		count += x;
	else
		return (-1);
	return (count);
}


int ft_printf(const char *format, ...)
{
	va_list args;
	int count;
	int x;
	int	i;

	count = 0;
	va_start(args, format);
    i = 0;
    while (format[i])
    {
        if (format[i] == '%')
		{
			if (format[i + 1])
				x = ft_printforma(args, format[i++ + 1]);
		}
		else
			x = ft_putchar(format[i]);
		
		if (x != -1)
			count += x;
		else
		{
			va_end(args);
			return (-1);
		}
		i++;
	}
	va_end(args);
	return (count);
}

int main()
{
	int b = ft_printf("%s\n","hello world");
	int a = printf("%s\n","hello world");
	printf("%d : %d \n", a, b);
// 	int count = 0;
// 	int a = ft_putnbr(500,&count);
// 	printf ("\n%d\n",a);
}