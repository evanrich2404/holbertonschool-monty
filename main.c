#include "monty.h"

struct global_s global;

/**
 * main - main function
 * @argc: number of arguments
 * @argv: array of arguments
 * Return: 0, unless failure then 1
 */
int main(int argc, char *argv[])
{
	stack_t *stack_monty = NULL;
	FILE *inbound_file = NULL;
	size_t n = 0;
	char *line_buffer = NULL;
	const char delims[] = " \t\n";

	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}
	inbound_file = fopen(argv[1], "r");
	if (!(inbound_file))
	{
		fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
		exit(EXIT_FAILURE);
	}
	global.file_ref = inbound_file;
	global.op_line = 0;
	while (getline(&line_buffer, &n, inbound_file) != -1)
	{
		global.op_line++;
		global.op_code = strtok(line_buffer, delims);
		global.op_arg = strtok(NULL, delims);
		if (!global.op_code || global.op_code[0] == '#')
			continue;
		global.op_arg = strtok(NULL, delims);
		op_resolver(&stack_monty);
	}
	free_stack(&stack_monty, NULL);
	return (0);
}
