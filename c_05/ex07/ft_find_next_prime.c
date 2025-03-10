/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_find_next_prime.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkokcan <mkokcan@student.42kocaeli.com.tr  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/08 16:48:02 by mkokcan           #+#    #+#             */
/*   Updated: 2025/03/09 17:46:12 by mkokcan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_is_prime(int nb)
{
	unsigned int	helper;

	if (nb <= 1)
		return (0);
	helper = nb - 1;
	while (helper > 1)
	{
		if (nb % helper == 0)
			return (0);
		helper--;
	}
	return (1);
}

int	ft_find_next_prime(int nb)
{
	while (!ft_is_prime(nb))
		++nb;
	return (nb);
}

// #include <stdio.h>
// int main(void)
// {
// 	printf("%d\n", ft_find_next_prime(49));
// 	printf("%d\n", ft_find_next_prime(11));
// 	printf("%d\n", ft_find_next_prime(99));
// 	printf("%d\n", ft_find_next_prime(9));
// 	printf("%d\n", ft_find_next_prime(3));
// 	printf("%d\n", ft_find_next_prime(14));
// 	printf("%d\n", ft_find_next_prime(1));
//
// 	return (0);
// }
