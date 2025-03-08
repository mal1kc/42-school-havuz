/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkokcan <mkokcan@student.42kocaeli.com.tr  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/05 12:48:44 by mkokcan           #+#    #+#             */
/*   Updated: 2025/03/08 16:16:25 by mkokcan          ###   ########.fr       */
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

	sign = 1;
	indx = 0;
	result = 0;
	while (str[indx] && ft_is_space(str[indx]))
		indx++;
	while (str[indx] && (str[indx] == '+' || str[indx] == '-'))
	{
		if (str[indx] == '-')
			sign *= -1;
		indx++;
	}
	while (str[indx] && ft_char_is_numeric(str[indx]))
	{
		result = (result * 10) + (str[indx] - '0');
		indx++;
	}
	return (result * sign);
}

// #include <stdio.h>
// int	main()
// {
// 	printf("%d\n",ft_atoi(" ---+--+1234ab567-"));
// 	printf("%d\n",ft_atoi("  ---+--+1234ab567-"));
// 	printf("%d\n",ft_atoi("123--^^^4ab567-"));
// }
