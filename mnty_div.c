#include "monty.h"

/**
 * mnty_div - divides the second top element by the top element of stack
 * @stack: double pointer to the top node  of the stack
 * @line_number: current line of the Monty bytecode file
 * Return: nothing
 */
void mnty_div(stack_t **stack, unsigned int line_number)
{
	if (*stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%u: can't div, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}
	if ((*stack)->n == 0)
	{
		fprintf(stderr, "L%u: division by zero\n", line_number);
		exit(EXIT_FAILURE);
	}
	(*stack)->next->n /= (*stack)->n;
	mnty_pop(stack, line_number);
}
