/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkokcan <mkokcan@student.42kocaeli.com.tr  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/05 12:44:32 by mkokcan           #+#    #+#             */
/*   Updated: 2025/03/05 12:44:34 by mkokcan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

unsigned int	ft_strlen(char *str)
{
	unsigned int	count;

	count = 0;
	while (str[count] != '\0')
	{
		count++;
	}
	return (count);
}

char	*ft_strcat(char *dest, char *src)
{
	char			*dest_end;
	unsigned int	c1;

	dest_end = dest + ft_strlen(dest);
	c1 = 0;
	while (src[c1] != '\0')
	{
		dest_end[c1] = src[c1];
		c1++;
	}
	dest_end[c1] = '\0';
	return (dest);
}
