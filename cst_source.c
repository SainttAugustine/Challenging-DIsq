#include <errno.h>
#include "cst_shell.h"
#include "cst_source.h"

/**
*unget_char - discards char
*@src: char to be evaluated
*Return: void
*/

void unget_char(struct source_s *src)
{
	if (src->curpos < 0)
	{
		return;
	}

	src->curpos--;
}

/**
*next_char - proceeds to the next char
*@src: char to be evaluated
*Return: valid char on success
*/
char next_char(struct source_s *src)
{
	char c1;
	(void)c1;
	
	if (!src || !src->buffer)
	{
		errno = ENODATA;
		return (-ERRCHAR);
	}

	if (src->curpos == INIT_SRC_POS)
	{
		src->curpos  = -1;
	}
	else
	{
		c1 = src->buffer[src->curpos];
	}

	if (++src->curpos >= src->bufsize)
	{
		src->curpos = src->bufsize;
		return (EOF);
	}

	return (src->buffer[src->curpos]);
}

/**
*peek_char - checks the next char
*@src: char to be evaluated
*Return: valid character on success
*/
char peek_char(struct source_s *src)
{
	long pos;
	
	if (!src || !src->buffer)
	{
		errno = ENODATA;
		return (-ERRCHAR);
	}

	pos = src->curpos;

	if (pos == INIT_SRC_POS)
	{
		pos++;
	}
	pos++;

	if (pos >= src->bufsize)
	{
		return (EOF);
	}

	return (src->buffer[pos]);
}

/**
*skip_white_spaces - skips white spaces
*@src: source object
*Return: void
*/
void skip_white_spaces(struct source_s *src)
{
	char c;

	if (!src || !src->buffer)
	{
		return;
	}

	while (((c = peek_char(src)) != EOF) && (c == ' ' || c == '\t'))
	{
		next_char(src);
	}
}
