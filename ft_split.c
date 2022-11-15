/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pruangde <pruangde@student.42bangkok.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/27 19:11:38 by pruangde          #+#    #+#             */
/*   Updated: 2022/11/15 20:21:56 by pruangde         ###   ########.fr       */
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
	size_t	first_d;

	first_d = 0;
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
			ps[first_d] = (char *)malloc((i + 1) * sizeof(char));
			first_d++;
		}
		else
			s++;
	}
}

static void	add_str(char const *s, char **ps, char c)
{
	size_t	i;
	size_t	first_d;

	first_d = 0;
	while (*s)
	{
		if (*s != c)
		{
			i = 0;
			while (*s != c && *s != '\0')
			{
				ps[first_d][i] = *s;
				i++;
				s++;
			}
			ps[first_d][i] = '\0';
			first_d++;
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

int	count_element_p2p(char **p2p)
{
	int	i;

	i = 0;
	while (p2p[i])
	{
		i++;
	}
	return (i);
}
