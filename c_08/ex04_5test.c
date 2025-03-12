#include "ft_stock_str.h"
#include <stdlib.h>
int main(int argc, char **argv)
{
	t_stock_str *s_arr;

	s_arr = ft_strs_to_tab(argc, argv);
	ft_show_tab(s_arr);
	free(s_arr);
}
