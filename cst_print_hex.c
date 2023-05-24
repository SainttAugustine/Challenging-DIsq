#include "cst_printf.h"

void cst_put_hex(unsigned long n, char *radix);

/**
* cst_put_hex - prints out hexadecimal characters
* @n: length of the charcters
* *@radix: radix of the evaluated characters
* Return: void
*/
void cst_put_hex(unsigned long n, char *radix)
{
	if (n < 16)
	{
		cst_putchar(radix[n]);
	} else if (n > 15)
	{
		cst_put_hex(n / 16, radix);
		cst_put_hex(n % 16, radix);
	} else
	{
		cst_putchar(n + 48);
	}
}

/**
* cst_print_hex - prints out hexadecimal characters to stdout
* @n: length of the characters
* @format: format specifier in printf call
*Return: length of characters printed in stdout
*/
int cst_print_hex(unsigned long n, char format)
{
	char *radix_x;
	char *radix_xx;
	int len;

	radix_x = "0123456789abcdef";
	radix_xx = "0123456789ABCDEF";
	len = 0;

	if (n == 0)
	{
		len += write(1, "0", 1);
	} else
	{
		if (format == 'x')
		{
			cst_put_hex(n, radix_x);
		}
		if (format == 'X')
		{
			cst_put_hex(n, radix_xx);
		}
	}
	while (n)
	{
		n /= 16;
		++len;
	}

	return (len);

}
