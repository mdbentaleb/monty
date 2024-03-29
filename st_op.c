#include "monty.h"

/**
 * mul_nodes - Adds the top two elements.
 * @stack: Pointer to a pointer.
 * @line_number: Interger.
 * Return: void
 */
void mul_nodes(stack_t **stack, unsigned int line_number)
{
	int sm;

	if (stack == NULL || *stack == NULL || (*stack)->next == NULL)
		more_err(8, line_number, "mul");

	(*stack) = (*stack)->next;
	sm = (*stack)->n * (*stack)->prev->n;
	(*stack)->n = sm;
	free((*stack)->prev);
	(*stack)->prev = NULL;
}



/**
 * mod_nodes - Adds the top two elements.
 * @stack: Pointer to a pointer.
 * @line_number: Interger.
 * Return: void
 */
void mod_nodes(stack_t **stack, unsigned int line_number)
{
	int sm;

	if (stack == NULL || *stack == NULL || (*stack)->next == NULL)

		more_err(8, line_number, "mod");


	if ((*stack)->n == 0)
		more_err(9, line_number);
	(*stack) = (*stack)->next;
	sm = (*stack)->n % (*stack)->prev->n;
	(*stack)->n = sm;
	free((*stack)->prev);
	(*stack)->prev = NULL;
}
