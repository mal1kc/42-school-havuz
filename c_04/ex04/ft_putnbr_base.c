/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkokcan <mkokcan@student.42kocaeli.com.tr  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/05 12:49:46 by mkokcan           #+#    #+#             */
/*   Updated: 2025/03/08 16:41:38 by mkokcan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

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

void	ft_putnbr_base(int nbr, char *base)
{
	long	temp;
	int		base_len;

	base_len = 0;
	if (!check_base(base, &base_len))
	{
		return ;
	}
	temp = nbr;
	if (temp < 0)
	{
		write(1, "-", 1);
		temp = -temp;
	}
	if (temp >= base_len)
	{
		ft_putnbr_base(temp / base_len, base);
		write(1, &base[temp % base_len], 1);
	}
	else
	{
		write(1, &base[temp], 1);
	}
}

//  int 	main()
//  {
//  	char base2[] = "0123456789ABCDEF";
//  	int  num2 = -42;
//  	ft_putnbr_base(num2,base2);
//  }
