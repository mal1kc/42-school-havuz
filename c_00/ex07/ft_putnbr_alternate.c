#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putnbr(int nb)
{
	if (nb == -2147483648)
	{
		ft_putchar('-');
		ft_putchar('2');
		nb = 147483648;
	}
	if (nb < 0)
	{
		ft_putchar('-');
		nb = -nb;
	}
	if (nb > 10)
	{
		ft_putnbr(nb / 10);
		ft_putnbr(nb % 10);
	}
	else
	{
		ft_putchar(nb + '0');
	}
}

int	main(void)
{
	ft_putnbr(2147483647);
	ft_putchar('\n');
	ft_putnbr(-2147483648);
	ft_putchar('\n');
	ft_putnbr(-1111111111);
	ft_putchar('\n');
	ft_putnbr(-100000000);
	ft_putchar('\n');
	ft_putnbr(15928);
	return (0);
}
