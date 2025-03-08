/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_non_printable.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkokcan <mkokcan@student.42kocaeli.com.tr  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/03 15:09:30 by mkokcan           #+#    #+#             */
/*   Updated: 2025/03/06 11:52:53 by mkokcan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <unistd.h>

int	ft_char_is_printable(char chr)
{
	return (chr >= ' ' && chr <= '~');
}

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	put_hex_number(int number_10base)
{
	const char	hex_digits[16] = "0123456789abcdef";

	ft_putchar('\\');
	ft_putchar(hex_digits[number_10base / 16]);
	ft_putchar(hex_digits[number_10base % 16]);
}

void	ft_putstr_non_printable(char *str)
{
	int	c;

	c = 0;
	while (str[c] != '\0')
	{
		if (ft_char_is_printable(str[c]))
		{
			ft_putchar(str[c]);
		}
		else
		{
			put_hex_number((int)str[c]);
		}
		c++;
	}
}
