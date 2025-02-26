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
