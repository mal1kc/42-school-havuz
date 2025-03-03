#include <stddef.h>
#include <stdio.h>
#include <string.h>

int          ft_strcmp(char *s1, char *s2);                        // 00
int          ft_strncmp(char *s1, char *s2, unsigned int n);       // 01
char        *ft_strcat(char *dest, char *src);                     // 02
char        *ft_strncat(char *dest, char *src, unsigned int size); // 03
char        *ft_strstr(char *str, char *to_find);                  // 04
unsigned int ft_strlcat(char *dest, char *src, unsigned int size); // 05

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
	// Test ft_strcmp
	assert_int(0, ft_strcmp("hello", "hello"), "ft_strcmp: equal strings");
	assert_int(14, ft_strcmp("hello", "hella"), "ft_strcmp: different strings");
	assert_int(-14, ft_strcmp("hella", "hello"), "ft_strcmp: different strings");

	// Test ft_strncmp
	assert_int(0, ft_strncmp("hello", "hello", 5), "ft_strncmp: equal strings");
	assert_int(14, ft_strncmp("hello", "hella", 5), "ft_strncmp: different strings");
	assert_int(-14, ft_strncmp("hella", "hello", 5), "ft_strncmp: different strings");
	assert_int(0, ft_strncmp("hello", "hello", 3), "ft_strncmp: equal strings (partial)");

	// Test ft_strcat
	char dest1[20] = "Hello, ";
	assert_str("Hello, World!", ft_strcat(dest1, "World!"), "ft_strcat: concatenate strings");

	// Test ft_strncat
	char dest2[20] = "Hello, ";
	assert_str("Hello, Wor", ft_strncat(dest2, "World!", 3), "ft_strncat: concatenate first 3 characters");

	// Test ft_strstr
	assert_str("World!", ft_strstr("Hello, World!", "World!"), "ft_strstr: find substring");
	assert_str(NULL, ft_strstr("Hello, World!", "NotFound"), "ft_strstr: substring not found");

	// Test ft_strlcat
	char         dest3[20] = "Hello, ";
	unsigned int len = ft_strlcat(dest3, "World!", sizeof(dest3));
	assert_str("Hello, World!", dest3, "ft_strlcat: concatenate with size limit");
	assert_int(13, len, "ft_strlcat: total length after concatenation");

	return 0;
}
