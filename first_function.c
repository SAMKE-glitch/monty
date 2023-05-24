#include "monty.h"

/**
 * mnty_push - function that pushes an element to the stack
 * @stack: double pointer to the stack
 * @line_number: line number in the file
 * Return: Nothing
 */
void mnty_push(stack_t **stack, unsigned int line_number)
{
	int value;
	size_t i;
	stack_t *new_node;
	char *arg = strtok(NULL, " \t\n");

	if (arg)
	{
		for (i = 0; arg[i] != '\0'; i++)
		{
			if (!isdigit(arg[i]) && arg[i] != '-')
			{
				fprintf(stderr, "L%u: usage: push requires an integer argument\n", line_number);
				exit(EXIT_FAILURE);
			}
		}
		value = atoi(arg);

		new_node = malloc(sizeof(stack_t));

		if (!new_node)
		{
			fprintf(stderr, "Error: malloc failed\n");
			exit(EXIT_FAILURE);
		}
		new_node->n = value;
		new_node->prev = NULL;
		new_node->next = *stack;

		if (*stack)
			(*stack)->prev = new_node;
		*stack = new_node;
	}
	else
	{
		fprintf(stderr, "L%u: usage: push requires an integers argument\n", line_number);
	}
}

/**
 * mnty_pall - function that prints all the values on the stack
 * @stack: double pointer to the stack
 * @line_number: line number in the file
 * Return: nothing
 */
void mnty_pall(stack_t **stack, unsigned int line_number)
{
	stack_t *current;

	if (*stack == NULL)
	{
		return;
	}
	current = *stack;

	(void)line_number;

	while (current != NULL)
	{
		printf("%d\n", current->n);
		current = current->next;
	}
}
