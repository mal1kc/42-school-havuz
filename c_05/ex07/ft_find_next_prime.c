int	ft_is_prime(int nb)
{
	unsigned int	helper;

	if (nb <= 1)
		return (0);
	helper = nb - 1;
	while (helper > 1)
	{
		if (nb % helper == 0)
			return (0);
		helper--;
	}
	return (1);
}

int	ft_find_next_prime(int nb)
{
	int	helper;

	helper = ft_is_prime(nb);
	while (!helper)
		helper = ft_is_prime(++nb);
	return (nb);
}

// #include <stdio.h>
// int main(void)
// {
// 	printf("%d\n", ft_find_next_prime(49));
// 	printf("%d\n", ft_find_next_prime(11));
// 	printf("%d\n", ft_find_next_prime(99));
// 	printf("%d\n", ft_find_next_prime(9));
// 	printf("%d\n", ft_find_next_prime(3));
// 	printf("%d\n", ft_find_next_prime(14));
// 	printf("%d\n", ft_find_next_prime(1));
//
// 	return (0);
// }
