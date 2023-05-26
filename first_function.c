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
	char *lines = strtok(NULL, " \t\n");

	if (lines)
	{
		for (i = 0; lines[i] != '\0'; i++)
		{
			if (!isdigit(lines[i]) && lines[i] != '-')
			{
				fprintf(stderr, "L%u: usage: push integer\n", line_number);
				exit(EXIT_FAILURE);
			}
		}
		value = atoi(lines);

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
		fprintf(stderr, "L%u: usage: push integer\n", line_number);
		exit(EXIT_FAILURE);
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

/**
 * mnty_pint - function that prints the value at the top of the stack
 * @stack: the stack where the value is
 * @line_number: The current line of the monty bytecode file
 * Return: Nothing
 */
void mnty_pint(stack_t **stack, unsigned int line_number)
{
	if (*stack == NULL)
	{
		fprintf(stderr, "L%u: can't pint, stack empty\n", line_number);
		exit(EXIT_FAILURE);
	}
	printf("%d\n", (*stack)->n);
}

/**
 * mnty_pop - function that removes top element of the stack
 * @stack: the stack where we remove the top element
 * @line_number: the current line of the monty bytecode file
 * Return: nothing
 */
void mnty_pop(stack_t **stack, unsigned int line_number)
{
	stack_t *tempo;

	if ((*stack) == NULL)
	{
		fprintf(stderr, "L%u: can't pop an empty stack\n", line_number);
		exit(EXIT_FAILURE);
	}
	tempo = *stack;
	*stack = (*stack)->next;

	if (*stack != NULL)
		(*stack)->prev = NULL;

	free(tempo);
}
/**
 * mnty_swap - function that top 2 elements of the stack
 * @stack: the stack to swap elements
 * @line_number: te current line inse the monty bytecode file
 * Return: nothing
 */
void mnty_swap(stack_t **stack, unsigned int line_number)
{
	stack_t *temp;

	if (*stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%u: can't swap, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}

	temp = *stack;
	*stack = (*stack)->next;
	temp->prev = (*stack)->next;
	(*stack)->next = temp;
	(*stack)->prev = NULL;
	temp->next = NULL;
}
