/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkokcan <mkokcan@student.42kocaeli.com.tr  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/26 12:47:20 by mkokcan           #+#    #+#             */
/*   Updated: 2025/02/26 12:47:29 by mkokcan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putstr(char *str)
{
	int	coutn;

	coutn = 0;
	while (str[coutn] != '\0')
	{
		coutn++;
	}
	write(1, str, coutn);
}
