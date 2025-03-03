int ft_is_space(char chr)
{
	if (chr == ' ')
		return (1);
	if (chr == '\t')
		return (1);
	if (chr == '\n')
		return (1);
	if (chr == '\r')
		return (1);
	if (chr == '\f')
		return (1);
	if (chr == '\v')
		return (1);
	return (0);
}

int ft_char_is_numeric(char chr)
{
	return (chr >= '0' && chr <= '9');
}

int ft_atoi(char *str)
{
	int sign;
	int result;
	int indx;
	int str_len;

	sign = 1;
	indx = 0;
	result = 0;
	str_len = 0;
	while (str[str_len] != '\0')
		str_len++;
	while (indx < str_len)
	{
		if (str[indx] == '-')
		{
			indx++;
			sign *= -1;
			continue;
		}
		if (str[indx] == '+' || ft_is_space(str[indx]))
		{
			indx++;
			continue;
		}
		if (ft_char_is_numeric(str[indx]))
			result = (result * 10) + (str[indx] - '0');
		indx++;
	}
	return (result * sign);
}
