#include "monty.h"

/**
 * err - Prints error messages.
 * @error_code: The error codes (1) (2) (3) (4) (5) (6) (7) (8):
 * Return: void
 */
void err(int error_code, ...)
{
	va_list arg;
	char *opt;
	int l_nmb;

	va_start(arg, error_code);
	switch (error_code)
	{
		case 1:
			fprintf(stderr, "USAGE: monty file\n");
			break;
		case 2:
			fprintf(stderr, "Error: Can't open file %s\n",
				va_arg(arg, char *));
			break;
		case 3:
			l_nmb = va_arg(arg, int);
			opt = va_arg(arg, char *);
			fprintf(stderr, "L%d: unknown instruction %s\n", l_nmb, opt);
			break;
		case 4:
			fprintf(stderr, "Error: malloc failed\n");
			break;
		case 5:
			fprintf(stderr, "L%d: usage: push integer\n", va_arg(arg, int));
			break;
		default:
			break;
	}
	free_nodes();
	exit(EXIT_FAILURE);
}

/**
 * more_err - handles errors.
 * @error_code: The error codes 6 - 7 - 8 - 9:
 * Return: void
 */
void more_err(int error_code, ...)
{
	va_list arg;
	char *opt;
	int l_nmb;

	va_start(arg, error_code);
	switch (error_code)
	{
		case 6:
			fprintf(stderr, "L%d: can't pint, stack empty\n",
				va_arg(arg, int));
			break;
		case 7:
			fprintf(stderr, "L%d: can't pop an empty stack\n",
				va_arg(arg, int));
			break;
		case 8:
			l_nmb = va_arg(arg, unsigned int);
			opt = va_arg(arg, char *);
			fprintf(stderr, "L%d: can't %s, stack too short\n", l_nmb, opt);
			break;
		case 9:
			fprintf(stderr, "L%d: division by zero\n",
				va_arg(arg, unsigned int));
			break;
		default:
			break;
	}
	free_nodes();
	exit(EXIT_FAILURE);
}

/**
 * string_err - handles errors.
 * @error_code: The error codes 10 - 11:
 * Return: void
 */
void string_err(int error_code, ...)
{
	va_list arg;
	int l_nmb;

	va_start(arg, error_code);
	l_nmb = va_arg(arg, int);
	switch (error_code)
	{
		case 10:
			fprintf(stderr, "L%d: can't pchar, value out of range\n", l_nmb);
			break;
		case 11:
			fprintf(stderr, "L%d: can't pchar, stack empty\n", l_nmb);
			break;
		default:
			break;
	}
	free_nodes();
	exit(EXIT_FAILURE);
}
