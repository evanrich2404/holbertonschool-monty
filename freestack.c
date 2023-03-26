#include "monty.h"

/**
 * free_stack - frees the stack
 * @stack: double pointer to the stack
 * @message: error message
 * Return: void
 */
void free_stack(stack_t **stack, char *message)
{
	stack_t *tmp;

	if (message)
	{
		if (message[0] == '!')
		{
			message++;
			fprintf(stderr, "L%d%s%s\n", global.op_line,
				message, global.op_code);
		}
		else
			fprintf(stderr, "L%d%s", global.op_line, message);
	}
	if (global.line_ref)
		free(global.line_ref);
	fclose(global.file_ref);
	if (*stack)
	{
		while (*stack)
		{
			tmp = (*stack)->next;
			free(*stack);
			*stack = tmp;
		}
	}
	if (message)
		exit(EXIT_FAILURE);
	else
		return;
}
