/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivanderw <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/01 16:52:28 by ivanderw          #+#    #+#             */
/*   Updated: 2023/06/08 22:39:03 by ivanderw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
/*
NAME
	ft_strjoin

PROTOTYPE 
	char *ft_strjoin(char const *s1, char const *s2);

PARAMETERS
	s1	: The prefix string.
	s2	: The suffix string.

RETURN
	The new string
	NULL if the allocation fails.

EXTERNAL FUNCTIONS
	malloc

DESCRIPTION
	Allocates (with malloc(3) and returns a new string string, which is 
	the result of the concatenation of 's1' and 's2'
*/
#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*output;
	size_t	len;
	size_t	i;
	size_t	j;

	if (!s1 || !s2)
		return (NULL);
	len = ft_strlen(s1) + ft_strlen(s2) + 1;
	output = (char *) malloc(len);
	if (!output)
		return (NULL);
	i = 0;
	j = 0;
	while (s1[i])
	{
		output[i] = s1[i];
		i++;
	}
	while (s2[j])
	{
		output[i + j] = s2[j];
		j++;
	}
	output[i + j] = '\0';
	return (output);
}
