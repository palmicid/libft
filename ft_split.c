/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pruangde <pruangde@student.42bangkok.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/27 19:11:38 by pruangde          #+#    #+#             */
/*   Updated: 2022/07/25 14:16:53 by pruangde         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	count_word(char const *s, char c)
{
	size_t	i;

	i = 0;
	while (*s)
	{
		if (*s != c)
		{
			i++;
			while (*s != c && *s != '\0')
				s++;
		}
		else
			s++;
	}
	return (i);
}

static void	flen_new(char const *s, char **ps, char c)
{
	size_t	i;
	size_t	fd;

	fd = 0;
	while (*s)
	{
		if (*s != c)
		{
			i = 0;
			while (*s != c && *s != '\0')
			{
				i++;
				s++;
			}
			ps[fd] = (char *)malloc((i + 1) * sizeof(char));
			fd++;
		}
		else
			s++;
	}
}

static void	add_str(char const *s, char **ps, char c)
{
	size_t	i;
	size_t	fd;

	fd = 0;
	while (*s)
	{
		if (*s != c)
		{
			i = 0;
			while (*s != c && *s != '\0')
			{
				ps[fd][i] = *s;
				i++;
				s++;
			}
			ps[fd][i] = '\0';
			fd++;
		}
		else
			s++;
	}
}

char	**ft_split(char const *s, char c)
{
	char	**ptstr;
	size_t	i;

	if (!s)
		return (NULL);
	i = count_word(s, c);
	ptstr = (char **)malloc((i + 1) * sizeof(char *));
	if (!ptstr)
		return (NULL);
	ptstr[i] = NULL;
	flen_new(s, ptstr, c);
	add_str(s, ptstr, c);
	return (ptstr);
}
