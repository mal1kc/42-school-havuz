int	ft_iterative_factorial(int nb)
{
	int	res;

	res = 0;
	if (nb <= 0)
	{
		return (res);
	}
	res = 1;
	while (nb > 0)
	{
		res = res * nb;
		nb--;
	}
	return (res);
}

// #include <stdio.h>
// int main(void)
// {
// 	printf("%d\n", ft_iterative_factorial(3));
// 	printf("%d\n", ft_iterative_factorial(-1));
// 	printf("%d\n", ft_iterative_factorial(0));
// 	printf("%d\n", ft_iterative_factorial(5));
// }
