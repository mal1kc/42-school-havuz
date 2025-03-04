int	ft_strncmp(char *s1, char *s2, unsigned int n)
{
	unsigned int	c;

	c = 0;
	while (s1[c] != '\0' && s2[c] != '\0' && c < n)
	{
		if (s1[c] != s2[c])
		{
			return (s1[c] - s2[c]);
		}
		c++;
	}
	if (c == n)
		return (0);
	return (s1[c] - s2[c]);
}
