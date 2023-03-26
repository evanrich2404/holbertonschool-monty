#include "monty.h"

/**
 * op_resolver - resolves the opcode
 * @stack: double pointer to the stack
 * Return: void
 */
void op_resolver(stack_t **stack)
{
	unsigned int i;
	char *errM1 = "!: unknown instruction ";
	instruction_t betty[] = {
		{"push", push_monty},
		{"pall", pall_monty},
		{"pint", pint_monty},
		{"pop", pop_monty},
		{"swap", swap_monty},
		{"add", add_monty},
		{"nop", nop_monty},
		{"sub", sub_monty},
		{"div", div_monty},
		{"mul", mul_monty},
		{"mod", mod_monty},
		{"pchar", pchar_monty},
		{"pstr", pstr_monty},
		{"rotl", rotl_monty},
		{"rotr", rotr_monty},
		{NULL, NULL}
	};

	for (i = 0; betty[i].opcode; i++)
	{
		if (strcmp(betty[i].opcode, global.op_code) == 0)
		{
			betty[i].f(stack, global.op_line);
			return;
		}
	}
	free_stack(stack, errM1);
}
