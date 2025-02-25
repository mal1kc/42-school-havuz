#include <unistd.h>

void	ft_putstr(char *str)
{
	int	coutn;

	coutn = 0;
	while (str[coutn] != '\0')
	{
		coutn++;
	}
	write(1, str, coutn);
}

int	main(void)
{
	ft_putstr("hello, 42");
	return (0);
}
