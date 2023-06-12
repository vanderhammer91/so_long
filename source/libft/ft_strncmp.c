/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivanderw <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/06 17:37:49 by ivanderw          #+#    #+#             */
/*   Updated: 2023/06/08 22:39:12 by ivanderw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
/*
SYNOPSIS
     #include <string.h>

     int
     strcmp(const char *s1, const char *s2);

     int
     strncmp(const char *s1, const char *s2, size_t n);

DESCRIPTION
     The strcmp() and strncmp() functions lexicographically compare the 
	 null-termi-
     nated strings s1 and s2.

     The strncmp() function compares not more than n characters.  
	 Because strncmp()
     is designed for comparing strings rather than binary data, 
	 characters that
     appear after a `\0' character are not compared.

RETURN VALUES
     The strcmp() and strncmp() functions return an integer greater than,
	 equal to,
     or less than 0, according as the string s1 is greater than, equal to, 
	 or less
     than the string s2.  The comparison is done using unsigned characters,
	 so that
     `\200' is greater than `\0'.
*/
#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, int n)
{
	int				i;
	unsigned char	*my_s1;
	unsigned char	*my_s2;

	my_s1 = (unsigned char *)s1;
	my_s2 = (unsigned char *)s2;
	i = 0;
	while (i < n)
	{
		if (my_s1[i] == '\0' && my_s2[i] == '\0')
		{
			return (0);
		}
		if (my_s1[i] != my_s2[i])
		{
			if (my_s1[i] == '\0' && my_s2[i] != '\0')
				return (-1);
			else if (my_s2[i] == '\0' && my_s1[i] != '\0')
				return (1);
			else
				return (my_s1[i] - my_s2[i]);
		}
		i++;
	}
	return (0);
}
