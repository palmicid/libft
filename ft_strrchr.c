/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pruangde <pruangde@student.42bangkok.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/19 16:09:52 by pruangde          #+#    #+#             */
/*   Updated: 2022/02/19 16:35:13 by pruangde         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char	*save;
	char	find;

	c = (unsigned char)c;
	save = (char *)0;
	while (*s)
	{
		find = *s;
		if (find == c)
			save = (char *)s;
		s++;
	}
	if (c == 0)
		save = ft_strchr(s, 0);
	return (save);
}
