#include "monty.h"

/**
 * main - this is the main entry point
 * @argc: the arguement count
 * @argv: the argument vector
 *
 * Return: 0 on success
 */
int main(int argc, char *argv[])
{
	FILE *file_fd;

	if (argc != 2)
	{
		printf("USAGE: monty file\n");
		return (EXIT_FAILURE);
	}
	file_fd = fopen(argv[1], "r");
	if (file_fd == NULL)
	{
		printf("Error: Can't open file %s\n", argv[1]);
		return (EXIT_FAILURE);
	}
	exec_mnty(file_fd);
	return (0);
}
