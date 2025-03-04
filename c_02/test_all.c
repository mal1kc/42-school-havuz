#include <assert.h>
#include <stdio.h>
#include <string.h>

char	*ft_strcpy(char *dest, char *src);
char	*ft_strncpy(char *dest, char *src, unsigned int size);
int		ft_str_is_alpha(char *str);
int		ft_str_is_numeric(char *str);
int		ft_str_is_lowercase(char *str);
int		ft_str_is_uppercase(char *str);
int		ft_str_is_printable(char *str);
char	*ft_strupcase(char *str);
char	*ft_strlowcase(char *str);
char	*ft_strcapitalize(char *str);

void	assert_string_eq(const char *expected, const char *actual,
		const char *test_name)
{
	if (strcmp(expected, actual) == 0)
	{
		printf("PASS:'%s' : expected '%s', got '%s'\n", test_name, expected,
			actual);
	}
	else
	{
		printf("FAIL:'%s' : expected '%s', got '%s'\n", test_name, expected,
			actual);
	}
}

void	assert_int(const int expected, const int actual, const char *test_name)
{
	if (expected == actual)
	{
		printf("PASS:'%s' : expected '%d', got '%d'\n", test_name, expected,
			actual);
	}
	else
	{
		printf("FAIL:'%s' : expected '%d', got '%d'\n", test_name, expected,
			actual);
	}
}

int	main(void)
{
	char	dest[100];
	char	*retval;
	char	strcpy_expected[] = "Hello World!";
	char	upcase_0_sample_text[] = "uppercase";
	char	upcase_1_sample_text[] = "uppercase123";
	char	upcase_2_sample_text[] = "UPPERCASE123";
	char	upcase_3_sample_text[] = "U p p e r c a s E\t";
	char	lowcase_0_sample_text[] = "lowercase";
	char	lowcase_1_sample_text[] = "LOWERCASE123";
	char	lowcase_2_sample_text[] = "194812-42";
	char	lowcase_3_sample_text[] = "U p p e r c a s E\t";
	char	*src;
	char	dest1[20];
	char	dest2[20];
	char	dest3[20];
	char	dest4[20];
	char	capitalize_1[] = "hello world";
	char	capitalize_2[] = "hello WORLD!";
	char	capitalize_3[] = "hello123 world!";
	char	capitalize_4[] = "  hello world";
	char	capitalize_5[] = "hello   world!";
	char	capitalize_6[] = "   hello";

	// Testing ft_strcpy and ft_strncpy
	retval = ft_strcpy(dest, strcpy_expected);
	assert_string_eq(strcpy_expected, dest, "strcpy 0");
	assert_string_eq(strcpy_expected, retval, "strcpy 1");
	retval = ft_strncpy(dest, "Hello World", 5);
	assert_string_eq("Hello", dest, "strncpy 0");
	assert_string_eq("Hello", retval, "strncpy 1");
	src = "Hello World";
	// Test case 1: Copy first 5 characters
	// Using standard strncpy
	strncpy(dest1, src, 5);
	dest1[5] = '\0'; // Ensuring null-termination
	// Using custom ft_strncpy
	ft_strncpy(dest2, src, 5);
	// Check if both functions return the same result
	assert_string_eq("Hello", dest1, "strncpy 0");
	assert_string_eq("Hello", dest2, "strncpy 1");
	// Ensure that both dest1 and dest2 are null-terminated at index 5
	assert(dest1[5] == '\0'); // After copying 5 chars, the 6th must be '\0'
	assert(dest2[5] == '\0'); // Same for custom function
	// Test case 2: n > length of src (to check for proper null-filling)
	// Using standard strncpy with larger n
	strncpy(dest3, src, 15);
	dest3[15] = '\0'; // Ensuring null-termination
	// Using custom ft_strncpy with larger n
	ft_strncpy(dest4, src, 15);
	// Check if both functions return the same result
	assert_string_eq("Hello World", dest3, "strncpy 2");
	assert_string_eq("Hello World", dest4, "strncpy 3");
	// Ensure the rest of the destination buffers are filled with '\0'
	assert(dest3[11] == '\0');
	// After copying "Hello World",
	index 11 should be '\0' assert(dest4[11] == '\0');
	// Same for custom function
	// Testing ft_str_is_alpha
	assert_int(1, ft_str_is_alpha("aaadasdbsdaczAZA"), "ft_str_is_alpha 0");
	assert_int(0, ft_str_is_alpha("a123asd"), "ft_str_is_alpha 1");
	assert_int(1, ft_str_is_alpha(""), "ft_str_is_alpha 2");
	assert_int(0, ft_str_is_alpha("A123asd"), "ft_str_is_alpha 3");
	assert_int(1, ft_str_is_alpha("AZADADAD"), "ft_str_is_alpha 4");
	assert_int(0, ft_str_is_alpha("1"), "ft_str_is_alpha 5");
	assert_int(0, ft_str_is_alpha("AZADADAD9"), "ft_str_is_alpha 6");
	// Testing ft_str_is_numeric
	assert_int(0, ft_str_is_numeric("aaadasdbsdaczAZA"), "ft_str_is_numeric 0");
	assert_int(0, ft_str_is_numeric("a123asd"), "ft_str_is_numeric 1");
	assert_int(1, ft_str_is_numeric(""), "ft_str_is_numeric 2");
	assert_int(0, ft_str_is_numeric("A123asd"), "ft_str_is_numeric 3");
	assert_int(1, ft_str_is_numeric("123958213"), "ft_str_is_numeric 4");
	assert_int(0, ft_str_is_numeric("1 2"), "ft_str_is_numeric 5");
	// Testing ft_str_is_lowercase
	assert_int(0, ft_str_is_lowercase("aaadasdbsdaczAZA"),
		"ft_str_is_lowercase 0");
	assert_int(0, ft_str_is_lowercase("a123asd"), "ft_str_is_lowercase 1");
	assert_int(1, ft_str_is_lowercase(""), "ft_str_is_lowercase 2");
	assert_int(1, ft_str_is_lowercase("aasdasdadqwqvscxwec"),
		"ft_str_is_lowercase 3");
	assert_int(0, ft_str_is_lowercase("123958213"), "ft_str_is_lowercase 4");
	assert_int(0, ft_str_is_lowercase("1 2"), "ft_str_is_lowercase 5");
	// Testing ft_str_is_uppercase
	assert_int(0, ft_str_is_uppercase("aaadasdbsdaczAZA"),
		"ft_str_is_uppercase 0");
	assert_int(0, ft_str_is_uppercase("a123asd"), "ft_str_is_uppercase 1");
	assert_int(1, ft_str_is_uppercase(""), "ft_str_is_uppercase 2");
	assert_int(1, ft_str_is_uppercase("AASDASDADQWQVSCXWEC"),
		"ft_str_is_uppercase 3");
	assert_int(0, ft_str_is_uppercase("123958213"), "ft_str_is_uppercase 4");
	assert_int(0, ft_str_is_uppercase("1 2"), "ft_str_is_uppercase 5");
	// Testing ft_str_is_printable
	assert_int(0, ft_str_is_printable("aaadasdbsdaczAZA\n"),
		"ft_str_is_printable 0");
	assert_int(0, ft_str_is_printable("\7F\n"), "ft_str_is_printable 1");
	assert_int(1, ft_str_is_printable("a123asd"), "ft_str_is_printable 2");
	assert_int(1, ft_str_is_printable(""), "ft_str_is_printable 3");
	assert_int(1, ft_str_is_printable("AASDASDADQWQVSCXWEC"),
		"ft_str_is_printable 4");
	assert_int(1, ft_str_is_printable("123958213"), "ft_str_is_printable 5");
	assert_int(1, ft_str_is_printable("1 2"), "ft_str_is_printable 6");
	// Testing ft_strupcase and ft_strlowcase
	retval = ft_strupcase(upcase_0_sample_text);
	assert_string_eq("UPPERCASE", retval, "ft_strupcase 0");
	retval = ft_strupcase(upcase_1_sample_text);
	assert_string_eq("UPPERCASE123", retval, "ft_strupcase 1");
	retval = ft_strupcase(upcase_2_sample_text);
	assert_string_eq("UPPERCASE123", retval, "ft_strupcase 2");
	retval = ft_strupcase(upcase_3_sample_text);
	assert_string_eq("U P P E R C A S E\t", retval, "ft_strupcase 3");
	retval = ft_strlowcase(lowcase_0_sample_text);
	assert_string_eq("lowercase", retval, "ft_strlowcase 0");
	retval = ft_strlowcase(lowcase_1_sample_text);
	assert_string_eq("lowercase123", retval, "ft_strlowcase 1");
	retval = ft_strlowcase(lowcase_2_sample_text);
	assert_string_eq("194812-42", retval, "ft_strlowcase 2");
	retval = ft_strlowcase(lowcase_3_sample_text);
	assert_string_eq("u p p e r c a s e\t", retval, "ft_strlowcase 3");
	// Testing ft_strcapitalize
	char capitalize_7[] = "salut, comment tu vas ? 42mots quarante-deux; "
							"cinquante+et+un";
	assert_string_eq("Hello World", ft_strcapitalize(capitalize_1),
		"ft_strcapitalize 1");
	assert_string_eq("Hello World!", ft_strcapitalize(capitalize_2),
		"ft_strcapitalize 2");
	assert_string_eq("Hello123 World!", ft_strcapitalize(capitalize_3),
		"ft_strcapitalize 3");
	assert_string_eq("  Hello World", ft_strcapitalize(capitalize_4),
		"ft_strcapitalize 4");
	assert_string_eq("Hello   World!", ft_strcapitalize(capitalize_5),
		"ft_strcapitalize 5");
	assert_string_eq("   Hello", ft_strcapitalize(capitalize_6),
		"ft_strcapitalize 6");
	assert_string_eq("Salut,
		Comment Tu Vas ? 42mots Quarante-Deux; Cinquante+Et+Un",
		ft_strcapitalize(capitalize_7), "ft_strcapitalize 6");
	return (0);
}
