#include "monty.h"

/**
 * mnty_mul - multiplies the 2nd top element with the top element of the stack
 * @stack: double pointer to the top node of the stack
 * @line_number - current line in the Monty bytecode file
 *
 * Return: nothing
 */
void mnty_mul(stack_t **stack, unsigned int line_number)
{
	if (*stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%u: can't mul, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}
	(*stack)->next->n *= (*stack)->n;
	mnty_pop(stack, line_number);
}
