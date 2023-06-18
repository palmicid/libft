# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: pruangde <pruangde@student.42bangkok.com>  +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/02/17 12:37:19 by pruangde          #+#    #+#              #
#    Updated: 2023/06/18 12:42:28 by pruangde         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

UNAME = uname -s

CFLAGS = -Wall -Wextra -Werror
RM = rm -rf
NAME = libft.a

IS_LIB = ft_isalnum.c ft_isascii.c ft_isprint.c ft_isdigit.c ft_isalpha.c
TO_LIB = ft_toupper.c ft_tolower.c ft_atoi.c ft_atol.c
STR_LIB = ft_strchr.c ft_strrchr.c ft_strlen.c ft_strncmp.c ft_strlcpy.c \
		  ft_strlcat.c ft_strnstr.c ft_strdup.c ft_splitdup.c
MEM_LIB = ft_memset.c ft_bzero.c ft_memmove.c ft_memchr.c ft_memcmp.c \
		  ft_memcpy.c ft_calloc.c ft_free_p2p.c

P2_LIB = ft_itoa.c ft_substr.c ft_strjoin.c ft_strtrim.c ft_split.c \
		 ft_strmapi.c ft_striteri.c ssp_strjoin.c
P2FD_LIB = ft_putchar_fd.c ft_putstr_fd.c ft_putendl_fd.c ft_putnbr_fd.c

BN_LIB = ft_lstnew.c ft_lstadd_front.c ft_lstsize.c ft_lstlast.c ft_lstadd_back.c \
		 ft_lstdelone.c ft_lstclear.c ft_lstiter.c ft_lstmap.c

GNL = get_next_line.c get_next_line_utils.c

SRCS = $(IS_LIB) $(TO_LIB) $(MEM_LIB) $(STR_LIB) $(P2_LIB) $(P2FD_LIB) $(GNL) $(BN_LIB)
OBJS = $(SRCS:.c=.o)

.PHONY: all clean fclean re bonus

all: $(NAME)

$(NAME): $(OBJS)
	ar -rcs $@ $^

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

# test:
# 	$(CC) maintest.c $(NAME)
# 	valgrind --vgdb=no --leak-check=full --show-leak-kinds=all ./a.out

# leak:
# 	leaks --atExit -- ./a.out

norm:
	@echo "------------------------------------"
	@echo " !!!!!!!!   NORMINETTE   !!!!!!!!"
	@echo ""
	@norminette -R CheckForbiddenSourceHeader *.c
	@echo ""
	@echo ""
	@norminette -R CheckDefine *.h
	@echo ""
	@echo "------------------------------------"

#	setting vscode
#		Render Whitespace --> all
#		indentation
#	vim in .vimrc
#		unlet! skip_defaults_vim
# 		ource $VIMRUNTIME/defaults.vim

#		let g:user42 = 'pruangde'
#		let g:mail42 = 'pruangde@student.42bangkok.com'

#		set autoindent
#		set smartindent
#		set background=dark
#		set tabstop=4
#		set shiftwidth=4
#		syntax on
