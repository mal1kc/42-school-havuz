/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_alpha.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkokcan <mkokcan@student.42kocaeli.com.tr  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/03 13:37:13 by mkokcan           #+#    #+#             */
/*   Updated: 2025/03/05 12:19:50 by mkokcan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// int ft_str_is_alpha(char *str)
// {
// 	unsigned int counter;
//
// 	counter = 0;
// 	while (str[counter] != '\0')
// 	{
// 		if (!((str[counter] >= 'a' && str[counter] <= 'z')
//  || (str[counter] <= 'Z' && str[counter] >= 'A')))
// 		{
// 			return (0);
// 		}
// 		counter++;
// 	}
// 	return (1);
// }
//
// short ver

int	ft_str_is_alpha(char *str)
{
	while (*str != '\0')
	{
		if (!((*str >= 'a' && *str <= 'z') || (*str <= 'Z' && *str >= 'A')))
			return (0);
		str++;
	}
	return (1);
}
