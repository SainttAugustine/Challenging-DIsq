#include "cst_printf.h"

/**
* cst_putchar - prints out a character to stdout
* @c: character to be printed
* Return: 1 if successful, otherwise -1 if not successful
*/
int cst_putchar(char c)
{
	write(1, &c, 1);

	return (1);
}

/**
* cst_putstr - prints out a string to stdout
* *@str: string to be printed
* Return: 1 if successful, otherwise -1 if not successful
*/
int cst_putstr(char *str)
{
	int i;

	i = -1;

	if (str == NULL)
	{
		cst_putstr("(null)");
		return (6);
	}

	while (str[++i])
	{
		write(1, &str[i], 1);
	}

	return (i);
}

/**
* cst_putnbr - prints out a number to stdout
* @n: number to be printed
* Return: length of the number printed out to stdout
*/
int cst_putnbr(int n)
{
	int len;

	len = 0;

	if (n == -2147483648)
	{
		return (write(1, "-2147483648", 11));
	}

	if (n < 0)
	{
		len = len + cst_putchar('-');
		n = -n;
	}

	if (n > 9)
	{
		len = len + cst_putnbr(n / 10);
	}

	len = len + cst_putchar(n % 10 + 48);
	return (len);
}

/**
* cst_print_percent - prints out the percentage (%) character to stdout
* @void: no argument required
* Return: 1 if successful, otherwise -1 if not successful
*/
int cst_print_percent(void)
{
	write(1, "%", 1);
	return (1);
}

/**
* cst_putnbr_u - prints out an unsigned number to stdout
* @n: unsigned integer to be printed
* Return: length of the number printed out to stdout
*/
int cst_putnbr_u(unsigned long n)
{
	int len;

	len = 0;

	if (n > 9)
	{
		len = len + cst_putnbr_u(n / 10);
	}

	len = len + cst_putchar(n % 10 + 48);
	return (len);
}
