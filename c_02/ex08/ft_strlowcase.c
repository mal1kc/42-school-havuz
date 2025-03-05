/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdowncase.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkokcan <mkokcan@student.42kocaeli.com.tr  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/03 13:38:02 by mkokcan           #+#    #+#             */
/*   Updated: 2025/03/03 13:38:04 by mkokcan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_chr_is_uppercase(char chr)
{
	return (chr >= 'A' && chr <= 'Z');
}

char	*ft_strlowcase(char *str)
{
	char	*orginal;

	orginal = str;
	while (*str != '\0')
	{
		if (ft_chr_is_uppercase(*str) == 1)
			*str = *str + 32;
		str++;
	}
	return (orginal);
}
