#include "cst_printf.h"

/**
* cst_printf - produces output according to a format
*				writes output to stdout, the standard output stream
* *@s: character string consisiting of format specifiers
* Return: number of characters printed(excluding '\0')
*/
int cst_printf(const char *s, ...)
{
	va_list ap;
	int index, len;

	index = 0;
	len = 0;

	va_start(ap, s);
	while (s[index])
	{
		if (s[index] == '%')
		{
			len += cst_formats(s, ap, ++index);
		} else
		{
			len += cst_putchar(s[index]);
		}
		index++;
	}

	va_end(ap);
	return (len);
}
