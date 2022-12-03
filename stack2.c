#include "monty.h"
int number;
/**
 * push_monty - push (add) node to list
 * Description: Function that pushes a new node at the beginning of stack_t
 * @top: element at the top of the stack (head)
 * @line_number: constant int value in the structure
 */
void push_monty(stack_t **top, unsigned int line_number)
{
	stack_t *newNode;

	(void) line_number;
	newNode = malloc(sizeof(stack_t));

	if (newNode == NULL)
		malloc_error();

	newNode->n = number;
	newNode->prev = NULL;
	if (*top == NULL)  /* validate if empty stack */
	{
		newNode->next = NULL;
		*top = newNode;
	}
	else /* if is not empty stack */
	{
	newNode->next = *top;
	(*top)->prev = newNode;
	*top = newNode;
	}
}
/**
 * pall_monty - print all
 * Description: Function that prints the elements of a stack
 * @top: element at the top of the stack (head)
 * @line_number: constant int value in the structure
 */
void pall_monty(stack_t **top, unsigned int line_number)
{
	stack_t *tmp = *top;
	(void)line_number;

	while (tmp != NULL)
	{
		printf("%d\n", tmp->n);
		tmp = tmp->next;
	}
}
/**
 * free_monty - free list
 * Description: Function that frees a stack_t
 * @top: head of stack
 */
void free_monty(stack_t *top)
{
	stack_t *temp;

	if (top == NULL)
		return;

	while (top != NULL)
	{
		temp = top;
		top = top->next;
		free(temp);
	}
	free(top);
}
