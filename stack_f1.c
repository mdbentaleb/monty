#include "monty.h"


/**
 * add_to_stack - Adds a node.
 * @new_node: Pointer to new node
 * @ln: Interger
 * Return: void
 */
void add_to_stack(stack_t **new_node, __attribute__((unused))unsigned int ln)
{
	stack_t *temp;

	if (new_node == NULL || *new_node == NULL)
		exit(EXIT_FAILURE);
	if (head == NULL)
	{
		head = *new_node;
		return;
	}
	temp = head;
	head = *new_node;
	head->next = temp;
	temp->prev = head;
}



/**
 * print_stack - Adds a node
 * @stack: Pointer to a pointer.
 * @line_number: line number.
 * Return: void
 */
void print_stack(stack_t **stack, unsigned int line_number)
{
	stack_t *temp;

	(void) line_number;
	if (stack == NULL)
		exit(EXIT_FAILURE);
	temp = *stack;
	while (temp != NULL)
	{
		printf("%d\n", temp->n);
		temp = temp->next;
	}
}


/**
 * pop_top - Adds a node.
 * @stack: Pointer to a pointer.
 * @line_number: Interger.
 * Return: void
 */
void pop_top(stack_t **stack, unsigned int line_number)
{
	stack_t *temp;

	if (stack == NULL || *stack == NULL)
		more_err(7, line_number);

	temp = *stack;
	*stack = temp->next;
	if (*stack != NULL)
		(*stack)->prev = NULL;
	free(temp);
}


/**
 * print_top - Prints the top node.
 * @stack: Pointer to a pointer.
 * @line_number: Interger.
 * Return: void
 */
void print_top(stack_t **stack, unsigned int line_number)
{
	if (stack == NULL || *stack == NULL)
		more_err(6, line_number);

	printf("%d\n", (*stack)->n);
}
