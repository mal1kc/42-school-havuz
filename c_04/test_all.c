#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int		ft_strlen(char *str);

void	ft_putstr(char *str);

void	ft_putnbr(int nb);

int		ft_atoi(char *str);
void	ft_putnbr_base(int nbr, char *base);

void	assert_int(int expected, int actual, const char *test_descp)
{
	if (expected == actual)
	{
		return ;
		printf("PASS: %s -> expected: %d, actual: %d\n", test_descp, expected,
			actual);
	}
	else
	{
		printf("FAIL: %s -> expected: %d, actual: %d\n", test_descp, expected,
			actual);
	}
}

int	mft_atoi(char *str)
{
	int	isaret;
	int	nb;

	while ((*str >= 9 && *str <= 13) || *str == 32)
		str++;
	isaret = 1;
	while (*str == '+' || *str == '-')
	{
		if (*str == '-')
			isaret = -isaret;
		str++;
	}
	nb = 0;
	while (*str >= '0' && *str <= '9')
	{
		nb *= 10;
		nb += *str - '0';
		str++;
	}
	return (nb * isaret);
}

void	assert_str(char *expected, char *actual, const char *test_descp)
{
	if (expected == actual)
	{
		return ;
	}
	if (strcmp(expected, actual) == 0)
	{
		printf("PASS: %s -> expected: %s, actual: %s\n", test_descp, expected,
			actual);
	}
	else
	{
		printf("FAIL: %s -> expected: %s, actual: %s\n", test_descp, expected,
			actual);
	}
}

int	main(void)
{
	// Test for ft_strlen
	assert_int(strlen("Hello"), ft_strlen("Hello"),
		"Test ft_strlen with 'Hello'");
	assert_int(strlen(""), ft_strlen(""),
		"Test ft_strlen with an empty string");
	assert_int(strlen("Hello!"), ft_strlen("Hello!"),
		"Test ft_strlen with 'Hello!'");
	// Test for ft_atoi
	assert_int(atoi("42"), ft_atoi("42"),
		"Test ft_atoi with positive number '42'");
	assert_int(atoi("-42"), ft_atoi("-42"),
		"Test ft_atoi with negative number '-42'");
	// mft_atoi is passing --42 to 42
	assert_int(atoi("--42"), ft_atoi("--42"),
		"Test ft_atoi with multiple negative signs '--42'");
	assert_int(atoi("0"), ft_atoi("0"), "Test ft_atoi with '0'");
	assert_int(atoi("  42"), ft_atoi("  42"),
		"Test ft_atoi with leading spaces '  42'");
	assert_int(atoi("  +42"), ft_atoi("  +42"),
		"Test ft_atoi with leading '+' '  +42'");
	assert_int(atoi("NotNumber"), ft_atoi("NotNumber"),
		"Test ft_atoi with non-numeric string");
	assert_int(atoi(""), ft_atoi(""), "Test ft_atoi with empty string");
	assert_int(atoi("   -42"), ft_atoi("   -42"),
		"Test ft_atoi with leading spaces and negative number '   -42'");
	assert_int(atoi("42abc"), ft_atoi("42abc"),
		"Test ft_atoi with valid number followed by non-numeric characters '42abc'");
	// mft_atoi is passing -+42 to -42
	assert_int(atoi("-+42"), ft_atoi("-+42"),
		"Test ft_atoi with multiple signs '-+42'");
	assert_int(atoi("2147483647"), ft_atoi("2147483647"),
		"Test ft_atoi with very large number '2147483647'");
	assert_int(atoi("-2147483648"), ft_atoi("-2147483648"),
		"Test ft_atoi with very large negative number '-2147483648'");
	assert_int(atoi("000042"), ft_atoi("000042"),
		"Test ft_atoi with leading zeros '000042'");
	assert_int(atoi("42   "), ft_atoi("42   "),
		"Test ft_atoi with valid number followed by spaces '42   '");
	assert_int(atoi("  +42  "), ft_atoi("  +42  "),
		"Test ft_atoi with spaces and '+' at both ends '  +42  '");
	assert_int(atoi("     "), ft_atoi("     "),
		"Test ft_atoi with string containing only spaces");
	assert_int(atoi("12c123"), ft_atoi("12c123"),
		"Test ft_atoi with non-numeric characters at the start");
	// Test for ft_putstr (manual verification required, just printing)
	printf("Test ft_putstr with 'Hello World!':\n");
	ft_putstr("Hello World!\n");
	// Test for ft_putnbr (manual verification required, just printing)
	printf("Test ft_putnbr with 123:\n");
	ft_putnbr(123);
	printf("\n");
	printf("Test ft_putnbr with -123:\n");
	ft_putnbr(-123);
	printf("\n");
	printf("Test ft_putnbr with 0:\n");
	ft_putnbr(0);
	printf("\n");
	ft_putnbr_base(42, "0123456789");
	printf("\n");
	ft_putnbr_base(-42, "0123456789");
	printf("\n");
	ft_putnbr_base(0, "0123456789");
	printf("\n");
	ft_putnbr_base(42, "01");
	printf("\n");
	ft_putnbr_base(-42, "01");
	printf("\n");
	ft_putnbr_base(42, "0123456789ABCDEF");
	printf("\n");
	ft_putnbr_base(-42, "0123456789ABCDEF");
	printf("\n");
	ft_putnbr_base(123456, "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ");
	printf("\n");
	ft_putnbr_base(2147483647, "0123456789");
	printf("\n");
	ft_putnbr_base(-2147483648, "0123456789");
	printf("\n");
	ft_putnbr_base(354775807, "01");
	printf("\n");
	ft_putnbr_base(42, "ABCDEFGH");
	printf("\n");
	ft_putnbr_base(42, "01234+6789");
	printf("\n");
	ft_putnbr_base(42, "01234456789");
	printf("\n");
	ft_putnbr_base(42, "0");
	printf("\n");
	ft_putnbr_base(0, "0123456789");
	printf("\n");
	return (0);
}
