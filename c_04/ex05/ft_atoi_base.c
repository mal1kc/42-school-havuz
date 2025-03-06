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

int	ft_is_space(char chr)
{
	if (chr == ' ')
		return (1);
	if (chr == '\t')
		return (1);
	if (chr == '\n')
		return (1);
	if (chr == '\r')
		return (1);
	if (chr == '\f')
		return (1);
	if (chr == '\v')
		return (1);
	return (0);
}

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

void	skip_space_and_get_sign(char *nbr_str, int *counter, int *sign)
{
	while (nbr_str[*counter] == '-' || nbr_str[*counter] == '+'
		|| ft_is_space(nbr_str[*counter]))
	{
		if (nbr_str[*counter] == '-')
			*sign *= -1;
		*counter = *counter + 1;
	}
}

int	ft_atoi_base(char *nbr_str, char *base)
{
	int	base_len;
	int	c;
	int	res;
	int	sign;
	int	base_c;

	res = 0;
	c = 0;
	sign = 1;
	if (!check_base(base, &base_len))
		return (0);
	skip_space_and_get_sign(nbr_str, &c, &sign);
	while (nbr_str[c] != '\0')
	{
		base_c = 0;
		while (base[base_c] != nbr_str[c] && base[base_c] != '\0')
			base_c++;
		if (base[base_c] == '\0')
			break ;
		res = (res * base_len) + base_c;
		c++;
	}
	return (res * sign);
}

// #include <stdio.h>
// int main()
// {
// 	char base[] = "0123456789";
// 	int  num = 10;
// 	if (num != ft_atoi_base("10", base))
// 	{
// 		printf("your shit not works");
// 	}
//
// 	char base2[] = "0123456789ABCDEF";
// 	int  num2 = -42;
// 	if (num2 != ft_atoi_base("-2A", base2))
// 	{
// 		printf("your shit not works");
// 	}
// }
