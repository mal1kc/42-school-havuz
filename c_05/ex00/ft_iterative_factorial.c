/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_iterative_factorial.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkokcan <mkokcan@student.42kocaeli.com.tr  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/08 16:46:55 by mkokcan           #+#    #+#             */
/*   Updated: 2025/03/09 17:34:50 by mkokcan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_iterative_factorial(int nb)
{
	int	res;

	res = 0;
	if (nb < 0)
		return (0);
	if (nb == 0 || nb == 1)
		return (1);
	res = 1;
	while (nb > 0)
	{
		res = res * nb;
		nb--;
	}
	return (res);
}

// #include <stdio.h>
// int main(void)
// {
//	printf("%d\n", ft_iterative_factorial(3));
//	printf("%d\n", ft_iterative_factorial(-1));
//	printf("%d\n", ft_iterative_factorial(0));
//	printf("%d\n", ft_iterative_factorial(2));
//	printf("%d\n", ft_iterative_factorial(5));
// }
