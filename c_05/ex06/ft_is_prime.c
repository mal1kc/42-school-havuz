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

// #include <stdio.h>
// int main(void)
// {
// 	printf("%d\n", ft_is_prime(49));
// 	printf("%d\n", ft_is_prime(11));
// 	printf("%d\n", ft_is_prime(7));
// 	printf("%d\n", ft_is_prime(9));
// 	printf("%d\n", ft_is_prime(3));
// 	printf("%d\n", ft_is_prime(2));
// 	printf("%d\n", ft_is_prime(1));
//
// 	return (0);
// }
