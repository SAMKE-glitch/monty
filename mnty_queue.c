#include "monty.h"

/**
 * mnty_queue - converts a stack to a queue
 * @stack: double pointer to the top node of the stack_t linked list
 * @line_number: current line of the Monty bytecode file
 *
 * Return: nothing
 */
void mnty_queue(stack_t **stack, unsigned int line_number)
{
	(*stack)->n = QUEUE;
	(void)line_number;
}
