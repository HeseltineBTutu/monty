#include <stdio.h>
#include "monty.h"
#include <sys/types.h>
ssize_t getline(char **lineptr, size_t *n, FILE *stream);
/**
 * main - Entry point for Monty interpreter
 * @argc: Number of arguments passed to the program
 * @argv: Array of arguments passed to teh program
 *
 * Return: EXIT_SUCCESS on success, EXIT_FAILURE on failure
 */
int main(int argc, char **argv)
{
	char *file_name;
	FILE *file_stream;
	unsigned int line_number = 0;
	stack_t *stack = NULL;
	char *line = NULL;
	size_t len = 0;
	ssize_t nread;

	if (argc != 2)
		return (usage_error());

	file_name = argv[1];
	file_stream = fopen(file_name, "r");

	if (file_stream == NULL)
		file_open_error(file_name);
	while ((nread = getline(&line, &len, file_stream)) != -1)
	{
		line_number++;
		if (parse_instruction(line, &stack, line_number) == EXIT_FAILURE)
		{
			fclose(file_stream);
			free_stack(stack);
			free(line);
			exit(EXIT_FAILURE);
		}
	}
	fclose(file_stream);
	free_stack(stack);
	free(line);
	return (EXIT_SUCCESS);
}
