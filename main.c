#include "monty.h"

command_t *act_com;

/**
 *main - Program Entry Point
 *@argC: Count of arguments
 *@argV: Values fo arguments
 *
 *Return: EXIT_SUCCESS
 */
int main(int argC, char **argV)
{
	FILE *target;
	stack_t *MontyStack = NULL;
	char line[1024];
	int lineNum;
	command_t *myOp;

	if (argC != 2)
	{
		dprintf(STDERR_FILENO, "USAGE: %s file\n", "monty");
		return (EXIT_FAILURE);
	}
	target = fopen(argV[1], "r");
	if (!target)
	{
		dprintf(STDERR_FILENO, "Error: Can't open file %s\n", argV[1]);
		return (EXIT_FAILURE);
	}

	for (lineNum = 1; fgets(line, 1024, target); lineNum++)
	{
		myOp = parse_line(line, lineNum);

		do_op(&MontyStack, myOp);
	}
	fclose(target);
	freeStack(MontyStack);
	free(act_com->opcode);
	free(act_com);
	return (EXIT_SUCCESS);
}
