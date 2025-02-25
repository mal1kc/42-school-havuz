#include <stdio.h>

void	ft_rev_int_tab(int *tab, int size)
{
	int	counter;
	int	temp;

	counter = 0;
	while (counter <= size / 2)
	{
		temp = tab[counter];
		tab[counter] = tab[size - counter - 1];
		tab[size - counter - 1] = temp;
		counter++;
	}
}

int	main(void)
{
	int	i;
	int	arr[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};

	i = 0;
	i = 0;
	while (i < 10)
	{
		printf("%d\n", arr[i]);
		i++;
	}
	ft_rev_int_tab(arr, 10);
	i = 0;
	while (i < 10)
	{
		printf("%d\n", arr[i]);
		i++;
	}
	return (0);
}
