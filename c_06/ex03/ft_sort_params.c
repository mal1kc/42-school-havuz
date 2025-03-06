#include <unistd.h>

int	ft_strcmp(char *s1, char *s2)
{
	while (*s1 && (*s1 == *s2))
	{
		s1++;
		s2++;
	}
	return (*(unsigned char *)s1 - *(unsigned char *)s2);
}

void	swap(char **a, char **b)
{
	char	*temp;

	temp = *a;
	*a = *b;
	*b = temp;
}

void	bubble_sort(char *arr[], int n)
{
	int	c1;
	int	c2;

	c1 = 0;
	while (c1 < n - 1)
	{
		c2 = 0;
		while (c2 < n - c1 - 1)
		{
			if (ft_strcmp(arr[c2], arr[c2 + 1]) > 0)
				swap(&arr[c2], &arr[c2 + 1]);
			c2++;
		}
		c1++;
	}
}

int	main(int argc, char *argv[])
{
	int	pname_len;
	int	p_indx;

	if (argc == 1)
		return (0);
	bubble_sort(argv + 1, argc - 1);
	p_indx = 1;
	while (p_indx < argc)
	{
		pname_len = 0;
		while (argv[p_indx][pname_len] != '\0')
			pname_len++;
		write(1, argv[p_indx], pname_len);
		write(1, "\n", 1);
		p_indx++;
	}
	return (0);
}
