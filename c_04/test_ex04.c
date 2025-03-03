#include <stdio.h>
#include <string.h>

void	ft_putnbr_base(int nbr, char *base);
int	test_check_base(char *base, int *base_len)
{
	unsigned int	c1;
	unsigned int	c2;

	c1 = 0;
	while (base[c1] != '\0')
	{
		if (base[c1] == '-' || base[c1] == '+')
			return (0);
		if (c1 > 1)
		{
			c2 = c1 - 1;
			while (c2 > 0)
			{
				if (base[c1] == base[c2])
					return (0);
				c2--;
			}
		}
		c1++;
	}
	*base_len = c1;
	return (c1 > 1);
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

char	*nbr_base(int nbr, char *base, char *result)
{
	int	base_len;
	int	rev_result[32];
	int	c;
	int	res_wrt;

	res_wrt = 0;
	c = 0;
	if (!test_check_base(base, &base_len))
		return (result);
	if (nbr == -2147483648)
	{
		result[res_wrt] = '-';
		res_wrt++;
		result[res_wrt] = base[2 % base_len];
		res_wrt++;
		nbr = 147483648;
	}
	if (nbr == 0)
	{
		result[res_wrt] = base[0];
		res_wrt++;
	}
	if (nbr < 0)
	{
		result[res_wrt] = '-';
		res_wrt++;
		nbr = -nbr;
	}
	while (nbr > 0)
	{
		rev_result[c] = base[nbr % base_len];
		nbr = nbr / base_len;
		c++;
	}
	while (c > 0)
	{
		c--;
		result[res_wrt] = rev_result[c];
		res_wrt++;
	}
	result[res_wrt] = '\0';
	return (result);
}

int	main(void)
{
	char	result[32];
	char	empty_result[32];

	strcpy(result, empty_result);
	assert_str("42", nbr_base(42, "0123456789", result), "test 00");
	strcpy(result, empty_result);
	assert_str("-42", nbr_base(-42, "0123456789", result), "test 01");
	strcpy(result, empty_result);
	assert_str("0", nbr_base(0, "0123456789", result), "test 02");
	strcpy(result, empty_result);
	assert_str("", nbr_base(0, "0", result), "test 08");
	strcpy(result, empty_result);
	assert_str("101010", nbr_base(42, "01", result), "test 06");
	strcpy(result, empty_result);
	assert_str("4", nbr_base(4,
			"0123456789abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ",
			result), "test 05");
	strcpy(result, empty_result);
	assert_str("-2A", nbr_base(-42, "0123456789ABCDEF", result), "test 09");
	strcpy(result, empty_result);
	assert_str("1120", nbr_base(42, "012", result), "test 10");
	strcpy(result, empty_result);
	assert_str("k", nbr_base(10, "abcdefghijklmnopqrstuvwxyz", result),
		"test 04");
	return (0);
}
