#include <unistd.h>

int	main(int argc, char *argv[])
{
	unsigned int	pname_len;

	pname_len = 0;
	(void)argc;
	while (argv[0][pname_len] != '\0')
		pname_len++;
	write(1, argv[0], pname_len);
	write(1, "\n", 1);
	return (0);
}
