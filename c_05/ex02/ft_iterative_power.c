/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_iterative_power.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkokcan <mkokcan@student.42kocaeli.com.tr  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/08 16:47:10 by mkokcan           #+#    #+#             */
/*   Updated: 2025/03/08 16:47:11 by mkokcan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_iterative_power(int nb, int power)
{
	int	res;

	if (power < 0)
		return (0);
	if (power == 0 && nb == 0)
		return (1);
	res = 1;
	while (power > 0)
	{
		power--;
		res = res * nb;
	}
	return (res);
}

// #include <stdio.h>
// int main(void)
// {
// 	printf("%d\n", ft_iterative_power(3, 3));
// 	printf("%d\n", ft_iterative_power(0, 0));
// 	printf("%d\n", ft_iterative_power(3, 0));
// 	printf("%d\n", ft_iterative_power(3, -2));
// 	printf("%d\n", ft_iterative_power(1, 10));
// 	printf("%d\n", ft_iterative_power(10, 2));
// 	return (0);
// }
