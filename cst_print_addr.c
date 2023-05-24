#include "cst_printf.h"

/**
* cst_print_addr - prints out an address specified by %p
* @n: number of charcters to be printed
* Return: length of the characters printed to stdout
*/
int cst_print_addr(unsigned long n)
{
	int len;

	len = 0;
	len = len + write(1, "0x", 2);
	len = len + cst_print_hex(n, 'x');

	return (len);
}
