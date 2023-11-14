/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yboutsli <yboutsli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 18:30:35 by yboutsli          #+#    #+#             */
/*   Updated: 2023/11/14 23:15:12 by yboutsli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H

# define FT_PRINTF_H
# include <unistd.h>
# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdarg.h>

int ft_printf(const char *format, ...);
int	ft_putstr(char *str);
int	ft_putchar(int c);
#endif