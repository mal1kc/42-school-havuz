/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkokcan <mkokcan@student.42kocaeli.com.tr  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/05 12:44:51 by mkokcan           #+#    #+#             */
/*   Updated: 2025/03/05 12:44:52 by mkokcan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

char	*ft_strstr(char *str, char *to_find)
{
	unsigned int	c1;
	unsigned int	c2;

	if (*to_find == '\0')
		return (str);
	c1 = 0;
	c2 = 0;
	while (str[c1] != '\0')
	{
		c2 = 0;
		while (str[c1 + c2] == to_find[c2])
		{
			if (to_find[c2 + 1] != '\0')
			{
				return (&str[c1]);
			}
			c2++;
		}
		c1++;
	}
	return (NULL);
}
