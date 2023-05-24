#include <stdio.h>
#include "cst_shell.h"

/**
*print_prompt1 - prints the shell prompt
*Return: void
*/

void print_prompt1(void)
{
	fprintf(stderr, "$ ");
}

/**
*print_prompt2 - prints the shell prompt
*Return: void
*/
void print_prompt2(void)
{
	fprintf(stderr, "> ");
}
