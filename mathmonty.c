#include "monty.h"

/**
 * swap_monty - swaps the top two elements of the stack
 * @stack: double pointer to the stack
 * @line_number: line number of the opcode
 * Return: void
 */
void swap_monty(stack_t **stack, unsigned int line_number)
{
	stack_t *tmp;
	char *errM1 = ": can't swap, stack too short\n";

	if (!(*stack))
		free_stack(stack, errM1);
	if (!(*stack)->next)
		free_stack(stack, errM1);
	tmp = (*stack)->next;
	(*stack)->next = tmp->next;
	(*stack)->prev = tmp;
	tmp->next = (*stack);
	tmp->prev = NULL;
	(*stack) = tmp;
	(void) line_number;
}

/**
 * add_monty - adds the top two elements of the stack
 * @stack: double pointer to the stack
 * @line_number: line number of the opcode
 * Return: void
 */
void add_monty(stack_t **stack, unsigned int line_number)
{
	stack_t *tmp;
	char *errM1 = ": can't add, stack too short\n";

	if (!(*stack))
		free_stack(stack, errM1);
	if (!(*stack)->next)
		free_stack(stack, errM1);
	tmp = (*stack);
	tmp->next->n = (((*stack)->n) + ((*stack)->next->n));
	(*stack) = tmp->next;
	free(tmp);
	(void) line_number;
}

/**
 * sub_monty - subtracts top 2 elements of the stack
 * @stack: double pointer to the stack
 * @line_number: line number of the opcode
 * Return: void
 */
void sub_monty(stack_t **stack, unsigned int line_number)
{
	stack_t *tmp;
	char *errM1 = ": can't sub, stack too short\n";

	if (!(*stack))
		free_stack(stack, errM1);
	if (!(*stack)->next)
		free_stack(stack, errM1);
	tmp = (*stack);
	tmp->next->n -= tmp->n;
	(*stack) = (*stack)->next;
	(*stack)->prev = NULL;
	free(tmp);
	(void) line_number;
}

/**
 * div_monty - divides top 2 elements of the stack
 * @stack: double pointer to the stack
 * @line_number: line number of the opcode
 * Return: void
 */
void div_monty(stack_t **stack, unsigned int line_number)
{
	stack_t *tmp;
	char *errM1 = ": can't div, stack too short\n";
	char *errM2 = ": division by zero\n";

	if (!(*stack))
		free_stack(stack, errM1);
	if (!(*stack)->next)
		free_stack(stack, errM1);
	if ((*stack)->n == 0)
		free_stack(stack, errM2);
	tmp = (*stack);
	tmp->next->n /= tmp->n;
	(*stack) = (*stack)->next;
	(*stack)->prev = NULL;
	free(tmp);
	(void) line_number;
}

/**
 * mul_monty - multiplies top 2 elements of the stack
 * @stack: double pointer to the stack
 * @line_number: line number of the opcode
 * Return: void
 */
void mul_monty(stack_t **stack, unsigned int line_number)
{
	stack_t *tmp;
	char *errM1 = ": can't mul, stack too short\n";

	if (!(*stack))
		free_stack(stack, errM1);
	if (!(*stack)->next)
		free_stack(stack, errM1);
	tmp = (*stack);
	tmp->next->n *= tmp->n;
	(*stack) = (*stack)->next;
	(*stack)->prev = NULL;
	free(tmp);
	(void) line_number;
}
