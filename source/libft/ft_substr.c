/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivanderw <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/25 18:54:11 by ivanderw          #+#    #+#             */
/*   Updated: 2023/06/08 22:39:18 by ivanderw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

//mallocs a string that is a substring of length len within
//a given string s. its length is the parameter len.
char	*ft_substr(const char *s, unsigned int start, size_t len)
{
	char	*output;
	size_t	i;
	size_t	s_len;

	if (!s)
		return ((char *)s);
	s_len = ft_strlen(s);
	if (start > s_len)
		return (ft_strdup(""));
	if (len > s_len - start)
		len = s_len - start;
	output = (char *) malloc(len + 1);
	if (!(output))
		return (NULL);
	i = 0;
	while (i < len)
	{
		output[i] = s[i + start];
		i++;
	}
	output[i] = '\0';
	return (output);
}
