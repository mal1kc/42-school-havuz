/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_int_tab.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkokcan <mkokcan@student.42kocaeli.com.tr  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/26 13:13:05 by mkokcan           #+#    #+#             */
/*   Updated: 2025/02/26 13:13:41 by mkokcan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_swap(int *a, int *b)
{
	int	c;

	c = *a;
	*a = *b;
	*b = c;
}

void	ft_sort_int_tab(int *tab, int size)
{
	int	counter_0;
	int	counter_1;

	counter_0 = 0;
	counter_1 = 0;
	while (counter_0 < size - 1)
	{
		counter_1 = 0;
		while (counter_1 < size - counter_0 - 1)
		{
			if (tab[counter_1] > tab[counter_1 + 1])
			{
				ft_swap(&tab[counter_1], &tab[counter_1 + 1]);
			}
			counter_1++;
		}
		counter_0++;
	}
}
