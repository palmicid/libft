/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pruangde <pruangde@student.42bangkok.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/01 04:27:19 by pruangde          #+#    #+#             */
/*   Updated: 2022/10/27 16:05:09 by pruangde         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

//mode 1 find \n , mode 0 just \0
size_t	gnl_sp_strlen(const char *s, int mode)
{
	size_t	i;

	i = 0;
	if (!s)
		return (i);
	if (mode == 0)
	{
		while (s[i] != '\0')
			i++;
	}
	else
	{
		while (s[i] && s[i] != '\n')
			i++;
		i++;
	}
	return (i);
}

int	gnl_find_n(char *s)
{
	int	i;

	if (!s)
		return (0);
	i = 0;
	while (s[i] != '\0')
	{
		if (s[i] == '\n')
			return (1);
		i++;
	}
	return (0);
}

t_lstfd	*gnl_create_list(int fd)
{
	t_lstfd	*new_data;

	new_data = (t_lstfd *)malloc(sizeof(t_lstfd));
	if (!new_data)
		return (NULL);
	new_data->fd = fd;
	new_data->rfd = 1;
	new_data->str = NULL;
	new_data->next = NULL;
	return (new_data);
}

t_lstfd	*gnl_list_reloc(t_lstfd *data, int fd)
{
	t_lstfd	*prev;
	t_lstfd	*finder;

	finder = data;
	if (finder->fd == fd)
		data = data->next;
	else
	{
		while (finder->fd != fd)
		{
			prev = finder;
			finder = finder->next;
		}
		prev->next = finder->next;
	}
	free(finder);
	return (data);
}
