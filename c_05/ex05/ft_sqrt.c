int	ft_sqrt(int nb)
{
	int	helper;

	if (nb == 0 || nb == 1)
		return (nb);
	helper = 2;
	while (helper * helper < nb)
		helper++;
	if (helper * helper == nb)
		return (helper);
	return (0);
}

// #include <stdio.h>
// int main(void)
// {
// 	printf("%d\n", ft_sqrt(49));
// 	printf("%d\n", ft_sqrt(16));
// 	printf("%d\n", ft_sqrt(32));
// 	printf("%d\n", ft_sqrt(92));
// 	printf("%d\n", ft_sqrt(144));
// 	printf("%d\n", ft_sqrt(2));
// 	printf("%d\n", ft_sqrt(1));
// 	printf("%d\n", ft_sqrt(-49));
// 	return (0);
// }
