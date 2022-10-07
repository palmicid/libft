/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pruangde <pruangde@student.42bangkok.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/01 04:26:54 by pruangde          #+#    #+#             */
/*   Updated: 2022/10/07 18:31:12 by pruangde         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1024
# endif

# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# include <sys/uio.h>
# include "libft.h"

typedef struct s_lstfd
{
	int				fd;
	int				rfd;
	char			*str;
	struct s_lstfd	*next;
}					t_lstfd;

int		gnl_find_n(char *s);
char	*get_next_line(int fd);
char	*gnl_rdline(t_lstfd *cursor);
char	*gnl_sp_strdup_reloc(t_lstfd *data);
char	*gnl_sp_strjoin(char *s1, char *s2);
size_t	gnl_sp_strlen(const char *s, int mode);
t_lstfd	*gnl_create_list(int fd);
t_lstfd	*gnl_new_or_find(t_lstfd *data, int fd);
t_lstfd	*gnl_list_reloc(t_lstfd *data, int fd);

#endif
