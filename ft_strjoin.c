/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pruangde <pruangde@student.42bangkok.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/26 11:20:50 by pruangde          #+#    #+#             */
/*   Updated: 2023/05/22 22:06:20 by pruangde         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	i;
	size_t	j;
	size_t	len;
	char	*str;

	if (!s1 && !s2)
		return (NULL);
	else
		len = ft_strlen(s1) + ft_strlen(s2);
	str = (char *)ft_calloc((len + 1), sizeof(char));
	if (!str)
		return (NULL);
	i = 0;
	j = 0;
	while (s1[j])
		str[i++] = s1[j++];
	j = 0;
	while (s2[j])
		str[i++] = s2[j++];
	return (str);
}

// join s1 with n char from s2
char	*ft_strnjoin(char *s1, char *s2, size_t n)
{
	size_t	i;
	size_t	j;
	size_t	len;
	char	*str;

	if (!s1 && !s2)
		return (NULL);
	else
		len = ft_strlen(s1) + n;
	str = (char *)ft_calloc((len + 1), sizeof(char));
	if (!str)
		return (NULL);
	i = 0;
	j = 0;
	while (s1[j])
		str[i++] = s1[j++];
	j = 0;
	while (s2[j] && (j < n))
		str[i++] = s2[j++];
	return (str);
}
