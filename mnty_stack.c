#include "monty.h"

/**
 * mnty_stack - function that converts queue to a stack
 * @stack: double pointer to the top node of a stack_t linked list
 * @line_number: current line of the Monty bytecode file
 *
 * Return: nothing
 */
void mnty_stack(stack_t **stack, unsigned int line_number)
{
	(*stack)->n = STACK;
	(void)line_number;
}
