/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivanderw <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/07 18:26:43 by ivanderw          #+#    #+#             */
/*   Updated: 2023/06/08 22:37:14 by ivanderw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
/*
PROTOTYPE
	char *ft_itoa(int n);

PARAMETERS
	n: the integer to convert

RETURN VALUE
	The string representing the integer
	NULL if the allocation fails.

EXTERNAL FUNCTIONS
	malloc

DESCRIPTION
	Allocates (with malloc(3) and returns a string representing the integer
	received as an argument. Negative numbers must be handled.
*/
#include "libft.h"

size_t	get_int_length(int n)
{
	size_t	out;

	if (n == 0)
		return (1);
	out = 0;
	if (n < 0)
		out += 1;
	while (n != 0)
	{
		n = n / 10;
		out ++;
	}
	return (out);
}

char	*ft_itoa(int n)
{
	char	*output;
	size_t	length;

	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	else if (n == 0)
		return (ft_strdup("0"));
	length = get_int_length(n);
	output = (char *)malloc(sizeof(char) * length + 1);
	if (!output)
		return (NULL);
	if (n < 0)
	{
		output[0] = '-';
		n = -n;
	}
	output[length] = '\0';
	while (n != 0)
	{
		output[length - 1] = (n % 10) + '0';
		n = n / 10;
		length--;
	}
	return (output);
}
