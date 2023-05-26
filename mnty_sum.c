#include "monty.h"

/**
 * mnty_add - function that adds the top 2 elements of stackl
 * @stack: the stack that we are accessing the top elements to add
 * @line_number: the current line in the monty bytecode file
 *
 * Return: nothing
 */
void mnty_add(stack_t **stack, unsigned int line_number)
{
	if (*stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%u: can't add, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}
	(*stack)->next->n += (*stack)->n;
	mnty_pop(stack, line_number);
}
