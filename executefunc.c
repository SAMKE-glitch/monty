#include "monty.h"
#include <stdio.h>
#include <string.h>

/**
 * read_op_func - matches the opcode with it's function
 * @opcode: the instruction to match
 * Return: returns a pointer
 */
void (*read_op_func(char *opcode))(stack_t**, unsigned int)
{
	instruction_t op_fun[] = {{"push", mnty_push}, {"pall", mnty_pall}, {"pint", mnty_pint}, {NULL, NULL}};

	int i;

	for (i = 0; op_fun[i].opcode; i++)
	{
		if (strcmp(opcode, op_fun[i].opcode) == 0)
			return (op_fun[i].f);
	}
	return (NULL);
}

/**
 * exec_mnty - function to execute monty bytecodes script
 * @fle_fd: file descriptor for monty script
 *
 * Return: exit on sucess or error upon failing
 */
int exec_mnty(FILE *fle_fd)
{
	stack_t *stack = NULL;
	char *line = NULL;
	size_t urefu = 0;
	unsigned int line_number = 0;
	char *opcode = strtok(line, " \t\n");

	if (fle_fd == NULL)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}

	while (fgets(line, urefu, fle_fd) != NULL)
	{
		void (*op_func)(stack_t **, unsigned int) = read_op_func(opcode);
		if (opcode != NULL && opcode[0] != '#')
		{
			line_number++;

			if (op_func == NULL)
			{
				fprintf(stderr, "L%u: unknown instructions %s\n", line_number, opcode);
				free(line);
				fclose(fle_fd);
				exit(EXIT_FAILURE);
			}
			op_func(&stack, line_number);
		}
	}
	free(line);
	fclose(fle_fd);

	return (0);


}
