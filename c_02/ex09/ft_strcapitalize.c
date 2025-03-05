/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcapitalize.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkokcan <mkokcan@student.42kocaeli.com.tr  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/05 12:22:22 by mkokcan           #+#    #+#             */
/*   Updated: 2025/03/05 12:22:37 by mkokcan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_chr_is_upcase(char chr)
{
	return (chr <= 'Z' && chr >= 'A');
}

int	ft_chr_is_lowcase(char chr)
{
	return (chr >= 'a' && chr <= 'z');
}

int	ft_chr_is_nbr(char chr)
{
	return (chr >= '0' && chr <= '9');
}

char	*ft_strcapitalize(char *str)
{
	int	i;
	int	is_first;
	int	is_up;
	int	is_low;

	i = 0;
	is_first = 1;
	while (str[i] != '\0')
	{
		is_low = ft_chr_is_lowcase(str[i]);
		is_up = ft_chr_is_upcase(str[i]);
		if (is_first && is_low)
			str[i] += ('A' - 'a');
		else if (!is_first && is_up)
			str[i] += ('a' - 'A');
		is_first = 0;
		if (!(is_low || is_up || ft_chr_is_nbr(str[i])))
			is_first = 1;
		i++;
	}
	return (str);
}
