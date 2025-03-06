#include <unistd.h>

int	main(int argc, char *argv[])
{
	int	pname_len;
	int	p_indx;

	if (argc == 1)
		return (0);
	p_indx = argc - 1;
	while (p_indx > 0)
	{
		pname_len = 0;
		while (argv[p_indx][pname_len] != '\0')
			pname_len++;
		write(1, argv[p_indx], pname_len);
		write(1, "\n", 1);
		p_indx--;
	}
	return (0);
}
