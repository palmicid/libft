/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pruangde <pruangde@student.42bangkok.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/20 17:40:43 by pruangde          #+#    #+#             */
/*   Updated: 2022/02/26 11:15:56 by pruangde         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*nstr;
	size_t	i;
	size_t	j;

	if (!s)
		return (NULL);
	if (start > ft_strlen(s))
		start = ft_strlen(s);
	if (ft_strlen(s + start) <= len)
		len = ft_strlen(s + start);
	nstr = (char *)ft_calloc((len + 1), sizeof(char));
	i = start;
	j = 0;
	while (s[i] && j < len)
	{
		nstr[j++] = s[i++];
	}
	nstr[j] = '\0';
	return (nstr);
}
