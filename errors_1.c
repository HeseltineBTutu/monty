#include "monty.h"

/**
 * usage_error - prints usage error message and exits program
 *
 * Return: EXIT_FAILURE
 */
int usage_error(void)
{
	fprintf(stderr, "USAGE: monty file\n");
	exit(EXIT_FAILURE);
}
/**
 * file_open_error - prints an error message and exits if a file cannot be opened
 * @file_name: the name of the file that cannot be opened
 *
 * Return: void
 */
void file_open_error(char *file_name)
{
	fprintf(stderr, "Error: Can't open file %s\n", file_name);
	exit(EXIT_FAILURE);
}
