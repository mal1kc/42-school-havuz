#include <unistd.h>

void	ft_put_char(char f, char s, char t)
{
	write(1, &f, 1);
	write(1, &s, 1);
	write(1, &t, 1);
	if (f != '7' && s != '8' && t != '9')
	{
		f = ',';
		write(1, &f, 1);
		f = ' ';
		write(1, &f, 1);
	}
}

void	ft_print_comb(void)
{
	char	f;
	char	s;
	char	t;

	f = '0';
	while (f != '7')
	{
		s = f + 1;
		while (s != '8')
		{
			t = s + 1;
			while (t != '9')
			{
				ft_put_char(f, s, t);
				t++;
			}
			s++;
		}
		f++;
	}
	ft_put_char(f, s, t);
}

int	main(void)
{
	ft_print_comb();
}
