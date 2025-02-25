#include <unistd.h>

void	ft_put_char(char c)
{
	write(1, &c, 1);
}

void	ft_print_comb2(void)
{
	char	i_0;
	char	i_1;

	i_0 = 0;
	while (i_0 != 99)
	{
		i_1 = i_0 + 1;
		while (i_1 != 100)
		{
			ft_put_char('0' + (i_0 / 10));
			ft_put_char('0' + (i_0 % 10));
			ft_put_char(' ');
			ft_put_char('0' + (i_0 / 10));
			ft_put_char('0' + (i_1 % 10));
			if (i_0 != 98)
				write(1, ", ", 2);
			i_1++;
		}
		i_0++;
	}
}

int	main(void)
{
	ft_print_comb2();
}
