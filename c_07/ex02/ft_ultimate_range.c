#include <stdlib.h>
int ft_ultimate_range(int **range, int min, int max)
{
	int  write_counter;
	int *arr;
	int  len;

	*range = NULL;
	if (min >= max)
		return (0);
	len = (max - min);
	arr = malloc(sizeof(int) * len);
	if (arr == NULL)
		return (-1);
	*range = arr;
	write_counter = 0;
	while (write_counter < len)
	{
		arr[write_counter] = min + write_counter;
		write_counter++;
	}
	return (len);
}

// #include <stdio.h>
// int main(void)
// {
// 	int *arr;
// 	int  arr_len;
// 	int  a_indx;
//
// 	a_indx = 0;
// 	arr_len = ft_ultimate_range(&arr, -3, 5);
// 	while (a_indx < arr_len)
// 	{
// 		printf("%d\t", arr[a_indx]);
// 		a_indx++;
// 	}
// 	printf("\n");
// 	return 0;
// }
