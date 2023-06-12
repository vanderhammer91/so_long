/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivanderw <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/04 14:19:01 by ivanderw          #+#    #+#             */
/*   Updated: 2023/06/08 22:38:01 by ivanderw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

int	get_output_length(va_list args, const char mychar)
{
	int	length;

	length = 0;
	if (mychar == 'c')
		length += ft_printf_printchar_length(va_arg(args, int));
	else if (mychar == 's')
		length += ft_printf_printstr_length(va_arg(args, char *));
	else if (mychar == 'd' || mychar == 'i')
		length += ft_printf_printdecimal_length(va_arg(args, int));
	else if (mychar == 'X' || mychar == 'x')
		length += ft_printf_printhex_length(va_arg(args, unsigned int), mychar);
	else if (mychar == 'u')
		length += ft_printf_printunsigned_length(va_arg(args, unsigned int));
	else if (mychar == 'p')
		length += ft_printf_printadd_length(va_arg(args, unsigned long long));
	else if (mychar == '%')
	{
		length++;
		ft_putchar('%');
	}
	return (length);
}

int	ft_printf(const char *inputstr, ...)
{
	int		i;
	va_list	args;
	int		output_length;

	va_start(args, inputstr);
	i = 0;
	output_length = 0;
	while (inputstr[i])
	{
		if (inputstr[i] == '%')
		{
			output_length += get_output_length(args, inputstr[(i + 1)]);
			i++;
		}
		else
			output_length += ft_printf_printchar_length(inputstr[i]);
		i++;
	}
	va_end(args);
	return (output_length);
}
