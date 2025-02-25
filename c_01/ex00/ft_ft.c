#include <stdio.h>

void	ft_ft(int *nbr)
{
	*nbr = 42;
}

int	main(void)
{
	int	nb;

	nb = 21;
	ft_ft(&nb);
	printf("%d\n", nb);
	return (0);
}
