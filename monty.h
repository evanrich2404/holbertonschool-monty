#ifndef MONTY_H_
#define MONTY_H_

/*
 * Libraries
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <ctype.h>
#include <fcntl.h>
#include <stdarg.h>

/**
 * struct stack_s - doubly linked list representation of a stack (or queue)
 * @n: integer
 * @prev: points to the previous element of the stack (or queue)
 * @next: points to the next element of the stack (or queue)
 * 
 * Description: doubly linked list node structure
 * for stack, queues, LIFO, FIFO Holberton project
 */
typedef struct stack_s
{
    int n;
    struct stack_s *prev;
    struct stack_s *next;
} stack_t;

/**
 * struct instruction_s - opcode and its function
 * @opcode: the opcode
 * @f: function to handle the opcode
 * 
 * Description: opcode and its function
 */
typedef struct instruction_s
{
    char *opcode;
    void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;

/**
 * struct global_s - global variables
 * @op_code: the opcode
 * @op_arg: the argument
 * @op_line: the line number
 * @op_mode: the mode of the program
 * @file_ref: the file reference
 * @line_ref: the line reference
 * Description: global for stack, queues, LIFO, FIFO Holberton project
 */
typedef struct global_s
{
    char *op_code;
    char *op_arg;
    unsigned int op_line;
    unsigned int op_mode;
    FILE *file_ref;
    char *line_ref;
} global_t;

extern struct global_s global;

/*
 * Functions
 */
void op_resolver(stack_t **stack);
void push_monty(stack_t **stack, unsigned int line_number);
void pall_monty(stack_t **stack, unsigned int line_number);
void pint_monty(stack_t **stack, unsigned int line_number);
void pop_monty(stack_t **stack, unsigned int line_number);
void swap_monty(stack_t **stack, unsigned int line_number);
void add_monty(stack_t **stack, unsigned int line_number);
void nop_monty(stack_t **stack, unsigned int line_number);
void sub_monty(stack_t **stack, unsigned int line_number);
void div_monty(stack_t **stack, unsigned int line_number);
void mul_monty(stack_t **stack, unsigned int line_number);
void mod_monty(stack_t **stack, unsigned int line_number);
void pchar_monty(stack_t **stack, unsigned int line_number);
void pstr_monty(stack_t **stack, unsigned int line_number);
void rotl_monty(stack_t **stack, unsigned int line_number);
void rotr_monty(stack_t **stack, unsigned int line_number);
void stack_monty(stack_t **stack, unsigned int line_number);
void queue_monty(stack_t **stack, unsigned int line_number);
void free_stack(stack_t **stack, char *message);

#endif /* MONTY_H_ */
