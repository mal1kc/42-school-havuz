/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rev_int_tab.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkokcan <mkokcan@student.42kocaeli.com.tr  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/26 13:10:43 by mkokcan           #+#    #+#             */
/*   Updated: 2025/02/26 13:12:01 by mkokcan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_rev_int_tab(int *tab, int size)
{
	int	counter;
	int	temp;

	counter = 0;
	while (counter <= size / 2)
	{
		temp = tab[counter];
		tab[counter] = tab[size - counter - 1];
		tab[size - counter - 1] = temp;
		counter++;
	}
}
