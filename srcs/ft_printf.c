/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yboutsli <yboutsli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 18:33:16 by yboutsli          #+#    #+#             */
/*   Updated: 2023/11/13 20:46:54 by yboutsli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft.h"
#include <stdio.h>


int	ft_putchar(int c)
{
	int a;
	
	a = write(1, &c, 1);
	return (a);
}
int ft_putstr(char *str)
{
	int count;
	size_t i;

	i = 0;
	count = 0;
	while (str[i])
		count += ft_putchar(str[i++]);
	return (count);
}
int ft_printforma(va_list args, const char format)
{
	int count;

	count = 0;
	if (format == 'c')
		count += ft_putchar(va_arg(args, int));
	else if (format == 's')
		count += ft_putstr(va_arg(args, char*));
	return (count);
}
int ft_printf(const char *format, ...)
{
	size_t i;
	int count;
	va_list args;
	char c;

	count = 0;
	va_start(args, format);
    i = 0;
    while (format[i])
    {
        if(format[i] == '%')
			count += ft_printforma(args, format[++i]);
		else if(format[i] != '%')
			count += ft_putchar(format[i]);
		i++;
	}
	va_end(args);
	return (count);
}
int main()
{
	int b = ft_printf("hello%c%c%c[%s]\n",'1','2', '3', "good morning");
	int a = printf("hello%c%c%c[%s]\n",'1','2', '3', "good morning");
	printf("%d : %d \n", a, b);
}