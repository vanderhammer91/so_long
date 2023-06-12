/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_printhex_length.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivanderw <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/06 15:26:39 by ivanderw          #+#    #+#             */
/*   Updated: 2023/06/08 22:38:26 by ivanderw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

int	hex_length(unsigned int n)
{
	int	length;

	length = 0;
	while (n != 0)
	{
		length++;
		n = n / 16;
	}
	return (length);
}

void	print_hex(unsigned int n, const char mychar)
{
	if (n < 10)
	{
		ft_putchar(n + '0');
	}
	else if (n >= 10 && n < 16)
	{
		if (mychar == 'x')
			ft_putchar(n - 10 + 'a');
		if (mychar == 'X')
			ft_putchar(n - 10 + 'A');
	}
	else if (n >= 16)
	{
		print_hex(n / 16, mychar);
		print_hex(n % 16, mychar);
	}
}

int	ft_printf_printhex_length(unsigned int n, const char mychar)
{
	int	sign;

	sign = 0;
	if (n == 0)
	{
		ft_putchar('0');
		return (1);
	}
	else
	{
		print_hex(n, mychar);
	}
	return (hex_length(n) + sign);
}
