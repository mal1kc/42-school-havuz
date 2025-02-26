char	*ft_strncpy(char *dest, char *src, unsigned int n)
{
	unsigned int	counter;

	counter = 0;
	while (src[counter] != '\0')
	{
		if (counter == n)
		{
			break ;
		}
		dest[counter] = src[counter];
		counter++;
	}
	dest[counter] = '\0';
	return (dest);
}
