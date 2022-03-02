/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pruangde <pruangde@student.42bangkok.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/26 22:49:32 by pruangde          #+#    #+#             */
/*   Updated: 2022/03/03 00:01:55 by pruangde         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*strim;
	size_t	st;
	size_t	ed;

	if (!s1 || !set)
		return (NULL);
	st = 0;
	ed = ft_strlen(s1);
	while (ft_strchr(set, s1[st]) && s1[st])
		st++;
	while (ft_strchr(set, s1[ed]) && ed >= st)
		ed--;
	strim = ft_substr(s1, st, (ed - st) + 1);
	return (strim);
}
