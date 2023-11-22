/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yboutsli <yboutsli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 18:30:35 by yboutsli          #+#    #+#             */
/*   Updated: 2023/11/22 22:47:14 by yboutsli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H

# define FT_PRINTF_H
# include <unistd.h>
# include <stdlib.h>
# include <stdarg.h>

int	ft_printf(const char *format, ...);
int	ft_putstr(char *str);
int	ft_putchar(unsigned char c);
int	ft_putnbr(int nb);
int	ft_putnbrhexa(unsigned long nb, char casef);
int	ft_printforma(va_list args, const char format);
int	ft_printf(const char *format, ...);
int	ft_putpointer(unsigned long adress);
int	ft_putunsigned(unsigned int nb);
int	check(int x, int *count);
int	check2(int a, int b, int *count);
#endif