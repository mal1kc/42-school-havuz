#include <stdio.h>
#include <string.h>

int ft_strlen(char *str);

void ft_putstr(char *str);

void ft_putnbr(int nb);

int ft_atoi(char *str);

void assert_int(int expected, int actual, const char *test_descp)
{
	if (expected == actual)
	{
		printf("PASS: %s -> expected: %d, actual: %d\n", test_descp, expected, actual);
	}
	else
	{
		printf("FAIL: %s -> expected: %d, actual: %d\n", test_descp, expected, actual);
	}
}

void assert_str(char *expected, char *actual, const char *test_descp)
{
	if (expected == actual)
	{
		printf("PASS: %s -> expected: %s, actual: %s\n", test_descp, expected, actual);
		return;
	}
	if (strcmp(expected, actual) == 0)
	{
		printf("PASS: %s -> expected: %s, actual: %s\n", test_descp, expected, actual);
	}
	else
	{
		printf("FAIL: %s -> expected: %s, actual: %s\n", test_descp, expected, actual);
	}
}

int main()
{
	// Test for ft_strlen
	assert_int(5, ft_strlen("Hello"), "Test ft_strlen with 'Hello'");
	assert_int(0, ft_strlen(""), "Test ft_strlen with an empty string");
	assert_int(6, ft_strlen("Hello!"), "Test ft_strlen with 'Hello!'");

	// Test for ft_atoi
	assert_int(42, ft_atoi("42"), "Test ft_atoi with positive number '42'");
	assert_int(-42, ft_atoi("-42"), "Test ft_atoi with negative number '-42'");
	assert_int(42, ft_atoi("--42"), "Test ft_atoi with multiple negative signs '--42'");
	assert_int(0, ft_atoi("0"), "Test ft_atoi with '0'");
	assert_int(42, ft_atoi("  42"), "Test ft_atoi with leading spaces '  42'");
	assert_int(42, ft_atoi("  +42"), "Test ft_atoi with leading '+' '  +42'");
	assert_int(0, ft_atoi("NotNumber"), "Test ft_atoi with non-numeric string");
	assert_int(0, ft_atoi(""), "Test ft_atoi with empty string");
	assert_int(-42, ft_atoi("   -42"), "Test ft_atoi with leading spaces and negative number '   -42'");
	assert_int(42, ft_atoi("42abc"), "Test ft_atoi with valid number followed by non-numeric characters '42abc'");
	assert_int(-42, ft_atoi("-+42"), "Test ft_atoi with multiple signs '-+42'");
	assert_int(2147483647, ft_atoi("2147483647"), "Test ft_atoi with very large number '2147483647'");
	assert_int(-2147483648, ft_atoi("-2147483648"), "Test ft_atoi with very large negative number '-2147483648'");
	assert_int(42, ft_atoi("000042"), "Test ft_atoi with leading zeros '000042'");
	assert_int(42, ft_atoi("42   "), "Test ft_atoi with valid number followed by spaces '42   '");
	assert_int(42, ft_atoi("  +42  "), "Test ft_atoi with spaces and '+' at both ends '  +42  '");
	assert_int(0, ft_atoi("     "), "Test ft_atoi with string containing only spaces");
	assert_int(12123, ft_atoi("12c123"), "Test ft_atoi with non-numeric characters at the start");

	// Test for ft_putstr (manual verification required, just printing)
	printf("\nTest ft_putstr with 'Hello World!': ");
	ft_putstr("Hello World!\n");

	// Test for ft_putnbr (manual verification required, just printing)
	printf("\nTest ft_putnbr with 123: ");
	ft_putnbr(123);
	printf("\n");

	printf("Test ft_putnbr with -123: ");
	ft_putnbr(-123);
	printf("\n");

	printf("Test ft_putnbr with 0: ");
	ft_putnbr(0);
	printf("\n");

	return 0;
}
