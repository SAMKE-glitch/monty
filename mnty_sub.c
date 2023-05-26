#include "monty.h"

/**
 * mnty_sub - function that subtracts top elemt from second top
 * @stack: double pointer to the top element of the stack
 * @line_number: current line in the Monty bytecode file
 * Return: nothing
 */
void mnty_sub(stack_t **stack, unsigned int line_number)
{
	if (*stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%u: can't sub, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}
	(*stack)->next->n -= (*stack)->n;
	mnty_pop(stack, line_number);
}
