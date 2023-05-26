#include "monty.h"

/**
 * mnty_nop - function that doesn't do anything
 * @stack: pointer to the top node of the stack
 * @line_number: the curent line of the monty bytecode file
 * Return: nothing
 */
void mnty_nop(stack_t **stack, unsigned int line_number)
{
	(void)stack;
	(void)line_number;
}
