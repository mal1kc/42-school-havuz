#include <stdlib.h>

int	ft_strlen(char *str)
{
	int	len;

	len = 0;
	while (str[len] != '\0')
		len++;
	return (len);
}

int	ft_total_len(int size, char **strs, char *sep)
{
	int	len;
	int	i;

	len = 0;
	i = 0;
	while (i < size)
		len += ft_strlen(strs[i++]);
	len += (size - 1) * ft_strlen(sep) + 1;
	return (len);
}

char	*ft_strappend(char *dest, char *src, int *index)
{
	int	i;

	i = 0;
	while (src[i] != '\0')
		dest[(*index)++] = src[i++];
	return (dest);
}

char	*ft_strjoin(int size, char **strs, char *sep)
{
	int		i;
	int		index;
	int		total_len;
	char	*new_str;

	i = 0;
	index = 0;
	total_len = ft_total_len(size, strs, sep);
	if (size == 0)
		total_len = 1;
	new_str = malloc(sizeof(char) * total_len);
	if (!new_str)
		return (NULL);
	while (i < size)
	{
		ft_strappend(new_str, strs[i], &index);
		if (i++ < size - 1)
			ft_strappend(new_str, sep, &index);
	}
	new_str[index] = '\0';
	return (new_str);
}

// #include <stdio.h>
// #include <stdlib.h>
// int main()
// {
// 	char *strs[] = {"Hello", "world", "this", "is", "C"};
// 	char *sep = " - ";
// 	char *result = ft_strjoin(2, strs, sep);
// 	if (result)
// 	{
// 		printf("Result: %s\n", result);
// 		free(result);
// 	}
// 	else
// 		printf("Memory allocation failed\n");
// 	return (0);
// }
