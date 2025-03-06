/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkokcan <mkokcan@student.42kocaeli.com.tr  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/05 12:45:46 by mkokcan           #+#    #+#             */
/*   Updated: 2025/03/05 14:45:24 by mkokcan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

unsigned int	ft_strlcat(char *dest, char *src, unsigned int size)
{
	unsigned int	dst_len;
	unsigned int	src_len;
	unsigned int	c1;

	dst_len = 0;
	src_len = 0;
	c1 = 0;
	while (dest[dst_len] != '\0' && dst_len < size)
		dst_len++;
	while (src[src_len] != '\0')
		src_len++;
	if (size <= dst_len)
		return (size + src_len);
	while (c1 < (size - dst_len - 1) && src[c1] != '\0')
	{
		dest[dst_len + c1] = src[c1];
		c1++;
	}
	dest[dst_len + c1] = '\0';
	return (dst_len + src_len);
}
