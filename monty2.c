#include "monty2.h"
/**
 * pint - prints the value at the top of the stack, followed by a new line.
 * @stack: pointer to the top of the stack
 * @line_number: line number
 * Return: void
 */
void pint(stack_t **stack, unsigned int line_number)
{
    if (*stack == NULL)
    {
        printf("L%i: can't pint, stack empty", line_number);
        exit(EXIT_FAILURE);
    }
    printf("%i  ", (*stack)->n);
}
/**
 * pop - removes the top element of the stack.
 * @stack: pointer to the top of the stack
 * @line_number: line number
 * Return: void
 */
void pop(stack_t **stack, unsigned int line_number)
{
    stack_t *temp;
    if (*stack == NULL)
    {
        printf("L%i: can't pop an empty stack", line_number);
        exit(EXIT_FAILURE);
    }
    temp = *stack;
    *stack = (*stack)->next;
    free(temp);
}
/**
 * swap - swaps the top two elements of the stack.
 * @stack: pointer to the top of the stack
 * @line_number: line number
 * Return: void
 */
void swap(stack_t **stack, unsigned int line_number)
{
    stack_t *temp;
    if (*stack == NULL || (*stack)->next == NULL)
    {
        printf("L%i: can't swap, stack too short", line_number);
        exit(EXIT_FAILURE);
    }
    temp = *stack;
    *stack = (*stack)->next;
    (*stack)->prev = NULL;
    temp->next = (*stack)->next;
    (*stack)->next = temp;
    temp->prev = *stack;
}
/**
 * add - adds the top two elements of the stack.
 * @stack: pointer to the top of the stack
 * @line_number: line number
 * Return: void
 */
void add(stack_t **stack, unsigned int line_number)
{
    stack_t *temp;
    if (*stack == NULL || (*stack)->next == NULL)
    {
        printf("L%i: can't add, stack too short", line_number);
        exit(EXIT_FAILURE);
    }
    temp = *stack;
    *stack = (*stack)->next;
    (*stack)->n += temp->n;
    (*stack)->prev = NULL;
    free(temp);
}
/**
 * nop - doesn’t do anything.
 * @stack: pointer to the top of the stack
 * @line_number: line number
 * Return: void
 */
void nop(stack_t **stack, unsigned int line_number)
{
    (void)stack;
    (void)line_number;
}