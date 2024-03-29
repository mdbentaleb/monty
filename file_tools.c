#include "monty.h"

/**
 * open_file - opens file.
 * @file_name: file namepath
 *
 * Return: void
 */

void open_file(char *file_name)
{
	FILE *fl = fopen(file_name, "r");

	if (file_name == NULL || fl == NULL)
		err(2, file_name);

	read_file(fl);
	fclose(fl);
}


/**
 * read_file - reads file
 * @fd: pointer to file
 *
 * Return: void
 */

void read_file(FILE *fd)
{
	int line_nmbr, format = 0;
	char *buf = NULL;
	size_t l = 0;

	for (line_nmbr = 1; getline(&buffer, &l, fd) != -1; line_nmbr++)
	{
		format = parse_line(buf, line_nmbr, format);
	}
	free(buf);
}


/**
 * parse_line - Separates each line
 * @buffer: line
 * @line_number: line number
 * @format:  storage format. If 0 Nodes will be entered as a stack.
 * if 1 nodes will be entered as a queue.
 * Return: Returns 0 if the opcode is stack. 1 if queue.
 */

int parse_line(char *buffer, int line_number, int format)
{
	char *opc, *val;
	const char *del = "\n ";

	if (buffer == NULL)
		err(4);

	opc = strtok(buffer, delim);
	if (opc == NULL)
		return (format);
	val = strtok(NULL, del);

	if (strcmp(opc, "stack") == 0)
		return (0);
	if (strcmp(opc, "queue") == 0)
		return (1);

	find_func(opc, val, line_number, format);
	return (format);
}

/**
 * find_func - find the appropriate function
 * @opcode: opcode
 * @value: argument of opcode
 * @format:  storage format.
 * @ln: line number
 * Return: void
 */
void find_func(char *opcode, char *value, int ln, int format)
{
	int j;
	int flg;

	instruction_t func_list[] = {
		{"push", add_to_stack},
		{"pall", print_stack},
		{"pint", print_top},
		{"pop", pop_top},
		{"nop", nop},
		{"swap", swap_nodes},
		{"add", add_nodes},
		{"sub", sub_nodes},
		{"div", div_nodes},
		{"mul", mul_nodes},
		{"mod", mod_nodes},
		{"pchar", print_char},
		{"pstr", print_str},
		{"rotl", rotl},
		{"rotr", rotr},
		{NULL, NULL}
	};

	if (opcode[0] == '#')
		return;

	for (flg = 1, j = 0; func_list[j].opcode != NULL; j++)
	{
		if (strcmp(opcode, func_list[j].opcode) == 0)
		{
			call_fun(func_list[j].f, opcode, value, ln, format);
			flg = 0;
		}
	}
	if (flg == 1)
		err(3, ln, opcode);
}


/**
 * call_fun - Calls the required function.
 * @func: Pointer to function
 * @op: string.
 * @val: string.
 * @ln: line numeber.
 * @format: Format specifier.
 */
void call_fun(op_func func, char *op, char *val, int ln, int format)
{
	stack_t *node;
	int flg;
	int j;

	flg = 1;
	if (strcmp(op, "push") == 0)
	{
		if (val != NULL && val[0] == '-')
		{
			val = val + 1;
			flg = -1;
		}
		if (val == NULL)
			err(5, ln);
		for (i = 0; val[j] != '\0'; j++)
		{
			if (isdigit(val[j]) == 0)
				err(5, ln);
		}
		node = create_node(atoi(val) * flg);
		if (format == 0)
			func(&node, ln);
		if (format == 1)
			add_to_queue(&node, ln);
	}
	else
		func(&head, ln);
}
