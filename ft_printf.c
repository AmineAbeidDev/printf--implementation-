/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aabeid <aabeid@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/22 11:44:09 by aabeid            #+#    #+#             */
/*   Updated: 2021/11/26 16:11:30 by aabeid           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	check_conv(char type, va_list arg)
{
	int	ret;

	ret = 0;
	if (type == 'd' || type == 'i')
		ret += ft_putnbr(va_arg(arg, int));
	else if (type == 'c')
		ret += ft_putchar(va_arg(arg, int));
	else if (type == 's')
		ret += ft_putstr(va_arg(arg, char *));
	else if (type == 'u')
		ret += ft_putnbr(va_arg(arg, unsigned int));
	else if (type == 'x' || type == 'X')
		ret += ft_putnbr_base(va_arg(arg, unsigned int), type);
	else if (type == 'p')
		ret += ft_putnbr_base(va_arg(arg, unsigned long), type);
	else if (type == '%')
		ret += ft_putchar('%');
	return (ret);
}

int	ft_printf(const char *format, ...)
{
	va_list	args;
	int		ret;

	ret = 0;
	va_start(args, format);
	while (*format != '\0')
	{
		if (*format == '%')
		{
			ret += check_conv(*(format + 1), args);
				format += 2;
		}
		else
		{
			ft_putchar(*format);
			format++;
			ret++;
		}
	}
	va_end(args);
	return (ret);
}
