#include "monty.h"

/**
 * push_monty - pushes an element to the stack
 * @stack: double pointer to the stack
 * @line_number: line number of the opcode
 * Return: void
 */
void push_monty(stack_t **stack, unsigned int line_number)
{
	stack_t *new_node;
	unsigned int i = 1;
	int n;
	char *errM1 = ": usage: push integer\n";

	if (!(global.op_arg))
		free_stack(stack, errM1);
	if (!((global.op_arg[0] >= '0' && global.op_arg[0] <= '9')
	|| global.op_arg[0] == '-'))
		free_stack(stack, errM1);
	while (global.op_arg[i])
	{
		if (isdigit(global.op_arg[i]) == 0)
			free_stack(stack, errM1);
		i++;
	}
	new_node = malloc(sizeof(stack_t));
	n = atoi(global.op_arg);
	new_node->n = n;
	new_node->prev = NULL;
	new_node->next = *stack;
	if (*stack != NULL)
		(*stack)->prev = new_node;
	*stack = new_node;
	(void) line_number;
}

/**
 * pall_monty - prints all the values on the stack, starting from the top
 * @stack: double pointer to the stack
 * @line_number: line number of the opcode
 * Return: void
 */
void pall_monty(stack_t **stack, unsigned int line_number)
{
	stack_t *tmp = *stack;

	(void) line_number;
	while (tmp)
	{
		printf("%d\n", tmp->n);
		tmp = tmp->next;
	}
}

/**
 * pint_monty - print the value at the top of the stack, followed by a new line
 * @stack: double pointer to the stack
 * @line_number: line number of the opcode
 * Return: void
 */
void pint_monty(stack_t **stack, unsigned int line_number)
{
	char *errM1 = ": can't pint, stack empty\n";

	if (*stack == NULL)
		free_stack(stack, errM1);
	else
	{
		printf("%d\n", (*stack)->n);
	}
	(void) line_number;
}

/**
 * pop_monty - removes the top element of the stack
 * @stack: double pointer to the stack
 * @line_number: line number of the opcode
 * Return: void
 */
void pop_monty(stack_t **stack, unsigned int line_number)
{
	stack_t *tmp;
	char *errM1 = ": can't pop an empty stack\n";

	if (!(*stack))
		free_stack(stack, errM1);
	else
	{
		tmp = (*stack)->next;
		free(*stack);
		*stack = tmp;
	}
	(void) line_number;
}

/**
 * nop_monty - doesn’t do anything
 * @stack: double pointer to the stack
 * @line_number: line number of the opcode
 * Return: void
 */
void nop_monty(stack_t **stack, unsigned int line_number)
{
	(void) stack;
	(void) line_number;
}
