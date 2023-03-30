#include "monty.h"

/**
 * mod_monty - modifies the top two elements of the stack
 * @stack: double pointer to the stack
 * @line_number: line number of the opcode
 * Return: void
 */
void mod_monty(stack_t **stack, unsigned int line_number)
{
	stack_t *tmp;
	char *errM1 = ": can't mod, stack too short\n";
	char *errM2 = ": division by zero\n";

	if (!(*stack) || (!(*stack)->next))
		free_stack(stack, errM1);
	if ((*stack)->n == 0)
		free_stack(stack, errM2);
	tmp = (*stack);
	tmp->next->n %= tmp->n;
	(*stack) = (*stack)->next;
	(*stack)->prev = NULL;
	free(tmp);
	(void) line_number;
}

/**
 * pchar_monty - print the char at the top of the stack, followed by a new line
 * @stack: double pointer to the stack
 * @line_number: line number of the opcode
 * Return: void
 */
void pchar_monty(stack_t **stack, unsigned int line_number)
{
	char pchar;
	char *errM1 = ": can't pchar, value out of range\n";
	char *errM2 = ": can't pchar, stack empty\n";

	if (!(*stack))
		free_stack(stack, errM2);
	if ((*stack)->n < 0 || (*stack)->n > 127)
		free_stack(stack, errM1);
	pchar = (*stack)->n;
	printf("%c\n", pchar);
	(void) line_number;
}

/**
 * pstr_monty - prints the string starting at the top of the stack
 * @stack: double pointer to the stack
 * @line_number: line number of the opcode
 * Return: void
 */
void pstr_monty(stack_t **stack, unsigned int line_number)
{
	stack_t *tmp;

	tmp = (*stack);
	while (tmp && tmp->n > 0 && tmp->n < 128)
	{
		printf("%c", tmp->n);
		tmp = tmp->next;
	}
	printf("\n");
	(void) line_number;
}

/**
 * rotl_monty - rotates the stack to the top
 * @stack: double pointer to the stack
 * @line_number: line number of the opcode
 * Return: void
 */
void rotl_monty(stack_t **stack, unsigned int line_number)
{
	stack_t *bottom, *top, *tmp;

	if (!(*stack) || !(*stack)->next)
		return;
	bottom = (*stack);
	top = (*stack)->next;
	tmp = (*stack);
	while (tmp->next)
		tmp = tmp->next;
	tmp->next = bottom;
	top->prev = NULL;
	(*stack) = top;
	bottom->prev = tmp;
	bottom->next = NULL;
	(void) line_number;
}

/**
 * rotr_monty - rotates the stack to the bottom
 * @stack: double pointer to the stack
 * @line_number: line number of the opcode
 * Return: void
 */
void rotr_monty(stack_t **stack, unsigned int line_number)
{
	stack_t *bottom, *top, *tmp;

	if (!(*stack) || !(*stack)->next)
		return;
	top = (*stack);
	while (top->next)
		top = top->next;
	bottom = top->prev;
	tmp = (*stack);
	tmp->prev = top;
	(*stack) = top;
	top->next = tmp;
	top->prev = NULL;
	bottom->next = NULL;
	(void) line_number;
}
