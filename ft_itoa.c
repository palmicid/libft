/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pruangde <pruangde@student.42bangkok.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/21 00:22:55 by pruangde          #+#    #+#             */
/*   Updated: 2022/03/03 00:22:09 by pruangde         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	find_index(long int num)
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

void	num2str(char *str, long int num, int x)
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
	long int	num;

	num = (long int)n;
	x = find_index(n);
	str = (char *)ft_calloc(x, sizeof(char));
	if (!str)
		return (NULL);
	num2str(str, num, x);
	return (str);
}
