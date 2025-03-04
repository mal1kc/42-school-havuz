#include <bsd/string.h>
#include <stddef.h>
#include <stdio.h>

int	ft_strcmp(char *s1, char *s2);                                 // 00
int	ft_strncmp(char *s1, char *s2, unsigned int n);                // 01
char	*ft_strcat(char *dest, char *src);                            // 02
char	*ft_strncat(char *dest, char *src, unsigned int size);        // 03
char	*ft_strstr(char *str, char *to_find);                         // 04
unsigned int	ft_strlcat(char *dest, char *src, unsigned int size); // 05

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

void	assert_str(char *expected, char *actual, const char *test_descp)
{
	if (expected == actual)
	{
		return ;
		printf("PASS: %s -> expected: %s, actual: %s\n", test_descp, expected,
			actual);
		return ;
	}
	if (strcmp(expected, actual) == 0)
	{
		return ;
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
	char			dest1[20] = "Hello, ";
	char			dest2[20] = "Hello, ";
	char			dest3[20] = "Hello, ";
	unsigned int	len;
	char			dest_stdlib1[20] = "Hello, ";
	char			dest_ft1[20];
	char			dest_stdlib2[20] = "Hello, ";
	char			dest_ft2[20];
	char			dest_stdlib3[20] = "Hello, ";
	char			dest_ft3[20];
	unsigned int	len_stdlib;
	unsigned int	len_ft_actual;
	char			dest_stdlib4[20] = "";
	char			dest_ft4[20];
	char			dest_stdlib5[20] = "";
	char			dest_ft5[20];
	char			dest_stdlib6[5] = "Hi! ";
	char			dest_ft6[5];
	unsigned int	expected_len_stdlib6;
	unsigned int	actual_len_ft6;

	assert_int(0, ft_strcmp("hello", "hello"), "ft_strcmp: equal strings");
	assert_int(14, ft_strcmp("hello", "hella"), "ft_strcmp: different strings");
	assert_int(-14, ft_strcmp("hella", "hello"),
		"ft_strcmp: different strings");
	assert_int(0, ft_strncmp("hello", "hello", 5), "ft_strncmp: equal strings");
	assert_int(14, ft_strncmp("hello", "hella", 5),
		"ft_strncmp: different strings");
	assert_int(-14, ft_strncmp("hella", "hello", 5),
		"ft_strncmp: different strings");
	assert_int(0, ft_strncmp("hello", "hello", 3),
		"ft_strncmp: equal strings (partial)");
	assert_str("Hello, World!", ft_strcat(dest1, "World!"),
		"ft_strcat: concatenate strings");
	assert_str("Hello, Wor", ft_strncat(dest2, "World!", 3),
		"ft_strncat: concatenate first 3 characters");
	assert_str("World!", ft_strstr("Hello, World!", "World!"),
		"ft_strstr: find substring");
	assert_str(NULL, ft_strstr("Hello, World!", "NotFound"),
		"ft_strstr: substring not found");
	len = ft_strlcat(dest3, "World!", sizeof(dest3));
	assert_str("Hello, World!", dest3,
		"ft_strlcat: concatenate with size limit");
	assert_int(13, len, "ft_strlcat: total length after concatenation");
	// ASK
	assert_int(strcmp("hello", "hello"), ft_strcmp("hello", "hello"),
		"ft_strcmp vs strcmp: equal strings");
	assert_int(strcmp("hello", "hella"), ft_strcmp("hello", "hella"),
		"ft_strcmp vs strcmp: different strings");
	assert_int(strcmp("hella", "hello"), ft_strcmp("hella", "hello"),
		"ft_strcmp vs strcmp: different strings");
	assert_int(strncmp("hello", "hello", 5), ft_strncmp("hello", "hello", 5),
		"ft_strncmp vs strncmp: equal strings");
	assert_int(strncmp("hello", "hella", 5), ft_strncmp("hello", "hella", 5),
		"ft_strncmp vs strncmp: different strings");
	assert_int(strncmp("hella", "hello", 5), ft_strncmp("hella", "hello", 5),
		"ft_strncmp vs strncmp: different strings");
	assert_int(strncmp("hello", "hello", 3), ft_strncmp("hello", "hello", 3),
		"ft_strncmp vs strncmp: partial strings");
	strcpy(dest_ft1, dest_stdlib1);
	assert_str(strcat(dest_stdlib1, "World!"), ft_strcat(dest_ft1, "World!"),
		"ft_strcat vs strcat: concatenate strings");
	strcpy(dest_ft2, dest_stdlib2);
	assert_str(strncat(dest_stdlib2, "World!", 3), ft_strncat(dest_ft2,
			"World!", 3),
		"ft_strncat vs strncat: concatenate first 3 characters");
	assert_str(strstr("Hello, World!", "World!"), ft_strstr("Hello, World!",
			"World!"), "ft_strstr vs strstr: find substring");
	assert_str(strstr("Hello, World!", "NotFound"), ft_strstr("Hello, World!",
			"NotFound"), "ft_strstr vs strstr: substring not found");
	strcpy(dest_ft3, dest_stdlib3);
	len_stdlib = strlcat(dest_stdlib3, "World!", sizeof(dest_stdlib3));
	len_ft_actual = ft_strlcat(dest_ft3, "World!", sizeof(dest_ft3));
	assert_str(dest_ft3, dest_stdlib3,
		"ft_strlcat vs strlcat: concatenate with size limit");
	assert_int(len_stdlib, len_ft_actual,
		"ft_strlcat vs strlcat: total length after concatenation");
	assert_int(strcmp("", ""), ft_strcmp("", ""),
		"ft_strcmp vs strcmp: empty strings");
	assert_int(strcmp("", "hello"), ft_strcmp("", "hello"),
		"ft_strcmp vs strcmp: empty string vs non-empty");
	assert_int(strcmp("hello", ""), ft_strcmp("hello", ""),
		"ft_strcmp vs strcmp: non-empty string vs empty");
	assert_int(strncmp("", "", 0), ft_strncmp("", "", 0),
		"ft_strncmp vs strncmp: empty strings");
	assert_int(strncmp("hello", "", 0), ft_strncmp("hello", "", 0),
		"ft_strncmp vs strncmp: empty string vs part of non-empty");
	assert_int(strncmp("", "hello", 5), ft_strncmp("", "hello", 5),
		"ft_strncmp vs strncmp: empty string vs non-empty");
	strcpy(dest_ft4, dest_stdlib4);
	assert_str(strcat(dest_stdlib4, "World!"), ft_strcat(dest_ft4, "World!"),
		"ft_strcat vs strcat: empty destination");
	strcpy(dest_ft5, dest_stdlib5);
	assert_str(strncat(dest_stdlib5, "World!", 3), ft_strncat(dest_ft5,
			"World!", 3), "ft_strncat vs strncat: empty destination");
	assert_str(strstr("Hello, World!", ""), ft_strstr("Hello, World!", ""),
		"ft_strstr vs strstr: empty string as substring");
	assert_str(strstr("", "hello"), ft_strstr("", "hello"),
		"ft_strstr vs strstr: search for substring in empty string");
	strcpy(dest_ft6, dest_stdlib6);
	expected_len_stdlib6 = strlcat(dest_stdlib6, "there", sizeof(dest_stdlib6));
	actual_len_ft6 = ft_strlcat(dest_ft6, "there", sizeof(dest_ft6));
	assert_str(dest_stdlib6, dest_ft6, "ft_strlcat vs strlcat: small buffer");
	assert_int(expected_len_stdlib6, actual_len_ft6,
		"ft_strlcat vs strlcat: total length after concatenation");
	return (0);
}
