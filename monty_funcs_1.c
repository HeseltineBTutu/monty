#include "monty.h"
/**
 * push - push an element onto the stack
 * @stack: pointer to the stack
 * @line_number: current line number in the input file
 *
 * Return: void
 */
void push(stack_t **stack, unsigned int line_number)
{
	char *operand_str = strtok(NULL, " \n");
	int operand;
	stack_t *new_node;


	if (operand_str == NULL)
	{
		fprintf(stderr, "L%d: usage: push integer\n", line_number);
		exit(EXIT_FAILURE);
	}

	operand = atoi(operand_str);

	if (operand == 0 && strcmp(operand_str, "0") != 0)
	{
		fprintf(stderr, "L%d: usage: push integer\n", line_number);
		exit(EXIT_FAILURE);
	}

	new_node = malloc(sizeof(stack_t));
	if (new_node == NULL)
	{
		fprintf(stderr, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}
	new_node->n = operand;
	new_node->prev = NULL;
	new_node->next = *stack;

	if (*stack != NULL)
		(*stack)->prev = new_node;
	*stack = new_node;
}
/**
 * pall - print all elememnts of the stack
 * @stack: pointer to the stack
 * @line_number: current line number in the input file (not used)
 *
 * Return: void
 */
void pall(stack_t **stack)
{
	stack_t *current = *stack;
	
	while (current != NULL)
	{
		printf("%d\n", current->n);
		current = current->next;
	}
}
int parse_instruction(char *line, stack_t **stack, unsigned int line_number)
{
    char *opcode, *arg;
    int status = EXIT_SUCCESS;

    /* Ignore empty lines and comments */
    if (line == NULL || *line == '\0' || *line == '#')
        return status;

    /* Extract opcode and argument (if any) from the line */
    opcode = strtok(line, " \t\n");
    if (opcode == NULL)
	    return (status);
    arg = strtok(line, " \t\n");

    /* Call the appropriate function based on the opcode */
    if (strcmp(opcode, "push") == 0)
    {
	    if (arg == NULL)
	    {
		    fprintf(stderr, "L%u: usage: push integer\n", line_number);
		    return (EXIT_FAILURE);
	    }
	    push(stack, line_number);
    }
    else if (strcmp(opcode, "pall") == 0)
            pall(&(*stack));
        /* add more opcodes as needed */
    else
        {
            fprintf(stderr, "L%u: unknown instruction %s\n", line_number, opcode);
            status = EXIT_FAILURE;
        }
    return status;
}
