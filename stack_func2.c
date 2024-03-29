#include "monty.h"

/**
 * nop - nothing.
 * @stack: Pointer to a pointer.
 * @line_number: Interger.
 * Return: void
 */
void nop(stack_t **stack, unsigned int line_number)
{
	(void)stack;
	(void)line_number;
}



/**
 * swap_nodes - Swaps the top.
 * @stack: Pointer to a pointer.
 * @line_number: Interger.
 * Return: void
 */
void swap_nodes(stack_t **stack, unsigned int line_number)
{
	stack_t *temp;

	if (stack == NULL || *stack == NULL || (*stack)->next == NULL)
		more_err(8, line_number, "swap");
	temp = (*stack)->next;
	(*stack)->next = temp->next;
	if (temp->next != NULL)
		temp->next->prev = *stack;
	temp->next = *stack;
	(*stack)->prev = temp;
	temp->prev = NULL;
	*stack = temp;
}


/**
 * add_nodes - Adds node.
 * @stack: Pointer to a pointer.
 * @line_number: Interger.
 * Return: void
 */
void add_nodes(stack_t **stack, unsigned int line_number)
{
	int sm;

	if (stack == NULL || *stack == NULL || (*stack)->next == NULL)
		more_err(8, line_number, "add");

	(*stack) = (*stack)->next;
	sm = (*stack)->n + (*stack)->prev->n;
	(*stack)->n = sm;
	free((*stack)->prev);
	(*stack)->prev = NULL;
}



/**
 * sub_nodes - Adds the top two elements.
 * @stack: Pointer to a pointer.
 * @line_number: Interger.
 * Return: void
 */
void sub_nodes(stack_t **stack, unsigned int line_number)
{
	int sm;

	if (stack == NULL || *stack == NULL || (*stack)->next == NULL)

		more_err(8, line_number, "sub");


	(*stack) = (*stack)->next;
	sm = (*stack)->n - (*stack)->prev->n;
	(*stack)->n = sm;
	free((*stack)->prev);
	(*stack)->prev = NULL;
}



/**
 * div_nodes - Adds the top two elements.
 * @stack: Pointer to a pointer.
 * @line_number: Interger.
 * Return: void
 */
void div_nodes(stack_t **stack, unsigned int line_number)
{
	int sm;

	if (stack == NULL || *stack == NULL || (*stack)->next == NULL)
		more_err(8, line_number, "div");

	if ((*stack)->n == 0)
		more_err(9, line_number);
	(*stack) = (*stack)->next;
	sm = (*stack)->n / (*stack)->prev->n;
	(*stack)->n = sm;
	free((*stack)->prev);
	(*stack)->prev = NULL;
}
