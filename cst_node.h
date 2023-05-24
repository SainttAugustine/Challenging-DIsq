#ifndef CST_NODE_H
#define CST_NODE_H

/**
 * enum node_type_e - enum for node tyrpr
 * @NODE_COMMAND: simple command
 * @NODE_VAR: var name
 */
enum node_type_e
{
	NODE_COMMAND,	/* simple command */
	NODE_VAR	/* variable name (or simply, a word) */
};

/**
 * enum val_type_e - enum for value typr
 * @VAL_SINT: signed int
 * @VAL_UINT: unsigned int
 * @VAL_SLLONG: signed long long
 * @VAL_ULLONG: unsigned long long
 * @VAL_FLOAT: floating point
 * @VAL_LDOUBLE: long double
 * @VAL_CHR: character
 * @VAL_STR: string(char ptr)
 */
enum val_type_e
{
	VAL_SINT = 1,       /* signed int */
	VAL_UINT,           /* unsigned int */
	VAL_SLLONG,         /* signed long long */
	VAL_ULLONG,         /* unsigned long long */
	VAL_FLOAT,          /* floating point */
	VAL_LDOUBLE,        /* long double */
	VAL_CHR,            /* char */
	VAL_STR            /* str (char pointer) */
};

/**
 * union symval_u - union for symval
 * @sint: signed int
 * @uint: unsigned int
 * @sllong: signed long long
 * @ullong: unsigned long long
 * @sfloat: floating point
 * @ldouble: long double
 * @chr: character
 * @str: string(char ptr)
 */
union symval_u
{
	long               sint;

	unsigned long      uint;

	long long          sllong;

	unsigned long long ullong;

	double             sfloat;

	long double        ldouble;

	char               chr;

	char              *str;


};


/**
 * struct node_s - Struct op for node
 *
 * @type: type of node
 * @val_type: type of this node's val field
 * @val: value of this node
 * @children: number of child nodes
 * @first_child: first child node
 * @prev_sibling: previous child node
 * @next_sibling: next child node
 */
struct node_s
{
	node_type_e type;    /* type of this node */
	val_type_e val_type; /* type of this node's val field */
	symval_u val;        /* value of this node */
	int    children;            /* number of child nodes */
	struct node_s *first_child; /* first child node */
	struct node_s *next_sibling, *prev_sibling; /*
												 * if this is a child node, keep
												 * pointers to prev/next siblings
												 */
};

struct  node_s *new_node(enum node_type_e type);
void    add_child_node(struct node_s *parent, struct node_s *child);
void    free_node_tree(struct node_s *node);
void    set_node_val_str(struct node_s *node, char *val);


#endif
