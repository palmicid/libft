/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pruangde <pruangde@student.42bangkok.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/01 04:26:37 by pruangde          #+#    #+#             */
/*   Updated: 2022/05/01 04:26:46 by pruangde         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*sp_strjoin(char *s1, char *s2)
{
	size_t	i;
	size_t	j;
	size_t	len;
	char	*str;

	if (!s1 && !s2)
		return (NULL);
	len = sp_strlen(s1, 0) + sp_strlen(s2, 0);
	str = (char *)malloc((len + 1) * sizeof(char));
	if (!str)
		return (NULL);
	i = 0;
	j = 0;
	while (s1 && s1[i])
		str[i++] = s1[j++];
	j = 0;
	while (s2[j])
		str[i++] = s2[j++];
	str[i] = '\0';
	if (s1)
	{
		free(s1);
		s1 = NULL;
	}
	return (str);
}

char	*sp_strdup_reloc(t_lstfd *cursor)
{
	size_t	data_len;
	size_t	len;
	char	*dup;
	char	*tmp;
	size_t	mode;

	mode = (size_t)find_n(cursor->str);
	len = sp_strlen(cursor->str, mode);
	dup = (char *)malloc((len + 1) * (sizeof(char)));
	if (!dup)
		return (NULL);
	dup = ft_memcpy(dup, cursor->str, len);
	dup[len] = '\0';
	data_len = sp_strlen((cursor->str + len), 0);
	tmp = (char *)malloc((data_len + 1) * sizeof(char));
	if (!tmp)
		return (NULL);
	tmp = ft_memcpy(tmp, cursor->str + len, data_len);
	tmp[data_len] = '\0';
	free(cursor->str);
	cursor->str = tmp;
	tmp = NULL;
	return (dup);
}

char	*rdline(t_lstfd *cursor)
{
	char	*buf;
	char	*ret;

	buf = (char *)malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!buf)
		return (NULL);
	while (cursor->rfd > 0)
	{
		cursor->rfd = read(cursor->fd, buf, BUFFER_SIZE);
		if (cursor->rfd < 0 || (cursor->rfd == 0 && !cursor->str))
		{
			free(buf);
			return (NULL);
		}
		buf[cursor->rfd] = '\0';
		cursor->str = sp_strjoin(cursor->str, buf);
		if (find_n(cursor->str))
			break ;
	}
	free(buf);
	ret = sp_strdup_reloc(cursor);
	if (!(sp_strlen(ret, 0)))
		free(ret);
	return (ret);
}

t_lstfd	*new_or_find(t_lstfd *data, int fd)
{
	t_lstfd	*current_fd;
	t_lstfd	*prev;

	if (!(data))
		current_fd = create_list(fd);
	else
	{
		while (data)
		{
			if (data->fd == fd)
			{
				current_fd = data;
				return (current_fd);
			}
			else
			{
				prev = data;
				data = data->next;
			}
		}
		current_fd = create_list(fd);
		prev->next = current_fd;
	}
	return (current_fd);
}

char	*get_next_line(int fd)
{
	static t_lstfd	*data = NULL;
	t_lstfd			*cursor;
	char			*ret;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	cursor = new_or_find(data, fd);
	if (!data)
		data = cursor;
	ret = rdline(cursor);
	if (!sp_strlen(cursor->str, 0))
	{
		free(cursor->str);
		cursor->str = NULL;
	}
	if ((cursor->rfd <= 0) && !(cursor->str))
	{
		data = list_reloc(data, fd);
	}
	return (ret);
}
