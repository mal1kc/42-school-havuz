/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkokcan <mkokcan@student.42kocaeli.com.tr  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/06 11:22:20 by mkokcan           #+#    #+#             */
/*   Updated: 2025/03/06 11:34:02 by mkokcan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


char	*ft_strdup(char	*src)
{
	unsigned int counter;
	unsigned int writer;
	char	*target;
	
	counter = 0;
	writer = 0;
	while(src[counter] != '\0')
	{
		counter++;
	}
	
	target =(char *) malloc(sizeof(char) * counter);
	if(target == (NULL))
	{
		return (target);
	}
	while(writer < counter)
	{
		target[writer] = src[writer];
		writer++;
	}
	target[writer] = '\0';
	return (target);
}
