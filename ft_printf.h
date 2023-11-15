/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yboutsli <yboutsli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 18:30:35 by yboutsli          #+#    #+#             */
/*   Updated: 2023/11/15 16:31:37 by yboutsli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H

# define FT_PRINTF_H
# include <unistd.h>
# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdarg.h>
# include <limits.h>

int	ft_printf(const char *format, ...);
int	ft_putstr(char *str);
int	ft_putchar(unsigned int c);
int	ft_putnbr(int nb);
int ft_putnbrhexa(unsigned long nb, char casef);
int	ft_printforma(va_list args, const char format);
int ft_printf(const char *format, ...);
int ft_putpointer(unsigned long adress);
int ft_putunsigned(unsigned int nb);

#endif