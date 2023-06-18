/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ssp_strjoin.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pruangde <pruangde@student.42bangkok.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/27 16:01:36 by pruangde          #+#    #+#             */
/*   Updated: 2023/05/24 22:52:02 by pruangde         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// mode c_s1 if == 1 --> free s1, 0 --> not free
// mode c_s2 if == 1 --> free s2, 0 --> not free
char	*ssp_strjoin(char *s1, char *s2, int c_s1, int c_s2)
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
	if (c_s1 == 1)
		free(s1);
	if (c_s2 == 1)
		free(s2);
	return (str);
}

char	*ssp_strnjoin(char *s1, char *s2, size_t n, int mode1)
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
	if (mode1 == 1)
		free(s1);
	return (str);
}
