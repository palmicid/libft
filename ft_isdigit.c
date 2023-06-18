/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isdigit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pruangde <pruangde@student.42bangkok.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/16 11:23:47 by pruangde          #+#    #+#             */
/*   Updated: 2023/06/14 20:15:58 by pruangde         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_isdigit(int c)
{
	if (c >= '0' && c <= '9')
		return (1);
	return (0);
}

// also find + -
int	sp_digit_pm(int c)
{
	if (ft_isdigit(c) || c == '+' || c == '-')
		return (1);
	return (0);
}

// if digit or + - return 0, if not return 1
int	sp_digit_pm_str(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (!sp_digit_pm(str[i]))
			return (1);
		i++;
	}
	return (0);
}
