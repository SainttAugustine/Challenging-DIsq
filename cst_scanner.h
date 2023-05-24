#ifndef SCANNER_H
#define SCANNER_H

#include "cst_source.h"
/**
 * struct token_s - Struct op for token
 *
 * @src: source of input
 * @text_len: length of token text
 * @text: token text
 */
struct token_s
{
	source_s *src;       /* source of input */
	int    text_len;            /* length of token text */
	char   *text;               /* token text */
};

/* the special EOF token, which indicates the end of input */
extern struct token_s eof_token;

struct token_s *tokenize(struct source_s *src);
void free_token(struct token_s *tok);

#endif
