/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkokcan <mkokcan@student.42kocaeli.com.tr  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/05 12:48:44 by mkokcan           #+#    #+#             */
/*   Updated: 2025/03/05 13:04:51 by mkokcan          ###   ########.fr       */
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

int	ft_char_is_numeric(char chr)
{
	return (chr >= '0' && chr <= '9');
}

int	ft_atoi(char *str)
{
	int	sign;
	int	result;
	int	indx;
	int	usable_chr;

	sign = 1;
	indx = 0;
	result = 0;
	while (str[indx] != '\0')
	{
		if (str[indx] == '-')
		{
			indx++;
			sign *= -1;
			continue ;
		}
		usable_chr = (str[indx] == '+' || ft_is_space(str[indx]));
		if (!ft_char_is_numeric(str[indx]) && !usable_chr)
			break ;
		if (!usable_chr)
			result = (result * 10) + (str[indx] - '0');
		indx++;
	}
	return (result * sign);
}

// #include <stdio.h>
// int	main(void)
// {
// 	printf("%d\n",ft_atoi(" ---+--+1234ab567-"));
// }
