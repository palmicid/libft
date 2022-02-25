/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pruangde <pruangde@student.42bangkok.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/20 23:15:43 by pruangde          #+#    #+#             */
/*   Updated: 2022/02/21 00:03:23 by pruangde         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	char			c;
	unsigned int	un;

	if (n < 0)
	{
		write(fd, "-", 1);
		un = n * (-1);
	}
	else
		un = n;
	if (un >= 10)
		ft_putnbr_fd(un / 10, fd);
	c = (char)((un % 10) + 48);
	write(fd, &c, 1);
}
