#ifndef CST_PRINTF_H
#define CST_PRINTF_H

#include <unistd.h>
#include <stdarg.h>

int cst_printf(const char *s, ...);
int cst_putchar(char c);
int cst_putstr(char *str);
int cst_formats(const char *str, va_list ap, int i);
int cst_putnbr(int n);
int cst_print_percent(void);
int cst_putnbr_u(unsigned long n);
int cst_print_hex(unsigned long n, char format);
int cst_print_addr(unsigned long n);

#endif
