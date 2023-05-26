#include "monty.h"

/**
 * mnty_pchar - prints the character at the top of the stack
 * @stack: double pointer to the top node of the stack
 * @line_number: current line of the Monty bytecode file
 *
 * Return: nothing
 */
void mnty_pchar(stack_t **stack, unsigned int line_number)
{
	int value;

	if (*stack == NULL)
	{
		fprintf(stderr, "L%u: can't pchar, stack empty\n", line_number);
		exit(EXIT_FAILURE);
	}
	value = (*stack)->n;

	if (value < 0 || value > 127)
	{
		fprintf(stderr, "L%u: can't pchar, value out of range\n", line_number);
		exit(EXIT_FAILURE);
	}
	printf("%c\n", (char)value);
}
