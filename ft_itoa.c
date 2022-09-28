/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pruangde <pruangde@student.42bangkok.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/21 00:22:55 by pruangde          #+#    #+#             */
/*   Updated: 2022/09/29 04:09:38 by pruangde         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	find_index(long num)
{
	int	i;
	int	p;

	if (num <= 0)
		p = 2;
	else
		p = 1;
	i = 0;
	while (num)
	{
		num /= 10;
		i++;
	}
	return (i + p);
}

static void	num2str(char *str, long num, int x)
{
	x -= 2;
	if (num == 0)
		*str = '0';
	else
	{
		if (num < 0)
		{
			*str = '-';
			num *= -1;
		}
		while (num)
		{
			*(str + x) = (num % 10) + '0';
			num /= 10;
			x--;
		}
	}
}

char	*ft_itoa(int n)
{
	int			x;
	char		*str;

	n = (long)n;
	x = find_index(n);
	str = (char *)ft_calloc(x, sizeof(char));
	if (!str)
		return (NULL);
	num2str(str, n, x);
	return (str);
}
