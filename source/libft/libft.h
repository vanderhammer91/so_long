/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivanderw <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/08 22:30:03 by ivanderw          #+#    #+#             */
/*   Updated: 2023/06/08 23:07:19 by ivanderw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H
# include <stdlib.h>
# include <unistd.h>
# include <limits.h>
# include <stdarg.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1024
# endif

long	ft_atoi(const char *str);
char	*ft_itoa(int n);
int		ft_printf(const char *inputstr, ...);
int		ft_printf_printadd_length(unsigned long long my_ptr);
int		ft_printf_printchar_length(char n);
int		ft_printf_printdecimal_length(int n);
int		ft_printf_printhex_length(unsigned int n, const char mychar);
int		ft_printf_printstr_length(char *str);
int		ft_printf_printunsigned_length(unsigned int n);
void	ft_putchar(char c);
char	*ft_strchr(const char *string, int searchedChar);
char	*ft_strdup(char *src);
size_t	ft_strlen(const char *s);
char	*ft_substr(const char *s, unsigned int start, size_t len);
char	*ft_strjoin(char const *s1, char const *s2);
char	*get_next_line(int fd);

#endif
