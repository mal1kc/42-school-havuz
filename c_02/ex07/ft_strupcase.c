/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strupcase.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkokcan <mkokcan@student.42kocaeli.com.tr  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/03 13:37:51 by mkokcan           #+#    #+#             */
/*   Updated: 2025/03/03 13:37:57 by mkokcan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// 97  - 65  = 32
// 'a' - 'A' = 32

int	ft_chr_is_lowercase(char chr)
{
	return (chr >= 'a' && chr <= 'z');
}

char	*ft_strupcase(char *str)
{
	char	*orginal;

	orginal = str;
	while (*str != '\0')
	{
		if (ft_chr_is_lowercase(*str) == 1)
		{
			*str = *str - 32;
		}
		str++;
	}
	return (orginal);
}
