# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ivanderw <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/06/08 22:20:02 by ivanderw          #+#    #+#              #
#    Updated: 2023/06/08 22:41:35 by ivanderw         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

FLAG = -Wextra -Werror -Wall

CC = gcc

NAME = libft.a

source = 	ft_putchar.c					\
			ft_strlen.c 					\
			ft_strchr.c						\
			ft_strncmp.c					\
			ft_atoi.c						\
			ft_strdup.c						\
			ft_substr.c						\
			ft_strjoin.c					\
			ft_itoa.c						\
			ft_printf_printadd_length.c		\
			ft_printf_printchar_length.c	\
			ft_printf_printdecimal_length.c	\
			ft_printf_printhex_length.c		\
			ft_printf_printstr_length.c		\
			ft_printf_printunsigned_length.c\
			ft_printf.c						\
			get_next_line.c					\


OBJECTS = $(source:%.c=%.o)



all: $(NAME)

%.o: %.c
	$(CC) $(FLAG) -o $@ -c $<

$(NAME):	$(OBJECTS)
						ar src $(NAME) $(OBJECTS)

clean:
						rm -f $(OBJECTS)

fclean:		clean
						rm -f $(NAME)

re:			fclean all
