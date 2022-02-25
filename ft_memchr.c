/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pruangde <pruangde@student.42bangkok.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/18 00:32:46 by pruangde          #+#    #+#             */
/*   Updated: 2022/02/18 03:20:11 by pruangde         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t			i;
	unsigned char	to_find;

	i = 0;
	to_find = (unsigned char)c;
	while (i < n)
	{
		if (*((unsigned char *)s) == to_find)
			return ((void *)s);
		i++;
		s++;
	}
	return (0);
}
