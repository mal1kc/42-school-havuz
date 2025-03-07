#include <stdlib.h>
int *ft_range(int min, int max)
{
	int *res_p;
	int  len;
	int  write_counter;

	if (min >= max)
		return NULL;
	len = max - min;
	if (len < 0)
		len = -len;

	res_p = malloc(sizeof(int) * len);
	write_counter = 0;
	while (write_counter < len)
	{
		res_p[write_counter] = min + write_counter;
		write_counter++;
	}
	return res_p;
}

// #include <stdio.h>
// int main(void)
// {
// 	int *a;
// 	int  a_indx;
//
// 	a_indx = 0;
// 	a = ft_range(-3, 10);
// 	while (a_indx < 13)
// 	{
// 		printf("%d\t", a[a_indx]);
// 		a_indx++;
// 	}
// 	printf("\n");
// 	return 0;
// }
