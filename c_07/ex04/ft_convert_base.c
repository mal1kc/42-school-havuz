#include <stddef.h>
#include <stdlib.h>

int ft_is_space(char chr)
{
	if (chr == ' ' || (chr >= '\t' && chr <= '\r'))
		return (1);
	return (0);
}

int check_base(char *base, int *base_len)
{
	unsigned int c1;
	unsigned int c2;

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

void skip_space_and_get_sign(char *nbr_str, int *counter, int *sign)
{
	while (ft_is_space(nbr_str[*counter]))
	{
		*counter = *counter + 1;
	}
	while (nbr_str[*counter] == '-' || nbr_str[*counter] == '+')
	{
		if (nbr_str[*counter] == '-')
			*sign *= -1;
		*counter = *counter + 1;
	}
}

int ft_atoi_base(char *nbr_str, char *base, int *base_len)
{
	int c;
	int res;
	int sign;
	int base_c;

	res = 0;
	c = 0;
	sign = 1;
	skip_space_and_get_sign(nbr_str, &c, &sign);
	while (nbr_str[c] != '\0')
	{
		base_c = 0;
		while (base[base_c] != nbr_str[c] && base[base_c] != '\0')
			base_c++;
		if (base[base_c] == '\0')
			break;
		res = (res * *base_len) + base_c;
		c++;
	}
	return (res * sign);
}

// can be maked without malloc wtf?
//
// void ft_wrtnbr_base(int nbr, char *base, int base_len, char *nbr_str, int *nbr_writer_indx)
// {
// 	long temp;
// 	int  stack[32];
// 	int  index = 0;
// 	temp = nbr;
// 	if (*nbr_writer_indx >= 32)
// 	{
// 		nbr_str[*nbr_writer_indx] = '\0';
// 		return;
// 	}
//
// 	if (temp < 0)
// 	{
// 		nbr_str[(*nbr_writer_indx)++] = '-';
// 		temp = -temp;
// 	}
//
// 	while (temp >= base_len)
// 	{
// 		stack[index++] = temp % base_len;
// 		temp /= base_len;
// 	}
// 	stack[index++] = temp;
//
// 	while (index > 0)
// 	{
// 		nbr_str[(*nbr_writer_indx)++] = base[stack[--index]];
// 	}
// 	nbr_str[*nbr_writer_indx] = '\0';
// }

void ft_wrtnbr_base(int nbr, char *base, int base_len, char *nbr_str, int *nbr_writer_indx)
{
	long temp;

	temp = nbr;
	if (*nbr_writer_indx >= 32)
	{
		nbr_str[*nbr_writer_indx] = '\0';
		return;
	}
	if (temp < 0)
	{
		nbr_str[(*nbr_writer_indx)++] = '-';
		temp = -temp;
	}
	if (temp >= base_len)
	{
		ft_wrtnbr_base(temp / base_len, base, base_len, nbr_str, nbr_writer_indx);
		nbr_str[(*nbr_writer_indx)++] = base[temp % base_len];
	}
	else
	{
		nbr_str[(*nbr_writer_indx)++] = base[temp];
	}
}

// 2147483647 -> 32 bit (31 bit numb + 1 sign) in binary

char *ft_convert_base(char *nbr, char *base_from, char *base_to)
{
	char *retval;
	int   base_from_len;
	int   base_to_len;
	int   nbr_as_int;
	int   nbr_writer;

	retval = NULL;
	base_from_len = 0;
	base_to_len = 0;
	nbr_writer = 0;
	if ((!check_base(base_from, &base_from_len) || !check_base(base_to, &base_to_len)))
		return (retval);
	nbr_as_int = ft_atoi_base(nbr, base_from, &base_from_len);
	retval = (char *) malloc(sizeof(char) * 33);
	ft_wrtnbr_base(nbr_as_int, base_to, base_to_len, retval, &nbr_writer);
	return (retval);
}

// #include <stdio.h>
// #include <stdlib.h>
// int main()
// {
// 	char *base_from = "0123456789"; // Decimal base
// 	char *base_to = "01";           // Binary base
// 	char *number = "2147483647";    // Number to convert
//
// 	char *result = ft_convert_base(number, base_from, base_to);
// 	if (result)
// 	{
// 		printf("The binary representation of %s is: %s\n", number, result);
// 		free(result); // Don't forget to free the allocated memory
// 	}
// 	else
// 	{
// 		printf("Conversion failed.\n");
// 	}
//
// 	// Additional test cases
// 	char *hex_base_from = "0123456789ABCDEF"; // Hexadecimal base
// 	char *binary_base_to = "01";              // Binary base
// 	char *hex_number = "7FFFFFFF";            // Hexadecimal number
//
// 	result = ft_convert_base(hex_number, hex_base_from, binary_base_to);
// 	if (result)
// 	{
// 		printf("The binary representation of %s is: %s\n", hex_number, result);
// 		free(result);
// 	}
// 	else
// 	{
// 		printf("Conversion failed.\n");
// 	}
//
// 	return (0);
// }
