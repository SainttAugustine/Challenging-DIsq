#include "cst_printf.h"

/**
* cst_formats - determines the format specifier to be used
* *@s: format string argument
* @ap: list of arguments
* @i: position of character in format string
*
* Return: length of charcters printed
*/
int cst_formats(const char *s, va_list ap, int i)
{
	int len;

	len = 0;
	if (s[i] == 'c')
		len += cst_putchar(va_arg(ap, int));
	else if (s[i] == 's')
		len += cst_putstr(va_arg(ap, char *));
	else if (s[i] == 'd')
		len += cst_putnbr(va_arg(ap, int));
	else if (s[i] == 'i')
		len += cst_putnbr(va_arg(ap, int));
	else if (s[i] == 'u')
		len += cst_putnbr_u(va_arg(ap, unsigned int));
	else if (s[i] == '%')
		len += cst_print_percent();
	else if (s[i] == 'x')
		len += cst_print_hex(va_arg(ap, unsigned int), 'x');
	else if (s[i] == 'X')
		len += cst_print_hex(va_arg(ap, unsigned int), 'X');
	else if (s[i] == 'p')
		len += cst_print_addr(va_arg(ap, unsigned long));
	return (len);
}
