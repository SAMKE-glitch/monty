#include "monty.h"

/**
 * mnty_rotr - rotates the stack to the bottom
 * @stack: double pointer to top node of the stack
 * @line_number: currentline of the monty bytecode file
 *
 * Return: nothing
 */
void mnty_rotr(stack_t **stack, unsigned int line_number)
{
	stack_t *top = *stack;
	stack_t *last = NULL;

	if (top != NULL && top->next != NULL)
	{
		while (top->next != NULL)
			top = top->next;

		last = top;
		last->prev->next = NULL;
		last->prev = NULL;
		last->next = *stack;
		(*stack)->prev = last;
		*stack = last;
	}
	(void)line_number;
}
