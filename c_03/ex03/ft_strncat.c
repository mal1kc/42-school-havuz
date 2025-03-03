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
