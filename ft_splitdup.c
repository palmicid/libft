/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_splitdup.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pruangde <pruangde@student.42bangkok.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/03 11:26:22 by pruangde          #+#    #+#             */
/*   Updated: 2022/11/15 20:22:11 by pruangde         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	**ft_splitdup(char **origin)
{
	char	**new;
	int		tmp;
	int		i;

	tmp = count_element_p2p(origin);
	new = (char **)malloc((tmp + 1) * sizeof(char *));
	if (!new)
		return (NULL);
	new[tmp] = 0;
	i = 0;
	while (i < tmp)
	{
		new[i] = ft_strdup(origin[i]);
		i++;
	}
	return (new);
}
