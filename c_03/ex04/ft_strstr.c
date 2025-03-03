#include <stddef.h>

char	*ft_strstr(char *str, char *to_find)
{
	unsigned int	c1;
	unsigned int	c2;

	if (*to_find == '\0')
		return (str);
	c1 = 0;
	c2 = 0;
	while (str[c1] != '\0')
	{
		c2 = 0;
		while (str[c1 + c2] == to_find[c2])
		{
			if (to_find[c2 + 1] != '\0')
			{
				return (&str[c1]);
			}
			c2++;
		}
		c1++;
	}
	return (NULL);
}
