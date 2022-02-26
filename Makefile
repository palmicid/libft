# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: pruangde <pruangde@student.42bangkok.com>  +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/02/17 12:37:19 by pruangde          #+#    #+#              #
#    Updated: 2022/02/25 23:37:31 by pruangde         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc
CFLAGS = -Wall -Wextra -Werror
RM = rm -rf
NAME = libft.a

IS_LIBC = ft_isalnum.c ft_isascii.c ft_isprint.c ft_isdigit.c ft_isalpha.c
TO_LIBC = ft_toupper.c ft_tolower.c ft_atoi.c
STR_LIBC = ft_strchr.c ft_strrchr.c ft_strlen.c ft_strncmp.c ft_strlcpy.c ft_strlcat.c ft_strnstr.c ft_strdup.c
MEM_LIBC = ft_memset.c ft_bzero.c ft_memmove.c ft_memchr.c ft_memcmp.c ft_memcpy.c ft_calloc.c

P2_LIBC = ft_itoa.c ft_substr.c #ft_strjoin.c #ft_strtrim.c #ft_split.c 
P2FD_LIBC = ft_putchar_fd.c ft_putstr_fd.c ft_putendl_fd.c ft_putnbr_fd.c

LIBC = $(IS_LIBC) $(TO_LIBC) $(MEM_LIBC) $(STR_LIBC) $(P2_LIBC) $(P2FD_LIBC)

SRCS = $(LIBC)
OBJS = $(SRCS:.c=.o)

.PHONY: all clean fclean re

all: $(NAME)

$(NAME): $(OBJS)
	ar -rcs $@ $^
	ranlib $@

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

norm:
	@echo "------------------------------------"
	@echo "EJ' Norm"
	@echo ""
	@norminette -R CheckForbiddenSourceHeader ft_*.c
	@norminette -R CheckDefine *.h
	@echo ""
	@echo "------------------------------------"
