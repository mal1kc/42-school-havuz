#include <stdio.h>

void	ft_swap(int *a, int *b)
{
	int	c;

	c = *a;
	*a = *b;
	*b = c;
}

void	ft_sort_int_tab(int *tab, int size)
{
	int	counter_0;
	int	counter_1;

	counter_0 = 0;
	counter_1 = 0;
	while (counter_0 < size - 1)
	{
		counter_1 = 0;
		while (counter_1 < size - counter_0 - 1)
		{
			if (tab[counter_1] > tab[counter_1 + 1])
			{
				ft_swap(&tab[counter_1], &tab[counter_1 + 1]);
			}
			counter_1++;
		}
		counter_0++;
	}
}

int	main(void)
{
	int	i;
	int	arr[10] = {10, 323, 33, 50, 40, 500, 30, 20, 10, 3};

	i = 0;
	// int arr[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
	i = 0;
	while (i < 10)
	{
		printf("%d\n", arr[i]);
		i++;
	}
	printf("----\n");
	ft_sort_int_tab(arr, 10);
	printf("----\n");
	i = 0;
	while (i < 10)
	{
		printf("%d\n", arr[i]);
		i++;
	}
	return (0);
}
