/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aabeid <aabeid@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/23 09:29:54 by aabeid            #+#    #+#             */
/*   Updated: 2021/11/28 14:59:08 by aabeid           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

int	chars_counter(long n)
{
	int	ret;

	ret = 0;
	if (n <= 0)
	{
		n *= -1;
		ret++;
	}
	while (n > 0)
	{
		n /= 10;
		ret++;
	}
	return (ret);
}

int	ft_putnbr(long nb)
{
	int	ret;

	if (nb < 0)
	{
		ft_putchar('-');
		ft_putnbr(nb * (-1));
	}
	else if (nb >= 10)
	{
		ft_putnbr(nb / 10);
		ft_putnbr(nb % 10);
	}
	else
	{
		ft_putchar(nb + '0');
	}
	ret = chars_counter(nb);
	return (ret);
}
