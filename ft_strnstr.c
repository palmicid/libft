/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pruangde <pruangde@student.42bangkok.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/19 20:31:44 by pruangde          #+#    #+#             */
/*   Updated: 2022/02/20 20:38:00 by pruangde         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *str, const char *nd, size_t len)
{
	size_t	i;
	size_t	j;

	i = 0;
	if (!(*nd))
		return ((char *)str);
	while (str[i] && i < len)
	{
		j = 0;
		if (str[i] == nd[j])
		{
			while (str[i + j] == nd[j] && str[i + j] && nd[j] && (i + j) < len)
				j++;
			if (!(nd[j]))
				return ((char *)str + i);
		}
		i++;
	}
	return (NULL);
}
