/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aabeid <aabeid@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/23 09:30:32 by aabeid            #+#    #+#             */
/*   Updated: 2021/11/25 18:48:26 by aabeid           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

int	ft_putchar_base(char *arr, int idx)
{
	int	tmp;

	tmp = idx;
	if (idx < 1)
	{
		write(1, "0", 1);
		return (1);
	}
	while (--idx >= 0)
		write(1, &arr[idx], 1);
	return (tmp);
}

int	ft_putnbr_base(unsigned long long n, char c)
{
	int		tmp;
	char	arr[12];
	int		idx;
	char	*base;
	int		ret;

	base = "0123456789abcdef";
	if (c == 'X')
			base = "0123456789ABCDEF";
	idx = 0;
	ret = 0;
	while (n != 0)
	{
		tmp = n % 16;
		n = n / 16;
		arr[idx++] = base[tmp];
	}
	if (c == 'p')
	{	
		write(1, "0x", 2);
		ret += 2;
	}
	if (idx >= 0)
		ret += ft_putchar_base(arr, idx);
	return (ret);
}
