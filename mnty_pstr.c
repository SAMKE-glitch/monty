#include "monty.h"

/**
 * mnty_pstr - prints the string starting at the top of the stack
 * @stack: double pointer to the top node of the stack
 * @line_number: current line of the monty bytecode file
 *
 * Return: nothing
 */
void mnty_pstr(stack_t **stack, unsigned int line_number)
{
	stack_t *temp = (*stack)->next;

	while (temp && temp->n != 0 && (temp->n > 0 && temp->n <= 127))
	{
		printf("%c", temp->n);
		temp = temp->next;
	}

	printf("\n");

	(void)line_number;
}
