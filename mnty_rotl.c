#include "monty.h"

/**
 * mnty_rotl - rotates the stack to the top
 * @stack: double pointer to the top of our stack
 * @line_number: current line in the Monty bytecode file
 *
 * Retrun: nothing
 */
void mnty_rotl(stack_t **stack, unsigned int line_number)
{
	stack_t *top, *bottom;

	if (*stack != NULL && (*stack)->next != NULL)
	{
		top = *stack;
		bottom = *stack;

		while (bottom->next != NULL)
			bottom = bottom->next;

		*stack = top->next;
		(*stack)->prev = NULL;
		bottom->next = top;
		top->prev = bottom;
		top->next = NULL;
	}
	(void)line_number;
}
