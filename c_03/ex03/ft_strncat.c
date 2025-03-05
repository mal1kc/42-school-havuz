/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkokcan <mkokcan@student.42kocaeli.com.tr  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/05 12:43:33 by mkokcan           #+#    #+#             */
/*   Updated: 2025/03/05 12:43:34 by mkokcan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strncat(char *dest, char *src, unsigned int size)
{
	char			*dest_end;
	unsigned int	c1;

	dest_end = dest;
	while (*dest_end != '\0')
	{
		dest_end++;
	}
	c1 = 0;
	while (src[c1] != '\0' && c1 < size)
	{
		dest_end[c1] = src[c1];
		c1++;
	}
	dest_end[c1] = '\0';
	return (dest);
}
