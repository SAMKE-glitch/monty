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
	instruction_t op_fun[] = {{"push", mnty_push}, {"pall", mnty_pall},
		{"pint", mnty_pint}, {"pop", mnty_pop}, {"swap", mnty_swap},
		{"add", mnty_add}, {"nop", mnty_nop}, {"sub", mnty_sub},
		{"div", mnty_div}, {"mul", mnty_mul}, {"mod", mnty_mod},
		{"pchar", mnty_pchar}, {"pstr", mnty_pstr},
		{"rotl", mnty_rotl}, {"rotr", mnty_rotr},
		{"stack", mnty_stack}, {"queue", mnty_queue},
		{NULL, NULL}};

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
	char line[1024];
	unsigned int line_number = 0;
	char *opcode;
	void (*op_func)(stack_t **, unsigned int);

	if (fle_fd == NULL)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}

	while (fgets(line, sizeof(line), fle_fd))
	{
		opcode = strtok(line, " \t\n");

		if (opcode != NULL && opcode[0] != '#')
		{
			line_number++;
			op_func = read_op_func(opcode);

			if (op_func == NULL)
			{
				fprintf(stderr, "L%u: unknown instructions %s\n", line_number, opcode);
				fclose(fle_fd);
				exit(EXIT_FAILURE);
			}
			op_func(&stack, line_number);
		}
	}
	fclose(fle_fd);

	return (0);


}
