#ifndef HOLY_GRAIL_H
#define HOLY_GRAIL_H

/* who isn't going to make a reference to this? */

char **holygrail;

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdarg.h>
#include <fcntl.h>
#include <ctype.h>
extern int n;

/**
 * struct stack_s - doubly linked list representation of a stack (or queue)
 * @n: integer
 * @prev: points to the previous element of the stack (or queue)
 * @next: points to the next element of the stack (or queue)
 *
 * Description: doubly linked list node structure
 * for stack, queues, LIFO, FIFO
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
 * for stack, queues, LIFO, FIFO
 */
typedef struct instruction_s
{
        char *opcode;
        void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;

/* error_handler functions */
void error_arguments(void);
void open_error(char **);
void invalidInstruction_error(char *invInstruction, unsigned int line);
void not_int_err(unsigned int line);
void malloc_error(void);

/* error handler 2 */
void pint_error(unsigned int line);
void pop_error(unsigned int line);
void swap_error(unsigned int line);
void add_error(unsigned int line);
void sub_error(unsigned int line);

/* error_handler3 */
void div_error(unsigned int line);
void div_error2(unsigned int line);
void mul_error(unsigned int line);
void mod_error(unsigned int line);

/*error handler4*/
void pchar_error(unsigned int line);
void pchar_error2(unsigned int line);

/* executer functions*/
void open_and_read(char **argv);
int is_number(char *token);
int is_comment(char *token, int line_counter);

/*opcodes */
void (*get_op_code(char *token, unsigned int line)) (stack_t **, unsigned int);

/* prototypes for stack */
void push_monty(stack_t **top, unsigned int line_number);
void pall_monty(stack_t **top, unsigned int line_number);
void free_monty(stack_t *top);
void pint_monty(stack_t **top, unsigned int line_number);
void pop_monty(stack_t **top, unsigned int line_number);

/* stack operations */
void swap_monty(stack_t **top, unsigned int line);
void add_monty(stack_t **top, unsigned int line);
void sub_monty(stack_t **top, unsigned int line_number);
void div_monty(stack_t **top, unsigned int line_number);
void mul_monty(stack_t **top, unsigned int line);

/* more stack */
void nop_monty(stack_t **top, unsigned int line_number);
void mod_monty(stack_t **top, unsigned int line_number);




#endif
