/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azrig <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 14:17:57 by azrig             #+#    #+#             */
/*   Updated: 2024/11/18 14:17:57 by azrig            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_nblen(int nb)
{
	int	len;

	len = 0;
	while (nb != 0)
	{
		len++;
		nb = nb / 10;
	}
	return (len);
}

static char	*ft_putnbr(int n, int digit, int sign)
{
	char	*str;

	str = malloc(digit + 1);
	if (!str)
		return (NULL);
	str[digit] = '\0';
	digit--;
	while (digit >= 0)
	{
		str[digit] = (n % 10) + '0';
		n = n / 10;
		digit--;
	}
	if (sign)
		str[0] = '-';
	return (str);
}

static char	*ft_edge(int c)
{
	char	*str;

	if (c == 0)
	{
		str = malloc(2);
		if (!str)
			return (NULL);
		str[0] = '0';
		str[1] = '\0';
		return (str);
	}
	if (c == -2147483648)
	{
		str = malloc(12);
		if (!str)
			return (NULL);
		ft_strlcpy(str, "-2147483648", 12);
		return (str);
	}
	return (NULL);
}

char	*ft_itoa(int n)
{
	char	*str;
	int		digit;
	int		sign;

	sign = 0;
	if (n == 0 || n == -2147483648)
		return (ft_edge(n));
	else if (n < 0)
	{
		sign = 1;
		n = -n;
	}
	digit = ft_nblen(n) + sign;
	str = ft_putnbr(n, digit, sign);
	return (str);
}
