/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkokcan <mkokcan@student.42kocaeli.com.tr  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/05 12:49:46 by mkokcan           #+#    #+#             */
/*   Updated: 2025/03/05 12:51:09 by mkokcan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putnbr_base(int nbr, char *base);

int	check_base(char *base, int *base_len)
{
	unsigned int	c1;
	unsigned int	c2;

	c1 = 0;
	while (base[c1] != '\0')
	{
		if (base[c1] == '-' || base[c1] == '+')
			return (0);
		if (c1 > 1)
		{
			c2 = c1 - 1;
			while (c2 > 0)
			{
				if (base[c1] == base[c2])
					return (0);
				c2--;
			}
		}
		c1++;
	}
	*base_len = c1;
	return (c1 > 1);
}

// void ft_putnbr_base(int nbr, char *base)
// {
// 	int base_len;
// 	base_len = 0;
// 	if (!check_base(base, &base_len))
// 	{
// 		return ;
// 	}
// 	if (nbr < 0)
// 	{
// 		write(1, "-", 1);
// 		nbr = -nbr;
// 	}
// 	if (nbr >= base_len)
// 	{
// 		ft_putnbr_base(nbr / base_len, base);
// 		write(1, &base[nbr % base_len], 1);
// 	}
// 	else
// 	{
// 		write(1, &base[nbr % base_len], 1);
// 	}
// }

int	putnbr_base_put_if_edge(int nbr, char *base, unsigned int base_len)
{
	if (nbr == -2147483648)
	{
		write(1, "-", 1);
		write(1, &base[2 % base_len], 1);
		nbr = 147483648;
		ft_putnbr_base(nbr, base);
		return (1);
	}
	if (nbr == 0)
	{
		write(1, &base[0], 1);
		return (1);
	}
	return (0);
}

void	ft_putnbr_base(int nbr, char *base)
{
	int		base_len;
	int		c;
	char	result[32];

	c = 0;
	if (!check_base(base, &base_len))
		return ;
	if (putnbr_base_put_if_edge(nbr, base, base_len))
		return ;
	if (nbr < 0)
	{
		write(1, "-", 1);
		nbr = -nbr;
	}
	while (nbr > 0)
	{
		result[c] = base[nbr % base_len];
		nbr = nbr / base_len;
		c++;
	}
	while (c > 0)
	{
		c--;
		write(1, &result[c], 1);
	}
}
