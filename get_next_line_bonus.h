/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pruangde <pruangde@student.42bangkok.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/01 04:26:54 by pruangde          #+#    #+#             */
/*   Updated: 2022/09/29 04:10:20 by pruangde         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

# include <sys/types.h>
# include <sys/uio.h>
# include <unistd.h>
# include <stdlib.h>
# include "libft.h"

typedef struct s_lstfd
{
	int				fd;
	int				rfd;
	char			*str;
	struct s_lstfd	*next;
}					t_lstfd;

char	*get_next_line(int fd);

int		gnl_find_n(char *s);
size_t	gnl_sp_strlen(const char *s, int mode);
t_lstfd	*gnl_create_list(int fd);
t_lstfd	*gnl_list_reloc(t_lstfd *data, int fd);

#endif
