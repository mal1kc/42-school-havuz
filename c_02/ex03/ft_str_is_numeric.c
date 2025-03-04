// int ft_str_is_numeric(char *str)
// {
// 	unsigned int counter;
//
// 	counter = 0;
// 	while (str[counter] != '\0')
// 	{
// 		if (!(str[counter] >= '0' && str[counter] <= '9'))
// 			return (0);
// 		counter++;
// 	}
// 	return (1);
// }
//
int ft_str_is_numeric(char *str)
{
	while (*str != '\0')
	{
		if (!(*str >= '0' && *str <= '9'))
			return (0);
		str++;
	}
	return (1);
}
